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
        //vec3 prev_position = body.position; // body.position = prev_position i neste steg.
        //body.position = 2*prev_position - prevprev_position + stepstep*(body.force/body.mass);
        //vec3 prevprev_position = prev_position;
        //vec3 prev_position = body.position;
        //body.velocity = (body.position - prevprev_position)/(2*time_step);
        body.position += time_step*body.velocity + stepstep/2*(body.force/body.mass);
        body.velocity += time_step/2*((body.force/body.mass) + prev_acc);
        vec3 prev_acc = body.force/body.mass;
	} 
}
