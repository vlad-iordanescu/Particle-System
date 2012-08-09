//#include "particle.h"
#include"global.h"
class liniar {
    public:
    liniar();
    ~liniar();
    int setParticles(int number, float (*coord)[2], float red, float green, float blue, float lifetime, float speed, float size);
    int setLiniarUpdate();
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel();
    int setDecel();
    particles *m_particles_l;
    int m_count;
    float (*m_coordonates)[2];    
    private:
    float (*m_nextcoord)[2];
    int *m_poz;
    
    
};
