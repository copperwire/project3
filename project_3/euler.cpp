#include <euler.h>
#include <solarsystem.h>

Euler::Euler (double dt):
    time_step(dt){
	}

void Euler::integrateOneStep(SolarSystem &system)
{
    system.calculateForcesAndEnergy();

    for(CelestialBody &body : system.bodies()){
        body.position += body.velocity * time_step;
        body.velocity += (body.force/body.mass)*time_step;
	} 
}

