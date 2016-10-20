#include <iostream>
#include <solarsystem.h>
#include <verlet.h>
#include <euler.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    //units [m] = solar masses, [r] = au, [v] = au/yr
    SolarSystem incandescence;

    CelestialBody &solaire = incandescence.createCelestialBody(vec3(0, 0, 0), vec3(0,0,0), 1);
    CelestialBody &holy_terra = incandescence.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6);

    vector<CelestialBody> &bodies = incandescence.bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
    }

    double dt = 1/(double) N ;
    Euler integrator(dt);
    for(int timestep=0; timestep<N; timestep++) {
            integrator.integrateOneStep(incandescence);
            incandescence.writeToFile("positions.xyz");
    }

    cout << "I just created my first solar system that has " << incandescence.bodies().size() << " objects." << endl;
    return 0;
}
