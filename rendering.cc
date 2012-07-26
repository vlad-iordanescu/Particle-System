#include<iostream>
#include<string.h>
#include"point.h"
using namespace std;
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
bool m_RndClr = false;
bool m_TrClr = false;
bool m_Accel = false;
bool m_Decel = false;

int main(int argc,char *argv[]){
    string m_str;
    m_str = argv[1];
    if (m_str == "point") {
    int number;
    float x, y;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x = atof(m_str.c_str());
    m_str = argv[4];
    y = atof(m_str.c_str());
    m_str = argv[5];
    red = (char)atoi(m_str.c_str());
    m_str = argv[6];
    green = (char)atoi(m_str.c_str());
    m_str = argv[7];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[8];
    lifetime = atof(m_str.c_str());
    m_str = argv[9];
    speed = atof(m_str.c_str());
    m_str = argv[10];
    size = atof(m_str.c_str());
    m_str = argv[11];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[12];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[13];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[14];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[15];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[12];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    point point_n(number, x, y, red, green, blue, lifetime, speed, size);
    glPointSize(point_n.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    point_n.setParticle();
    for(int i = 0; i < number; i++) {
        glColor3f(point_n.m_particles[i].m_red, point_n.m_particles[i].m_green, point_n.m_particles[i].m_blue);
        glVertex3f(point_n.m_particles[i].m_xpos, point_n.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        point_n.setPointMultipleUpdate();
        if (m_RndClr)
            point_n.setRandomColor();
        if (m_TrClr)
            point_n.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            point_n.setAccel(speed/0.01);
        if (m_Decel)
            point_n.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(point_n.m_particles[i].m_red, point_n.m_particles[i].m_green, point_n.m_particles[i].m_blue);
            glVertex3f(point_n.m_particles[i].m_xpos, point_n.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }
    else if (m_str == "point_r") {
    int number, length;
    float x, y;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x = atof(m_str.c_str());
    m_str = argv[4];
    y = atof(m_str.c_str());
    m_str = argv[5];
    red = (char)atoi(m_str.c_str());
    m_str = argv[6];
    green = (char)atoi(m_str.c_str());
    m_str = argv[7];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[8];
    lifetime = atof(m_str.c_str());
    m_str = argv[9];
    speed = atof(m_str.c_str());
    m_str = argv[10];
    size = atof(m_str.c_str());
    m_str = argv[11];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[12];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[13];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[14];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[15];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[12];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    m_str = argv[16];
    length = atoi(m_str.c_str());
    point point_r(number, x, y, red, green, blue, lifetime, speed, size);
    glPointSize(point_r.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    point_r.setParticle();
    for(int i = 0; i < number; i++) {
        glColor3f(point_r.m_particles[i].m_red, point_r.m_particles[i].m_green, point_r.m_particles[i].m_blue);
        glVertex3f(point_r.m_particles[i].m_xpos, point_r.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        point_r.setPointOneUpdate(length);
        if (m_RndClr)
            point_r.setRandomColor();
        if (m_TrClr)
            point_r.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            point_r.setAccel(speed/0.01);
        if (m_Decel)
            point_r.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(point_r.m_particles[i].m_red, point_r.m_particles[i].m_green, point_r.m_particles[i].m_blue);
            glVertex3f(point_r.m_particles[i].m_xpos, point_r.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }
    else if (m_str == "point_rd") {
    int number, length;
    float x, y;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x = atof(m_str.c_str());
    m_str = argv[4];
    y = atof(m_str.c_str());
    m_str = argv[5];
    red = (char)atoi(m_str.c_str());
    m_str = argv[6];
    green = (char)atoi(m_str.c_str());
    m_str = argv[7];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[8];
    lifetime = atof(m_str.c_str());
    m_str = argv[9];
    speed = atof(m_str.c_str());
    m_str = argv[10];
    size = atof(m_str.c_str());
    m_str = argv[11];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[12];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[13];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[14];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[15];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[12];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    m_str = argv[16];
    length = atoi(m_str.c_str());
    point point_rd(number, x, y, red, green, blue, lifetime, speed, size);
    glPointSize(point_rd.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    point_rd.setParticle();
    for(int i = 0; i < number; i++) {
        glColor3f(point_rd.m_particles[i].m_red, point_rd.m_particles[i].m_green, point_rd.m_particles[i].m_blue);
        glVertex3f(point_rd.m_particles[i].m_xpos, point_rd.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        point_rd.setPointDoubleUpdate(length);
        if (m_RndClr)
            point_rd.setRandomColor();
        if (m_TrClr)
            point_rd.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            point_rd.setAccel(speed/0.01);
        if (m_Decel)
            point_rd.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(point_rd.m_particles[i].m_red, point_rd.m_particles[i].m_green, point_rd.m_particles[i].m_blue);
            glVertex3f(point_rd.m_particles[i].m_xpos, point_rd.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }
    else if (m_str == "liniar") {
    int number,aux;
    float (*coord)[2], x, y;
    float lifetime, speed, size;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    if (argc % 2 == 0) {
        coord = new float[(argc - 10) / 2][2];
        for(int i = 0; i < (argc - 10) / 2; i++) {
            m_str = argv[3 + 2 * i];
            x = atof(m_str.c_str());
            coord[i][0] = x;
            m_str = argv[4 + 2 * i + 1];
            y = atof(m_str.c_str());
            coord[i][1] = y;
        }
    aux = (argc - 10);
    }
    else {
        coord = new float[(argc - 13) / 2][2];
        for(int i = 0; i < (argc - 13) / 2; i++) {
            m_str = argv[3 + 2 * i];
            x = atof(m_str.c_str());
            coord[i][0] = x;
            m_str = argv[4 + 2 * i + 1];
            y = atof(m_str.c_str());
            coord[i][1] = y;
        }
    aux = (argc - 13);
    }
    m_str = argv[3 + aux];
    red = (char)atoi(m_str.c_str());
    m_str = argv[4 + aux];
    green = (char)atoi(m_str.c_str());
    m_str = argv[5 + aux];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[6 + aux];
    lifetime = atof(m_str.c_str());
    m_str = argv[7 + aux];
    speed = atof(m_str.c_str());
    m_str = argv[8 + aux];
    size = atof(m_str.c_str());
    m_str = argv[9 + aux];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans") 
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[10 + aux];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[11 + aux];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[12 + aux];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[13 + aux];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[10 + aux];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    liniar liniar_n(number, coord, red, green, blue, lifetime, speed, size);
    glPointSize(liniar_n.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    liniar_n.setParticles();
    for(int i = 0; i < number; i++) {
        glColor3f(liniar_n.m_particles[i].m_red, liniar_n.m_particles[i].m_green, liniar_n.m_particles[i].m_blue);
        glVertex3f(liniar_n.m_particles[i].m_xpos, liniar_n.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        liniar_n.setLiniarUpdate();
        if (m_RndClr)
            liniar_n.setRandomColor();
        if (m_TrClr)
            liniar_n.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            liniar_n.setAccel(speed/0.01);
        if (m_Decel)
            liniar_n.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(liniar_n.m_particles[i].m_red, liniar_n.m_particles[i].m_green, liniar_n.m_particles[i].m_blue);
            glVertex3f(liniar_n.m_particles[i].m_xpos, liniar_n.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }
    else if (m_str == "random") {
    int number;
    float x1, y1, x2, y2;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x1 = atof(m_str.c_str());
    m_str = argv[4];
    y1 = atof(m_str.c_str());
    m_str = argv[5];
    x2 = atof(m_str.c_str());
    m_str = argv[6];
    y2 = atof(m_str.c_str());
    m_str = argv[7];
    red = (char)atoi(m_str.c_str());
    m_str = argv[8];
    green = (char)atoi(m_str.c_str());
    m_str = argv[9];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[10];
    lifetime = atof(m_str.c_str());
    m_str = argv[11];
    speed = atof(m_str.c_str());
    m_str = argv[12];
    size = atof(m_str.c_str());
    m_str = argv[13];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[14];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[15];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[16];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[17];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[14];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    global global_n(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size);
    glPointSize(global_n.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    global_n.setParticle();
    for(int i = 0; i < number; i++) {
        glColor3f(global_n.m_particles[i].m_red, global_n.m_particles[i].m_green, global_n.m_particles[i].m_blue);
        glVertex3f(global_n.m_particles[i].m_xpos, global_n.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        global_n.setUpdateRandomMov();
        if (m_RndClr)
            global_n.setRandomColor();
        if (m_TrClr)
            global_n.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            global_n.setAccel(speed/0.01);
        if (m_Decel)
            global_n.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(global_n.m_particles[i].m_red, global_n.m_particles[i].m_green, global_n.m_particles[i].m_blue);
            glVertex3f(global_n.m_particles[i].m_xpos, global_n.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }
    else if (m_str == "random_blk") {
    int number;
    float x1, y1, x2, y2;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x1 = atof(m_str.c_str());
    m_str = argv[4];
    y1 = atof(m_str.c_str());
    m_str = argv[5];
    x2 = atof(m_str.c_str());
    m_str = argv[6];
    y2 = atof(m_str.c_str());
    m_str = argv[7];
    red = (char)atoi(m_str.c_str());
    m_str = argv[8];
    green = (char)atoi(m_str.c_str());
    m_str = argv[9];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[10];
    lifetime = atof(m_str.c_str());
    m_str = argv[11];
    speed = atof(m_str.c_str());
    m_str = argv[12];
    size = atof(m_str.c_str());
    m_str = argv[13];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[14];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[15];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[16];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[17];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[14];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    global global_blk(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size);
    glPointSize(global_blk.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    global_blk.setParticle();
    for(int i = 0; i < number; i++) {
        glColor3f(global_blk.m_particles[i].m_red, global_blk.m_particles[i].m_green, global_blk.m_particles[i].m_blue);
        glVertex3f(global_blk.m_particles[i].m_xpos, global_blk.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        global_blk.setUpdateRandomBlink();
        if (m_RndClr)
            global_blk.setRandomColor();
        if (m_TrClr)
            global_blk.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            global_blk.setAccel(speed/0.01);
        if (m_Decel)
            global_blk.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(global_blk.m_particles[i].m_red, global_blk.m_particles[i].m_green, global_blk.m_particles[i].m_blue);
            glVertex3f(global_blk.m_particles[i].m_xpos, global_blk.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }
    else if (m_str == "random_rain") {
    int number;
    float x1, y1, x2, y2;
    char red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x1 = atof(m_str.c_str());
    m_str = argv[4];
    y1 = atof(m_str.c_str());
    m_str = argv[5];
    x2 = atof(m_str.c_str());
    m_str = argv[6];
    y2 = atof(m_str.c_str());
    m_str = argv[7];
    red = (char)atoi(m_str.c_str());
    m_str = argv[8];
    green = (char)atoi(m_str.c_str());
    m_str = argv[9];
    blue = (char)atoi(m_str.c_str());
    m_str = argv[10];
    lifetime = atof(m_str.c_str());
    m_str = argv[11];
    speed = atof(m_str.c_str());
    m_str = argv[12];
    size = atof(m_str.c_str());
    m_str = argv[13];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[14];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[15];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[16];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[17];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    else {
        m_str = argv[14];
    if (m_str == "accel")
        m_Accel = true;
    else if (m_str == "decel")
        m_Decel = true;
    }
    global global_blk(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size);
    glPointSize(global_blk.m_particles[0].m_size);
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glBegin(GL_POINTS);
    global_blk.setParticle();
    for(int i = 0; i < number; i++) {
        glColor3f(global_blk.m_particles[i].m_red, global_blk.m_particles[i].m_green, global_blk.m_particles[i].m_blue);
        glVertex3f(global_blk.m_particles[i].m_xpos, global_blk.m_particles[i].m_ypos,0);
    }
    glEnd();
    while (1) {
        glBegin(GL_POINTS);
        global_blk.setRandomColor();
        if (m_RndClr)
            global_blk.setRandomColor();
        if (m_TrClr)
            global_blk.setTransitionColor(tr_red, tr_green, tr_blue);
        if (m_Accel)
            global_blk.setAccel(speed/0.01);
        if (m_Decel)
            global_blk.setDecel(speed/0.01);
        for(int i = 0; i < number; i++) {
            glColor3f(global_blk.m_particles[i].m_red, global_blk.m_particles[i].m_green, global_blk.m_particles[i].m_blue);
            glVertex3f(global_blk.m_particles[i].m_xpos, global_blk.m_particles[i].m_ypos,0);
            glEnd();
        }
    }
    }

return 0;
}
