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
        vec3 prev_position = body.position;
        body.position = 2*body.position - prev_position+ stepstep*(body.force/body.mass);
        body.velocity = (body.position - prev_position)/(2*time_step);
	} 
}
