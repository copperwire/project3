#ifndef EULER_H
#include <solarsystem.h>
#define EULER_H


class Euler
{
    public:
        double time_step;
        Euler(double dt);

        void integrateOneStep(class SolarSystem &system);
};



#endif // EULER_H
