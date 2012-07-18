#include "liniar.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


liniar::liniar(int number, float (*coord)[2], char red, char green, char blue, float lifetime, float speed, float size) {
    m_particles = new particles[number];
    m_count = number;
    m_nextcoord = new float[m_count][2];
    m_coordonates = coord;
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

liniar::~liniar() { }

int liniar::setParticles() {
    int m_aux;
    for(int i = 0; i < m_count; i++) {
        m_particles[i].m_xpos = m_coordonates[0][0];
        m_particles[i].m_ypos = m_coordonates[0][1];
        m_nextcoord[i][0] = m_coordonates[1][0];
        m_nextcoord[i][1] = m_coordonates[1][1];
        m_aux = ((rand() % 10) + 1);
        m_particles[i].m_xangle = (m_nextcoord[i][0] - m_particles[i].m_xpos) * m_particles[i].m_speed * m_aux;
        m_particles[i].m_yangle = (m_nextcoord[i][1] - m_particles[i].m_ypos) * m_particles[i].m_speed * m_aux;
    }
    return 0;
}

int liniar::setLiniarUpdate(){
    srand (time(NULL));
    int m_aux;
    for (int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_coordonates[sizeof(m_coordonates)/sizeof(m_coordonates[0])][0] && m_particles[i].m_ypos == m_coordonates[sizeof(m_coordonates)/sizeof(m_coordonates[0])][1]) {
            m_particles[i].m_xpos = m_coordonates[0][0];
            m_particles[i].m_ypos = m_coordonates[0][1];
            m_nextcoord[i][0] = m_coordonates[1][0];
            m_nextcoord[i][1] = m_coordonates[1][1];
            m_aux = ((rand() % 10) + 1);
            m_particles[i].m_xangle = (m_nextcoord[i][0] - m_particles[i].m_xpos) * m_particles[i].m_speed * m_aux;
            m_particles[i].m_yangle = (m_nextcoord[i][1] - m_particles[i].m_ypos) * m_particles[i].m_speed * m_aux;
        }
        else if (m_particles[i].m_xpos == m_nextcoord[i][0] && m_particles[i].m_ypos == m_nextcoord[i][1]) {
            for (unsigned int j = 0; j < sizeof(m_coordonates)/sizeof(m_coordonates[0]); j++) {
                if (m_nextcoord[i][0] == m_coordonates[j][0]) {
                    m_nextcoord[i][0] = m_coordonates[j+1][0];
                    m_nextcoord[i][1] = m_coordonates[j+1][1];
                }
            }
            m_aux = ((rand() % 10) + 1);
            m_particles[i].m_xangle = (m_nextcoord[i][0] - m_particles[i].m_xpos) * m_particles[i].m_speed * m_aux;
            m_particles[i].m_yangle = (m_nextcoord[i][1] - m_particles[i].m_ypos) * m_particles[i].m_speed * m_aux;
        }
        else {
            m_particles[i].m_xpos += m_particles[i].m_xangle;
            m_particles[i].m_ypos += m_particles[i].m_yangle;
        }
    }
    return 0;
}

