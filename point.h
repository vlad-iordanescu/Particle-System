
#include"liniar.h"
#include <time.h>


class point {
    public:
    point();
    ~point();
    int setParticle(int number, float x, float y, float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2);
    int setPointMultipleUpdate();
    int setPointOneUpdate(int m_length);
    int setPointDoubleUpdate(int m_length);
    int setRandomColor();
    int setTransitionColor(char red, char green, char blue);
    int setAccel();
    int setDecel();
    int setDelay();
    int setDuration();
    particles *m_particles;
    int m_count;
    private:

    time_t start,end;
    float bf_time, af_time;
    int m_start;
    float m_xstart;
    float m_ystart;
};


