#include"point.h"



class mouse {
    public:
    mouse();
    ~mouse();
    int setParticle(int number, float length, float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2);
    int setMouseParticleUpdate(float m_x, float m_y);
    int setAccel();
    int setDecel();
    particles *m_particles_m;
    int m_count;
    int setDelay();
    int setRandomColor();
    int setDuration();
    private:
    time_t start,end;
    float bf_time, af_time;
    int m_length;
    float m_xmouse, m_ymouse;
    
};

