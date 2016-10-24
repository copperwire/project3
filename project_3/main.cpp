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
    CelestialBody &holy_terra = incandescence.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6);

    /*
     *
     CelestialBody &solaire = incandescence.createCelestialBody(vec3(3.555487376887400E-03,  3.443726955832962E-03, -1.595926442259376E-04),
                                                               vec3( -2.039381680455059E-06*365,  6.825851787592621E-06*365,  4.190413544166179E-08*365),
                                                               1);

    CelestialBody &holy_terra = incandescence.createCelestialBody(vec3(8.923201619757489E-01,  4.523540753710130E-01, -1.781780901718696E-04),
                                                                  vec3(-8.031919308950355E-03 * 365,  1.529775700370547E-02 * 365, -5.667177098913429E-07* 365),
                                                                  3e-6);
    CelestialBody &king_juno = incandescence.createCelestialBody(vec3( -5.425729474512933E+00, -4.893805883481592E-01,  1.233739639493046E-01),
                                                                 vec3( 5.899930831654800E-04 *365, -7.158477914441830E-03*365,  1.655140736264202E-05*365),
                                                                 9.54e-4);

     *
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
            incandescence.writeToFile("positions_earth_sun_euler.xyz", timestep, N);
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
            incandescence.writeToFile("positions_earth_sun_verlet.xyz", timestep, N);
        }

        stop = clock();

        time_write << (double) (stop - start)/CLOCKS_PER_SEC << endl;
    }
    //cout << "I just created my first solar system that has " << incandescence.bodies().size() << " objects." << endl;

    return 0;
}
