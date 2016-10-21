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
        body.position = 2*prev_position - prevprev_position + stepstep*(body.force/body.mass);
        body.velocity = (body.position - prevprev_position)/(2*time_step);
        vec3 prevprev_position = prev_position;
        vec3 prev_position = body.position;
	} 
}
