#ifndef VERLET_H
#include<solarsystem.h>
#define VERLET_H

class Verlet
{
public:
    double time_step;
    Verlet(double time_step);

    void integrateOneStep(class SolarSystem &system);
};

#endif // VERLET_H
