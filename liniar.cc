#include "liniar.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


liniar::liniar() { }

liniar::~liniar() { }

int liniar::setParticles(int number, float (*coord)[2], float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2) {
    int m_aux;
    m_particles_l = new particles[number];
    m_count = number;
    m_nextcoord = new float[m_count][2];
    m_coordonates = coord;
    m_poz = new int[m_count];
    for(int i = 0; i < m_count; i++) {
        m_particles_l[i].m_red = red;
        m_particles_l[i].m_green = green;
        m_particles_l[i].m_blue = blue;
        m_particles_l[i].m_lifetime = lifetime;
        m_particles_l[i].m_size = size;
        m_particles_l[i].m_speed = speed;
        m_particles_l[i].m_xangle = 0;
        m_particles_l[i].m_yangle = 0;
    }
    for(int i = 0; i < m_count; i++) {
        m_particles_l[i].m_xpos = m_coordonates[0][0];
        m_particles_l[i].m_ypos = m_coordonates[0][1];
        m_nextcoord[i][0] = m_coordonates[1][0];
        m_nextcoord[i][1] = m_coordonates[1][1];
        m_poz[i] = 1;
        m_aux = ((rand() % 50) + 1);
        m_particles_l[i].m_xangle = (m_nextcoord[i][0] - m_particles_l[i].m_xpos) * m_particles_l[i].m_speed * m_aux;
        m_particles_l[i].m_yangle = (m_nextcoord[i][1] - m_particles_l[i].m_ypos) * m_particles_l[i].m_speed *  m_aux;
    }
    bf_time = time1;
    af_time = time2;
    time (&start);
    return 0;
}

int liniar::setLiniarUpdate(){
    srand (time(NULL));

    for (int i = 0; i < m_count; i++) {
        if (m_particles_l[i].m_xpos == m_coordonates[1][0] && m_particles_l[i].m_ypos == m_coordonates[1][1]) {
            m_particles_l[i].m_xpos = m_coordonates[0][0];
            m_particles_l[i].m_ypos = m_coordonates[0][1];
            m_nextcoord[i][0] = m_coordonates[1][0];
            m_nextcoord[i][1] = m_coordonates[1][1];
            m_poz[i] = 1;
            m_particles_l[i].m_xangle = (m_coordonates[1][0] - m_particles_l[i].m_xpos) * m_particles_l[i].m_speed;
            m_particles_l[i].m_yangle = (m_coordonates[1][1] - m_particles_l[i].m_ypos) * m_particles_l[i].m_speed;
        }

        else {
            m_particles_l[i].m_xpos += m_particles_l[i].m_xangle;
            m_particles_l[i].m_ypos += m_particles_l[i].m_yangle;
        }
    }
    return 0;
}

int liniar::setRandomColor() {
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (rand() % 2 == 1 && m_particles_l[i].m_red < 255)
            m_particles_l[i].m_red += 1;
        else if (rand() % 2 == 1 && m_particles_l[i].m_red == 255)
            m_particles_l[i].m_red -= 1;
        else if (rand() % 2 == 0 && m_particles_l[i].m_red > 0)
            m_particles_l[i].m_red -= 1;
        else
            m_particles_l[i].m_red += 1;
        if (rand() % 2 == 1 && m_particles_l[i].m_green < 255)
            m_particles_l[i].m_green += 1;
        else if (rand() % 2 == 1 && m_particles_l[i].m_green == 255)
            m_particles_l[i].m_green -= 1;
        else if (rand() % 2 == 0 && m_particles_l[i].m_green > 0)
            m_particles_l[i].m_green -= 1;
        else
            m_particles_l[i].m_green += 1;
        if (rand() % 2 == 1 && m_particles_l[i].m_blue < 255)
            m_particles_l[i].m_blue += 1;
        else if (rand() % 2 == 1 && m_particles_l[i].m_blue == 255)
            m_particles_l[i].m_blue -= 1;
        else if (rand() % 2 == 0 && m_particles_l[i].m_blue > 0)
            m_particles_l[i].m_blue -= 1;
        else
            m_particles_l[i].m_blue += 1;
    }
    return 0;
}

int liniar::setTransitionColor(char red, char green, char blue) {
    for (int i = 0; i < m_count; i++) {
    if (m_particles_l[i].m_red < red)
        m_particles_l[i].m_red += 1;
    else if (m_particles_l[i].m_red > red)
        m_particles_l[i].m_red -= 1;
    if (m_particles_l[i].m_green < green)
        m_particles_l[i].m_green += 1;
    else if (m_particles_l[i].m_green > green)
        m_particles_l[i].m_green -= 1;
    if (m_particles_l[i].m_blue < blue)
        m_particles_l[i].m_blue += 1;
    else if (m_particles_l[i].m_blue > blue)
        m_particles_l[i].m_blue -= 1;
    if (m_particles_l[i].m_red == red && m_particles_l[i].m_green == green && m_particles_l[i].m_blue == blue)
        return 1;
    }
    return 0;
}

int liniar::setAccel() {
    for (int i = 0; i < m_count; i++) {
        m_particles_l[i].m_speed += 0.00001;
    }
    return 0;
}

int liniar::setDecel() {
    for (int i = 0; i < m_count; i++) {
        m_particles_l[i].m_speed -= 0.00001;
    }
    return 0;
}

int liniar::setDelay() {
      time (&end);
      if (difftime (end,start) >= bf_time)
          return 1;
      else 
          return 0;
}
int liniar::setDuration() {
      time (&end);
      if (difftime (end,start) - bf_time <= af_time)
          return 1;
      else 
          return 0;
}
