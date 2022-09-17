#include<swarm.h>

namespace create3
{
    swarm::swarm()
    {
       m_particles = new particle[Nparticles];

    }
    swarm::~swarm()
    {
        delete [] m_particles;
    }

    void swarm::update(double sped1)
    {
        for(int i = 0; i <Nparticles; i++)
   {
        m_particles[i].update(sped1);
        
   }
    }
}