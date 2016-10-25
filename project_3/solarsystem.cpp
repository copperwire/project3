#include "solarsystem.h"
#include <iostream>
#include <cmath>
using namespace std;

SolarSystem::SolarSystem() :
    m_kineticEnergy(0),
    m_potentialEnergy(0)
{
}

CelestialBody& SolarSystem::createCelestialBody(vec3 position, vec3 velocity, double mass) {
    m_bodies.push_back( CelestialBody(position, velocity, mass) );
    return m_bodies.back(); // Return reference to the newest added celstial body
}

void SolarSystem::calculateForcesAndEnergy()
{
    double prev_kin = m_kineticEnergy;
    double prev_pot = m_potentialEnergy;

    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    double G = 39.42 ; // AU^3 / (M_s * year ^2) = N m^2 / kg^2
    double c = 63198 ; //AU/year
    vec3 prev_ang = m_angularMomentum;
    m_angularMomentum.zeros();

    for(CelestialBody &body : m_bodies) {
        // Reset forces on all bodies
        body.force.zeros();
    }

    for(int i=0; i<numberOfBodies(); i++) {

        CelestialBody &body1 = m_bodies[i];
        for(int j=i+1; j<numberOfBodies(); j++) {
            //need better solution to avoid calculating forces twice for each body
            CelestialBody &body2 = m_bodies[j];
            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length();

            vec3 force_val = G* body1.mass*body2.mass*deltaRVector/(dr*dr*dr) ;  //* (1 +
                                                                                 //3*(body2.position.cross(body2.velocity).lengthSquared()/(body2.position.lengthSquared() * c*c) ));
            body2.force += force_val;
            body1.force -= force_val;

            m_potentialEnergy += G* body1.mass*body2.mass/(dr);
        }
        m_angularMomentum += body1.position.cross(body1.mass*body1.velocity);
        m_kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared();
    }

   double d_K = fabs(prev_kin - m_kineticEnergy);
   double d_P = fabs(prev_pot - m_potentialEnergy);
   double d_L = fabs((prev_ang - m_angularMomentum).length());

   if( d_K > 0.001*prev_kin){
       cout << "Warning: kinetic energy may be unstable " << endl;
   }
   else if( d_P > 0.001*prev_pot){
       cout << "Warning: Potential energy may be unstable " << endl;
   }
   else if( d_L > 0.001*prev_ang.length()){
       cout << "Warning: Spin may be unstable " << endl;
   }
}

int SolarSystem::numberOfBodies() const
{
    return m_bodies.size();
}

double SolarSystem::totalEnergy() const
{
    return m_kineticEnergy + m_potentialEnergy;
}

double SolarSystem::potentialEnergy() const
{
    return m_potentialEnergy;
}

double SolarSystem::kineticEnergy() const
{
    return m_kineticEnergy;
}

void SolarSystem::writeToFile(string filename, double timestep, int N)
{

    if(!m_file.good()) {
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()) {
            cout << "Error opening file " << filename << ". Aborting!" << endl;
            terminate();
        }
    }

    //m_file << numberOfBodies() << endl;
    //m_file << "#Comment line that needs to be here. Balle." << endl;
    for(CelestialBody &body : m_bodies) {
        m_file << body.position.x() << " " << body.position.y() << " " << body.position.z() << "\n";
    }
    if (timestep == N-1){
        m_file.close();
    }
}

vec3 SolarSystem::angularMomentum() const
{
    return m_angularMomentum;
}

std::vector<CelestialBody> &SolarSystem::bodies()
{
    return m_bodies;
}
