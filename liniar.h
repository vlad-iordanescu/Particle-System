//#include "particle.h"
#include"global.h"
class liniar {
    public:
    liniar(int number, float (*coord)[2], char red, char green, char blue, float lifetime, float speed, float size);
    ~liniar();
    int setParticles();
    int setLiniarUpdate();
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel(float m_aux);
    int setDecel(float m_aux);
    particles *m_particles;
    int m_count;
    private:
    float (*m_coordonates)[2];
    float (*m_nextcoord)[2];
};
