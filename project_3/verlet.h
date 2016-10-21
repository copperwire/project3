#ifndef VERLET_H
#include <solarsystem.h>
#include <vec3.h>
#define VERLET_H

class Verlet
{
public:
    double time_step;
    Verlet(double time_step);
    vec3 prev_position;
    vec3 prevprev_position;

    void integrateOneStep(class SolarSystem &system);
};

#endif // VERLET_H
