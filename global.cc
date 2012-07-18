#include "global.h"
#include <stdlib.h>
#include <time.h>

global::global(int number, int x1, int y1, int x2, int y2, char red, char green, char blue, float lifetime, float speed, float size) {
    m_particles = new particles[number];
    m_count = number;
    m_xstart = x1;
    m_ystart = y1;
    m_xfin = x2;
    m_yfin = y2;
    m_constlifetime = lifetime;
    for(int i = 0; i < m_count; i++) {
        m_particles[i].m_red = red;
        m_particles[i].m_green = green;
        m_particles[i].m_blue = blue;
        m_particles[i].m_lifetime = lifetime;
        m_particles[i].m_size = size;
        m_particles[i].m_speed = speed;
        m_particles[i].m_xangle = 0;
        m_particles[i].m_yangle = 0;
    }
}

global::~global() { }

int global::setParticle() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        m_particles[i].m_xpos = (rand() % (m_xstart - m_xfin)) + m_xfin;
        m_particles[i].m_ypos = (rand() % (m_ystart - m_yfin)) + m_yfin;
    }
    return 0;
}

int global::setUpdateRandomMov() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        if (m_particles[i].m_lifetime == 0 || m_particles[i].m_xpos > m_xstart || m_particles[i].m_xpos < m_xfin || m_particles[i].m_ypos > m_ystart || m_particles[i].m_ypos < m_yfin) {
            m_particles[i].m_xpos = (rand() % (m_xstart - m_xfin)) + m_xfin;
            m_particles[i].m_ypos = (rand() % (m_ystart - m_yfin)) + m_yfin;
            m_particles[i].m_lifetime = m_constlifetime;
        }
        else {
            m_particles[i].m_xangle = (rand() % 100) / 1000;
            m_particles[i].m_yangle = (rand() % 100) / 1000;
            if (rand() % 2 == 1)
                m_particles[i].m_xangle = m_particles[i].m_xangle * -1;
            if (rand() % 2 == 1)
                m_particles[i].m_yangle = m_particles[i].m_yangle * -1;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed;
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed;
            m_particles[i].m_lifetime--;
        }
    }
    return 0;
}

int global::setUpdateRandomBlink() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        m_particles[i].m_xpos = (rand() % (m_xstart - m_xfin)) + m_xfin;
        m_particles[i].m_ypos = (rand() % (m_ystart - m_yfin)) + m_yfin;
    }
    return 0;
}

int global::setUpdateRain() {
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        if (m_particles[i].m_lifetime == 0 || m_particles[i].m_xpos < m_xfin) {
            m_particles[i].m_xpos = (rand() % (m_xstart - m_xfin)) + m_xfin;
            m_particles[i].m_ypos = (rand() % (m_ystart - m_yfin)) + m_yfin;
            m_particles[i].m_lifetime = m_constlifetime;
        }
        else {
            m_particles[i].m_yangle = (rand() % 100) / 1000;
            m_particles[i].m_ypos -= m_particles[i].m_yangle * m_particles[i].m_speed;
            m_particles[i].m_lifetime--;
        }
    }
    return 0;
}
