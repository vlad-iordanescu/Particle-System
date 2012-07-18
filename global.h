#include "particle.h"

class global {
    public:
    global(int number, int x1, int y1, int x2, int y2, char red, char green, char blue, float lifetime, float speed, float size);
    ~global();
    int setParticle();
    int setUpdateRandomMov();
    int setUpdateRandomBlink();
    int setUpdateRain();
    particles *m_particles;
    private:
    int m_count;
    int m_xstart, m_ystart;
    int m_xfin, m_yfin;
    float m_constlifetime;
};
