#include <verlet.h>
#include <solarsystem.h>

Verlet::Verlet (double dt):
    time_step(dt){
    }

void Verlet::integrateOneStep(SolarSystem &system)
{
    system.calculateForcesAndEnergy();
    double stepstep = time_step*time_step;

    for(CelestialBody &body : system.bodies()){
        vec3 prevAccel = body.force/body.mass;
        body.position += time_step*body.velocity + stepstep/2 * prevAccel;

        system.calculateForcesAndEnergy();

        body.velocity += time_step/2. * (body.force/body.mass + prevAccel);
    }
}
