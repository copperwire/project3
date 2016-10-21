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
        vec3 record_pos = body.position;
        body.position = 2*body.position - body.prev_position + stepstep*(body.force/ body.mass);

        body.velocity = (body.position - body.prev_position)/(2*time_step);
        body.prev_position = record_pos;
    }
}
