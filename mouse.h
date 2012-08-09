#include"point.h"



class mouse {
    public:
    mouse();
    ~mouse();
    int setParticle(int number, float length, float red, float green, float blue, float lifetime, float speed, float size);
    int setMouseParticleUpdate(float m_x, float m_y);
    int setAccel();
    int setDecel();
    particles *m_particles_m;
    int m_count;
    
    private:
    int m_length;
    float m_xmouse, m_ymouse;
    
};

