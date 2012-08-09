#include"particle.h"

class global {
    public:
    global();
    ~global();
    int setParticle(int number, float x1, float y1, float x2, float y2, float red, float green, float blue, float lifetime, float speed, float size);
    int setUpdateRandomMov();
    int setUpdateRandomBlink();
    int setUpdateRain();
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel();
    int setDecel();
    particles *m_particles_r;
    int m_count;
    private:
    float m_xstart, m_ystart;
    float m_xfin, m_yfin;
    float m_constlifetime;
    int m_time;
};
