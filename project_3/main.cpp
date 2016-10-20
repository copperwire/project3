#include <iostream>
#include <solarsystem.h>
#include <verlet.h>
#include <euler.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);

    //units [m] = solar masses, [r] = au, [v] = au/day
    SolarSystem incandescence;

    CelestialBody &solaire = incandescence.createCelestialBody(vec3(0, 0, 0), vec3(0,0,0), 1);
    CelestialBody &holy_terra = incandescence.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6);
    return 0;
}
