#include"particle.h"
#include <time.h>

class global {
    public:
    global();
    ~global();
    int setParticle(int number, float x1, float y1, float x2, float y2, float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2);
    int setUpdateRandomMov();
    int setUpdateRandomBlink();
    int setUpdateRain();
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel();
    int setDecel();
    int setDelay();
    int setDuration();
    particles *m_particles_r;
    int m_count;
    private:
    time_t start,end;
    float bf_time, af_time;
    float m_xstart, m_ystart;
    float m_xfin, m_yfin;
    float m_constlifetime;
    int m_time;
};
