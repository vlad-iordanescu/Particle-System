#include "global.h"
#include <stdlib.h>


global::global() { }

global::~global() { }

int global::setParticle(int number, float x1, float y1, float x2, float y2, float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2) {
    srand (time(NULL));
    m_particles_r = new particles[number];
    m_count = number;
    m_xstart = x1;
    m_ystart = y1;
    m_xfin = x2;
    m_yfin = y2;
    m_time = 0;
    m_constlifetime = lifetime;
    for(int i = 0; i < m_count; i++) {
        m_particles_r[i].m_red = red;
        m_particles_r[i].m_green = green;
        m_particles_r[i].m_blue = blue;
        m_particles_r[i].m_lifetime = lifetime;
        m_particles_r[i].m_size = size;
        m_particles_r[i].m_speed = speed;
        m_particles_r[i].m_xangle = 0;
        m_particles_r[i].m_yangle = 0;
    }
    for(int i = 0; i < m_count; i++) {
        m_particles_r[i].m_xpos = (rand() % (int)(m_xfin - m_xstart)) + (int)m_xstart;
        m_particles_r[i].m_ypos = (rand() % (int)(m_yfin - m_ystart)) + (int)m_ystart;
    }
    bf_time = time1;
    af_time = time2;
    time (&start);
    return 0;
}

int global::setUpdateRandomMov() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        if (m_particles_r[i].m_lifetime == 0 || m_particles_r[i].m_xpos < m_xstart || m_particles_r[i].m_xpos > m_xfin || m_particles_r[i].m_ypos < m_ystart || m_particles_r[i].m_ypos > m_yfin) {
            m_particles_r[i].m_xpos = (rand() % (int)(m_xfin - m_xstart)) + (int)m_xstart;
            rand();
            m_particles_r[i].m_ypos = (rand() % (int)(m_yfin - m_ystart)) + (int)m_ystart;
            m_particles_r[i].m_lifetime = m_constlifetime;
        }
        else {
            m_particles_r[i].m_xangle = ((rand() % 1000) - 500) / 10;
            rand();
            m_particles_r[i].m_yangle = ((rand() % 1000) - 500) / 10;
            rand();
            m_particles_r[i].m_xpos += m_particles_r[i].m_xangle * m_particles_r[i].m_speed;
            m_particles_r[i].m_ypos += m_particles_r[i].m_yangle * m_particles_r[i].m_speed;
            m_particles_r[i].m_lifetime--;
        }
    }
    return 0;
}

int global::setUpdateRandomBlink() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        m_particles_r[i].m_xpos = (rand() % (int)(m_xfin - m_xstart)) + (int)m_xstart;
        rand();
        m_particles_r[i].m_ypos = (rand() % (int)(m_yfin - m_ystart)) + (int)m_ystart;
    }
    return 0;
}

int global::setUpdateRain() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        if (m_particles_r[i].m_lifetime == 0 || m_particles_r[i].m_ypos < m_ystart) {
            m_particles_r[i].m_xpos = (rand() % (int)(m_xfin - m_xstart)) + (int)m_xstart;
            m_particles_r[i].m_ypos = (rand() % (int)(m_yfin - m_ystart)) + (int)m_ystart;
            m_particles_r[i].m_lifetime = m_constlifetime;
        }
        else {
            m_particles_r[i].m_yangle = (rand() % 1000) / 100 + 0.1;
            rand();
            m_particles_r[i].m_ypos -= m_particles_r[i].m_yangle * m_particles_r[i].m_speed;
            m_particles_r[i].m_lifetime--;
        }
    }
    return 0;
}

int global::setRandomColor() {
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (rand() % 2 == 1 && m_particles_r[i].m_red < 255)
            m_particles_r[i].m_red += 1;
        else if (rand() % 2 == 1 && m_particles_r[i].m_red == 255)
            m_particles_r[i].m_red -= 1;
        else if (rand() % 2 == 0 && m_particles_r[i].m_red > 0)
            m_particles_r[i].m_red -= 1;
        else
            m_particles_r[i].m_red += 1;
        if (rand() % 2 == 1 && m_particles_r[i].m_green < 255)
            m_particles_r[i].m_green += 1;
        else if (rand() % 2 == 1 && m_particles_r[i].m_green == 255)
            m_particles_r[i].m_green -= 1;
        else if (rand() % 2 == 0 && m_particles_r[i].m_green > 0)
            m_particles_r[i].m_green -= 1;
        else
            m_particles_r[i].m_green += 1;
        if (rand() % 2 == 1 && m_particles_r[i].m_blue < 255)
            m_particles_r[i].m_blue += 1;
        else if (rand() % 2 == 1 && m_particles_r[i].m_blue == 255)
            m_particles_r[i].m_blue -= 1;
        else if (rand() % 2 == 0 && m_particles_r[i].m_blue > 0)
            m_particles_r[i].m_blue -= 1;
        else
            m_particles_r[i].m_blue += 1;
    }
    return 0;
}

int global::setTransitionColor(char red, char green, char blue) {
    for (int i = 0; i < m_count; i++) {
    if (m_particles_r[i].m_red < red)
        m_particles_r[i].m_red += 1;
    else if (m_particles_r[i].m_red > red)
        m_particles_r[i].m_red -= 1;
    if (m_particles_r[i].m_green < green)
        m_particles_r[i].m_green += 1;
    else if (m_particles_r[i].m_green > green)
        m_particles_r[i].m_green -= 1;
    if (m_particles_r[i].m_blue < blue)
        m_particles_r[i].m_blue += 1;
    else if (m_particles_r[i].m_blue > blue)
        m_particles_r[i].m_blue -= 1;
    if (m_particles_r[i].m_red == red && m_particles_r[i].m_green == green && m_particles_r[i].m_blue == blue)
        return 1;
    }
    return 0;
}

int global::setAccel() {
    for (int i = 0; i < m_count; i++) {
        m_particles_r[i].m_speed += 0.00001;
    }
    return 0;
}

int global::setDecel() {
    for (int i = 0; i < m_count; i++) {
        m_particles_r[i].m_speed -= 0.00001;
    }
    return 0;
}

int global::setDelay() {
      time (&end);
      if (difftime (end,start) >= bf_time)
          return 1;
      else 
          return 0;
}
int global::setDuration() {
      time (&end);
      if (difftime (end,start) - bf_time <= af_time)
          return 1;
      else 
          return 0;
}
