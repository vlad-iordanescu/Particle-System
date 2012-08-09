//#include "particle.h"
#include"liniar.h"
class point {
    public:
    point();
    ~point();
    int setParticle(int number, float x, float y, float red, float green, float blue, float lifetime, float speed, float size);
    int setPointMultipleUpdate();
    int setPointOneUpdate(int m_length);
    int setPointDoubleUpdate(int m_length);
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel();
    int setDecel();
    particles *m_particles;
    int m_count;
    private:
    int m_start;
    float m_xstart;
    float m_ystart;
};


