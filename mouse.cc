#include "mouse.h"
#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>

mouse::mouse() { }

mouse::~mouse() { }

int mouse::setParticle(int number, float length, float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2) {
    srand (time(NULL));
    m_particles_m = new particles[number];
    m_count = number;
    m_length = length;
    for(int i = 0; i < m_count; i++) {
        m_particles_m[i].m_red = red;
        m_particles_m[i].m_green = green;
        m_particles_m[i].m_blue = blue;
        m_particles_m[i].m_lifetime = lifetime;
        m_particles_m[i].m_size = size;
        m_particles_m[i].m_speed = speed;
        m_particles_m[i].m_xangle = 0;
        m_particles_m[i].m_yangle = 0;
    }
    for(int i = 0; i < m_count; i++) {
        if (rand() % 2 == 1)
            m_particles_m[i].m_xpos = rand() % 1000;
        else
            m_particles_m[i].m_xpos = rand() % 1000;
        if (rand() % 2 == 1)
            m_particles_m[i].m_ypos = rand() % 1000;
        else
            m_particles_m[i].m_ypos = rand() % 1000;
    }
    bf_time = time1;
    af_time = time2;
    time (&start);
    return 0;
}

int mouse::setMouseParticleUpdate(float m_x, float m_y) {
    int m_aux;
    srand (time(NULL));
    m_xmouse = m_x;
    m_ymouse = m_y;
    for(int i = 0; i < m_count; i++) {
        if ((m_particles_m[i].m_xpos > m_xmouse - 1 && m_particles_m[i].m_xpos < m_xmouse + 1) &&  (m_particles_m[i].m_ypos > m_ymouse - 1 && m_particles_m[i].m_ypos < m_ymouse + 1)) {
            if (rand() % 2 == 1)
                m_particles_m[i].m_xpos = m_xmouse + rand() % m_length;
            else
                m_particles_m[i].m_xpos = m_xmouse - rand() % m_length;
            if (rand() % 2 == 1)
                m_particles_m[i].m_ypos = m_ymouse + rand() % m_length;
            else
                m_particles_m[i].m_ypos = m_ymouse - rand() % m_length;
        }
        else {
            m_aux = ((rand() % 10) + 1);
            m_particles_m[i].m_xangle = (m_xmouse - m_particles_m[i].m_xpos) * m_particles_m[i].m_speed * m_aux;
            m_particles_m[i].m_yangle = (m_ymouse - m_particles_m[i].m_ypos) * m_particles_m[i].m_speed * m_aux;
            m_particles_m[i].m_xpos += m_particles_m[i].m_xangle;
            m_particles_m[i].m_ypos += m_particles_m[i].m_yangle;
        }
    }
    return 0;
}

int mouse::setRandomColor() {
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (rand() % 2 == 1 && m_particles_m[i].m_red < 255)
            m_particles_m[i].m_red += 1;
        else if (rand() % 2 == 1 && m_particles_m[i].m_red == 255)
            m_particles_m[i].m_red -= 1;
        else if (rand() % 2 == 0 && m_particles_m[i].m_red > 0)
            m_particles_m[i].m_red -= 1;
        else
            m_particles_m[i].m_red += 1;
        if (rand() % 2 == 1 && m_particles_m[i].m_green < 255)
            m_particles_m[i].m_green += 1;
        else if (rand() % 2 == 1 && m_particles_m[i].m_green == 255)
            m_particles_m[i].m_green -= 1;
        else if (rand() % 2 == 0 && m_particles_m[i].m_green > 0)
            m_particles_m[i].m_green -= 1;
        else
            m_particles_m[i].m_green += 1;
        if (rand() % 2 == 1 && m_particles_m[i].m_blue < 255)
            m_particles_m[i].m_blue += 1;
        else if (rand() % 2 == 1 && m_particles_m[i].m_blue == 255)
            m_particles_m[i].m_blue -= 1;
        else if (rand() % 2 == 0 && m_particles_m[i].m_blue > 0)
            m_particles_m[i].m_blue -= 1;
        else
            m_particles_m[i].m_blue += 1;
    }
    return 0;
}

int mouse::setAccel() {
    for (int i = 0; i < m_count; i++) {
        m_particles_m[i].m_speed += 0.00001;
    }
    return 0;
}

int mouse::setDecel() {
    for (int i = 0; i < m_count; i++) {
        m_particles_m[i].m_speed -= 0.00001;
    }
    return 0;
}

int mouse::setDelay() {
      time (&end);
      if (difftime (end,start) >= bf_time)
          return 1;
      else 
          return 0;
}
int mouse::setDuration() {
      time (&end);
      if (difftime (end,start) - bf_time <= af_time)
          return 1;
      else 
          return 0;
}
