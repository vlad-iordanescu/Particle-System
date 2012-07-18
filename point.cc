#include "point.h"
#include <stdlib.h>
#include <time.h>

point::point(int number, float x, float y, char red, char green, char blue, float lifetime, float speed, float size) {
    m_particles = new particles[number];
    m_count = number;
    m_xstart = x;
    m_ystart = y;
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
 
point::~point() { }

int point::setParticle() {
    for(int i = 0; i < m_count; i++) {
        m_particles[i].m_xpos = m_xstart;
        m_particles[i].m_ypos = m_ystart;
    }
    return 0;
}

int point::setPointMultipleUpdate() {
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_xstart && m_particles[i].m_ypos == m_ystart) {
            m_particles[i].m_xangle = (rand() % 100) / 1000;
            m_particles[i].m_yangle = (rand() % 100) / 1000;
            if (rand() % 2 == 1)
                m_particles[i].m_xangle = m_particles[i].m_xangle * -1;
            if (rand() % 2 == 1)
                m_particles[i].m_yangle = m_particles[i].m_yangle * -1;
        }
        else if (m_particles[i].m_xpos > m_particles[i].m_lifetime || m_particles[i].m_ypos > m_particles[i].m_lifetime) {
            m_particles[i].m_xpos = 0;
            m_particles[i].m_ypos = 0;
        }
        else {
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed * (rand() % 100) / 10000;
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed * (rand() % 100) / 10000;
        }
    }
    return 0;
}

int point::setPointOneUpdate(int m_length) { 
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_xstart && m_particles[i].m_ypos == m_ystart) {
            m_particles[i].m_xangle = (rand() % 100) / 1000;
            m_particles[i].m_yangle = (rand() % 100) / 1000;
            if (rand() % 2 == 1)
                m_particles[i].m_xangle = m_particles[i].m_xangle * -1;
            if (rand() % 2 == 1)
                m_particles[i].m_yangle = m_particles[i].m_yangle * -1;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed * (rand() % m_length);
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed * (rand() % m_length);
        }
        else if (m_particles[i].m_xpos > m_particles[i].m_lifetime || m_particles[i].m_ypos > m_particles[i].m_lifetime) {
            m_particles[i].m_xangle = m_particles[i].m_xangle * -1;
            m_particles[i].m_yangle = m_particles[i].m_yangle * -1;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed;
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed;
        }
        else {
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed;
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed;
        }
    }
    return 0;
}

int point::setPointDoubleUpdate(int m_length) { 
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_xstart && m_particles[i].m_ypos == m_ystart) {
            m_particles[i].m_xangle = (rand() % 100) / 1000;
            m_particles[i].m_yangle = (rand() % 100) / 1000;
            if (rand() % 2 == 1)
                m_particles[i].m_xangle = m_particles[i].m_xangle * -1;
            if (rand() % 2 == 1)
                m_particles[i].m_yangle = m_particles[i].m_yangle * -1;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed * (rand() % m_length);
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed * (rand() % m_length);
        }
        else if (m_particles[i].m_xpos > m_particles[i].m_lifetime || m_particles[i].m_ypos > m_particles[i].m_lifetime) {
            m_particles[i].m_xpos = 0;
            m_particles[i].m_ypos = 0;
        }
        else {
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed;
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed;
        }
    }
    return 0;
}

int point::setRandomColor() {
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (rand() % 2 == 1 && m_particles[i].m_red < 255)
            m_particles[i].m_red += 1;
        else if (rand() % 2 == 1 && m_particles[i].m_red == 255)
            m_particles[i].m_red -= 1;
        else if (rand() % 2 == 0 && m_particles[i].m_red > 0)
            m_particles[i].m_red -= 1;
        else
            m_particles[i].m_red += 1;
        if (rand() % 2 == 1 && m_particles[i].m_green < 255)
            m_particles[i].m_green += 1;
        else if (rand() % 2 == 1 && m_particles[i].m_green == 255)
            m_particles[i].m_green -= 1;
        else if (rand() % 2 == 0 && m_particles[i].m_green > 0)
            m_particles[i].m_green -= 1;
        else
            m_particles[i].m_green += 1;
        if (rand() % 2 == 1 && m_particles[i].m_blue < 255)
            m_particles[i].m_blue += 1;
        else if (rand() % 2 == 1 && m_particles[i].m_blue == 255)
            m_particles[i].m_blue -= 1;
        else if (rand() % 2 == 0 && m_particles[i].m_blue > 0)
            m_particles[i].m_blue -= 1;
        else
            m_particles[i].m_blue += 1;
    }
    return 0;
}

int point::setTransitionColor(char red, char green, char blue) {
    for (int i = 0; i < m_count; i++) {
    if (m_particles[i].m_red < red)
        m_particles[i].m_red += 1;
    else if (m_particles[i].m_red > red)
        m_particles[i].m_red -= 1;
    if (m_particles[i].m_green < green)
        m_particles[i].m_green += 1;
    else if (m_particles[i].m_green > green)
        m_particles[i].m_green -= 1;
    if (m_particles[i].m_blue < blue)
        m_particles[i].m_blue += 1;
    else if (m_particles[i].m_blue > blue)
        m_particles[i].m_blue -= 1;
    if (m_particles[i].m_red == red && m_particles[i].m_green == green && m_particles[i].m_blue == blue)
        return 1;
    }
    return 0;
}

int point::setAccel(float m_aux) {
    for (int i = 0; i < m_count; i++) {
        m_particles[i].m_speed += m_aux;
    }
    return 0;
}

int point::setDecel(float m_aux) {
    for (int i = 0; i < m_count; i++) {
        m_particles[i].m_speed -= m_aux;
    }
    return 0;
}

