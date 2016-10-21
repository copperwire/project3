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
    Euler integrator_euler(dt);
    for(int timestep=0; timestep<N; timestep++) {
            integrator_euler.integrateOneStep(incandescence);
            incandescence.writeToFile("positions_earth_sun_euler.xyz", timestep, N);
    }

    //cout << "I just created my first solar system that has " << incandescence.bodies().size() << " objects." << endl;

    Verlet integrator_verlet(dt);
    for(int timestep=0; timestep<N; timestep++) {
            integrator_verlet.integrateOneStep(incandescence);
            incandescence.writeToFile("positions_earth_sun_verlet.xyz", timestep, N);
    }

    return 0;
}
