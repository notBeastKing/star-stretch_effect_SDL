#include"particle.h"

#include<stdlib.h> 

namespace create2
{   
    particle::particle() {
        m_x = ((2.0 * rand())/RAND_MAX) - 1;
        m_y = ((2.0 * rand())/RAND_MAX) - 1;

        
    }


    void particle::update( double speed1)
    {
        double speed = 0.0001;
        m_x +=speed;
        m_y +=speed1;

    }

}