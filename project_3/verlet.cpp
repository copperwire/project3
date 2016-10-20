#include verlet.h

Verlet::Verlet (double dt):
//Calculate the time step, from number of iterations and total time
	time_step(int N, double total_time){
		step = N/total_time;
		stepstep = step*step
	}

void Verlet::integrateOneStep(SolarSystem &systems)
{

	systemcalculateForcesAndEnergy();

	for(CelestialBody &body : system.bodies()){
		body.position_new = 2*body.velocity -body.velocity_prev + stepstep*(body.force/body.mass)
		body.velocity = (body.position_new - body.position_prev)/(2*step)
	} 
}