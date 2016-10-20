#ifndef CELESTIALBODY_H
#include "vec3.h"
#define CELESTIALBODY_H


class CelestialBody
{
public:
    vec3 position;
    vec3 velocity;
    vec3 force;
    double mass;

    CelestialBody(vec3 vel, vec3 pos, double mass);
    CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_);

    void resetForce();
};

#endif // CELESTIALBODY_H
