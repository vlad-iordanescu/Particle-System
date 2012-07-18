#include "particle.h"
class point {
    public:
    point(int number, float x, float y, char red, char green, char blue, float lifetime, float speed, float size);
    ~point();
    int setParticle();
    int setPointMultipleUpdate();
    int setPointOneUpdate(int m_length);
    int setPointDoubleUpdate(int m_length);
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel(float m_aux);
    int setDecel(float m_aux);
    particles *m_particles;
    private:
    int m_count;
    float m_xstart;
    float m_ystart;
};


