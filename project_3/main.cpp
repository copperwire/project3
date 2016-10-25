#include <iostream>
#include <solarsystem.h>
#include <verlet.h>
#include <euler.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int years = atoi(argv[3]);
    //units [m] = solar masses, [r] = au, [v] = au/yr
    SolarSystem incandescence;

    CelestialBody &solaire = incandescence.createCelestialBody(vec3(0, 0, 0), vec3(0,0,0), 1);
    //CelestialBody &holy_terra = incandescence.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6);
    //CelestialBody &Jupiter = incandescence.createCelestialBody(vec3(0, 5.453, 0), vec3(2.75, 0, 0), 9.54e-4);
    //CelestialBody &sun = incandescence.createCelestialBody( vec3(3.575449E-3, 3.375340E-3, -1.600004E-4), vec3(-1.952401E-6, 6.851124E-6, 3.957326E-8)*365 , 1.0); //placing sun in origo
    CelestialBody &mercury = incandescence.createCelestialBody( vec3(0.3075, 0,0), vec3(0, 12.44, 0), 1.652E-7);

    /*

    CelestialBody &venus = incandescence.createCelestialBody( vec3(1.026660E-1, -7.170452E-1, -1.575634E-2), vec3(1.990043E-2, 2.691789E-3, -1.111638E-3)*365, 2.447E-7);
    CelestialBody &earth = incandescence.createCelestialBody( vec3(9.590546E-1, 2.934845E-1, -1.776190E-4), vec3(-5.286248E-3, 1.640189E-2, -7.691198E-8)*365, 3.00245940E-6); //creating earth
    CelestialBody &mars = incandescence.createCelestialBody( vec3(1.119656, -8.138412E-1, -4.467628E-2), vec3(8.796737E-3, 1.249663E-2, 4.583204E-5)*365, 3.213E-7);
    CelestialBody &jupiter = incandescence.createCelestialBody(vec3(5.431136, -4.177504E-1, 1.231972E-1), vec3(4.910085E-4, -7.167928E-3, 1.876323E-5)*365 , 9.54265748E-4); //creating jupiter
    CelestialBody &saturn = incandescence.createCelestialBody(
                vec3(-2.241397273177810E+00, -9.781170368384792E+00,  2.592732241876119E-01),
                vec3(5.132065657248627E-03, -1.263605497967198E-03, -1.822817061809818E-04)*365,
                2.858e-4);

    CelestialBody &neptune = incandescence.createCelestialBody(
                vec3(2.826602395068371E+01, -9.907390056949746E+00, -4.473952940873621E-01),
                vec3(1.017460711533741E-03,  2.981080366897627E-03, -8.483799215588196E-05)*365,
                5.15e-5);

    CelestialBody &uranus = incandescence.createCelestialBody( vec3(1.845561975903468E+01,  7.578703329407012E+00, -2.109487294279188E-01),
                                                               vec3(-1.522808404852966E-03,  3.454944174333453E-03,  3.256246842426625E-05)*365,
                                                               4.365e-5);
    */
    vector<CelestialBody> &bodies_euler = incandescence.bodies();

    for(int i = 0; i<bodies_euler.size(); i++) {
        CelestialBody &body = bodies_euler[i]; // Reference to this body
        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
    }
    double dt = years/(double) N ;
    double start, stop;

    if( atoi(argv[2]) == 0){
        cout << "Euler" << endl;
        Euler integrator_euler(dt);
        string time_file = "euler_time";
        ofstream time_write (time_file.c_str());
        time_write << "#seconds/clocks_per_sec" <<endl;
        start = clock();
        for(int timestep=0; timestep<N; timestep++) {
            integrator_euler.integrateOneStep(incandescence);
            incandescence.writeToFile("positions_sun_mercury_euler.xyz", timestep, N);
        }
        stop = clock();
        time_write << (double) (stop - start)/CLOCKS_PER_SEC << endl;
    }
    else if (atoi(argv[2]) == 1){
        cout << "verlet" << endl;
        string time_file = "verlet_time";
        ofstream time_write (time_file.c_str());
        time_write << "#seconds/clocks_per_sec" <<endl;
        Verlet integrator_verlet(dt);

        start = clock();
        for(int timestep=0; timestep<N; timestep++) {
            integrator_verlet.integrateOneStep(incandescence);
            incandescence.writeToFile("positions_sun_mercury_verlet_non_rel.xyz", timestep, N);
        }

        stop = clock();

        time_write << (double) (stop - start)/CLOCKS_PER_SEC << endl;
    }
    //cout << "I just created my first solar system that has " << incandescence.bodies().size() << " objects." << endl;

    return 0;
}
