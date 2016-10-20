#include euler.h

Euler::Euler (double dt):
//Calculate the time step, from number of iterations and total time
	time_step(int N, double total_time){
		step = N/total_time;
	}

void Euler::integrateOneStep(SolarSystem &systems)
{
	system-calculateForcesAndEnergy();

	for(CelestialBody &body : system.bodies()){
		body.position += body.velocity * time_step
		body.velocity += (body.force/body.mass)*time_step 
	} 
}





