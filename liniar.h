#include "particle.h"

class liniar {
    public:
    liniar(int number, float (*coord)[2], char red, char green, char blue, float lifetime, float speed, float size);
    ~liniar();
    int setParticles();
    int setLiniarUpdate();
    particles *m_particles;
    private:
    int m_count;
    float (*m_coordonates)[2];
    float (*m_nextcoord)[2];
};
