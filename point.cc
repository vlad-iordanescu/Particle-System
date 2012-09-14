#include "point.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>



point::point() { }
 
point::~point() { }

int point::setParticle(int number, float x, float y, float red, float green, float blue, float lifetime, float speed, float size, float time1, float time2) {
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
        m_particles[i].m_xangle = 1;
        m_particles[i].m_yangle = 1;
    }
    for(int i = 0; i < m_count; i++) {
        m_particles[i].m_xpos = m_xstart;
        m_particles[i].m_ypos = m_ystart;
    }
    m_start = 1;
    bf_time = time1;
    af_time = time2;

    time (&start);
    return 0;
}

int point::setPointMultipleUpdate() {
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_xstart && m_particles[i].m_ypos == m_ystart) {

            m_particles[i].m_xangle = ((rand() % 1000) - 500) / 10;
            rand();
            m_particles[i].m_yangle = ((rand() % 1000) - 500) / 10;
            rand();
            if (m_particles[i].m_xangle == 0)
                m_particles[i].m_xangle++;
            else if (m_particles[i].m_yangle == 0)
                m_particles[i].m_yangle++;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed * (rand()%10);
            rand();
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed * (rand()%10);
        }
        else if (sqrt((m_xstart - m_particles[i].m_xpos) * (m_xstart - m_particles[i].m_xpos) + (m_ystart - m_particles[i].m_ypos) * (m_ystart - m_particles[i].m_ypos)) > m_particles[0].m_lifetime) {
            m_particles[i].m_xpos = m_xstart;
            m_particles[i].m_ypos = m_ystart;
        }
        else {
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed * ((rand()%100)/100 + 0.1);
            rand();
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed * ((rand()%100)/100 + 0.1);
        }
    }
    return 0;
}

int point::setPointOneUpdate(int m_length) { 
    srand (time(NULL));
    for (int i = 0; i < m_count; i++) {
        if (m_particles[i].m_xpos == m_xstart && m_particles[i].m_ypos == m_ystart && m_start == 1) {
            m_particles[i].m_xangle = ((rand() % 1000) - 500) / 10;
            rand();
            m_particles[i].m_yangle = ((rand() % 1000) - 500) / 10;
            rand();
            
                if (i < m_count / 4) 
                     m_particles[i].m_xangle = -50;
                
                else if (i < m_count / 2) 
                     m_particles[i].m_xangle = 50;
                
                else if (i < (3 * m_count) / 4) 
                     m_particles[i].m_yangle = -50;
                
                else 
                     m_particles[i].m_yangle = 50;
                
            
            if (m_particles[i].m_xangle == 0)
                m_particles[i].m_xangle++;
            else if (m_particles[i].m_yangle == 0)
                m_particles[i].m_yangle++;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed; //* ((rand() % m_length) + 1);
            rand();
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed; //* ((rand() % m_length) + 1);
        }
        else if (sqrt((m_xstart - m_particles[i].m_xpos) * (m_xstart - m_particles[i].m_xpos) + (m_ystart - m_particles[i].m_ypos) * (m_ystart - m_particles[i].m_ypos)) > m_particles[0].m_lifetime) {
            m_particles[i].m_xangle = m_particles[i].m_xangle * -1;
            m_particles[i].m_yangle = m_particles[i].m_yangle * -1;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed;
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed;
            m_start = 0;
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
        if (m_particles[i].m_xpos == m_xstart && m_particles[i].m_ypos == m_ystart && m_start == 1) {
            m_particles[i].m_xangle = ((rand() % 1000) - 500) / 10;
            rand();
            m_particles[i].m_yangle = ((rand() % 1000) - 500) / 10;
            rand();
            
                if (i < m_count / 4) 
                     m_particles[i].m_xangle = -50;
                
                else if (i < m_count / 2) 
                     m_particles[i].m_xangle = 50;
                
                else if (i < (3 * m_count) / 4) 
                     m_particles[i].m_yangle = -50;
                
                else 
                     m_particles[i].m_yangle = 50;
                
            
            if (m_particles[i].m_xangle == 0)
                m_particles[i].m_xangle++;
            else if (m_particles[i].m_yangle == 0)
                m_particles[i].m_yangle++;
            m_particles[i].m_xpos += m_particles[i].m_xangle * m_particles[i].m_speed * (rand() % m_length);
            m_particles[i].m_ypos += m_particles[i].m_yangle * m_particles[i].m_speed * (rand() % m_length);
            
        }
        else if (sqrt((m_xstart - m_particles[i].m_xpos) * (m_xstart - m_particles[i].m_xpos) + (m_ystart - m_particles[i].m_ypos) * (m_ystart - m_particles[i].m_ypos)) > m_particles[0].m_lifetime) {
            m_particles[i].m_xpos = m_xstart;
            m_particles[i].m_ypos = m_ystart;
            m_start = 0;
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

int point::setAccel() {
    for (int i = 0; i < m_count; i++) {
        m_particles[i].m_speed += 0.00001;
    }
    return 0;
}

int point::setDecel() {
    for (int i = 0; i < m_count; i++) {
        m_particles[i].m_speed -= 0.00001;
    }
    return 0;
}

int point::setDelay() {
      time (&end);
      if (difftime (end,start) >= bf_time)
          return 1;
      else 
          return 0;
}
int point::setDuration() {
      time (&end);
      if (difftime (end,start) - bf_time <= af_time)
          return 1;
      else 
          return 0;
}
