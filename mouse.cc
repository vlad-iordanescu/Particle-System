#include "mouse.h"
#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>

mouse::mouse(int number, float length, char red, char green, char blue, float lifetime, float speed, float size) {
    m_particles = new particles[number];
    m_count = number;
    m_length = length;
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

mouse::~mouse() { }

int mouse::setParticle() {
    srand (time(NULL));
    glutPassiveMotionFunc(setmouseMovement);
    for(int i = 0; i < m_count; i++) {
        if (rand() % 2 == 1)
            m_particles[i].m_xpos += rand() % m_length;
        else
            m_particles[i].m_xpos -= rand() % m_length;
        if (rand() % 2 == 1)
            m_particles[i].m_ypos += rand() % m_length;
        else
            m_particles[i].m_ypos -= rand() % m_length;
    }
    return 0;
}

int mouse::setMouseParticleUpdate() {
    int m_aux;
    srand (time(NULL));
    for(int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_xmouse &&  m_particles[i].m_ypos == m_ymouse) {
            if (rand() % 2 == 1)
                m_particles[i].m_xpos += rand() % m_length;
            else
                m_particles[i].m_xpos -= rand() % m_length;
            if (rand() % 2 == 1)
                m_particles[i].m_ypos += rand() % m_length;
            else
                m_particles[i].m_ypos -= rand() % m_length;
        }
        else {
            m_aux = ((rand() % 10) + 1);
            m_particles[i].m_xangle = (m_xmouse - m_particles[i].m_xpos) * m_particles[i].m_speed * m_aux;
            m_particles[i].m_yangle = (m_ymouse - m_particles[i].m_xpos) * m_particles[i].m_speed * m_aux;
            m_particles[i].m_xpos += m_particles[i].m_xangle;
            m_particles[i].m_ypos += m_particles[i].m_yangle;
        }
    }
    return 0;
}

void mouse::setmouseMovement(int x, int y) {
    m_xmouse = x;
    m_ymouse = y;
}
