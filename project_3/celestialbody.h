#ifndef CELESTIALBODY_H
#include "vec3.h"
#define CELESTIALBODY_H


class CelestialBody
{
public:
    vec3 position;
    vec3 velocity;
    vec3 force;
    vec3 prev_position;
    double mass;

    CelestialBody(vec3 pos, vec3 vel, double mass);
    CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_);

    void resetForce();
};

#endif // CELESTIALBODY_H
