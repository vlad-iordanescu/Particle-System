//#include "particle.h"

class mouse {
    public:
    mouse(int number, float length, char red, char green, char blue, float lifetime, float speed, float size);
    ~mouse();
    int setParticle();
    int setMouseParticleUpdate();
    particles *m_particles;
    private:
    void setmouseMovement(int x, int y);
    int m_xmouse, m_ymouse;
    int m_count;
    int m_length;
    
};
