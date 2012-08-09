#include<iostream>
#include<string.h>
#include "mouse.h"
using namespace std;
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
bool m_RndClr = false;
bool m_TrClr = false;
bool m_Accel = false;
bool m_Decel = false;
bool m_point = false;
bool m_point_r = false;
bool m_point_rd = false;
bool m_point_accel = false;
bool m_point_decel = false;
bool m_global = false;
bool m_global_blk = false;
bool m_global_rain = false;
bool m_global_accel = false;
bool m_global_decel = false;
bool m_liniar = false;
bool m_liniar_accel = false;
bool m_liniar_decel = false;
bool m_mouse = false;
bool m_mouse_accel = false;
bool m_mouse_decel = false;
short start = 1;
const double Xmin = 0.0, Xmax = 1000.0;
const double Ymin = 0.0, Ymax = 1000.0;
point point_n;
global global_n;
liniar liniar_n;
mouse mouse_n;
int length;

float m_xmouse_pos, m_ymouse_pos;
void setmouseMovement(int x, int y) {
    m_xmouse_pos = ((float)x / 800) * 1400 - 200;
    m_ymouse_pos = ((((float)y - 600) * -1) / 600) * 1000;
    glutPostRedisplay();
}

void MyDisplay_point_n(void) {

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(m_RndClr == true)
        point_n.setRandomColor();
    if (m_point == true || m_point_r == true || m_point_rd == true)
        glColor3f(point_n.m_particles[0].m_red, point_n.m_particles[0].m_green, point_n.m_particles[0].m_blue);  
    if (m_global == true || m_global_blk == true || m_global_rain == true)
        glColor3f(global_n.m_particles_r[0].m_red, global_n.m_particles_r[0].m_green, global_n.m_particles_r[0].m_blue);
    if (m_liniar == true)
        glColor3f(liniar_n.m_particles_l[0].m_red, liniar_n.m_particles_l[0].m_green, liniar_n.m_particles_l[0].m_blue);
    if (m_mouse == true)
        glColor3f(mouse_n.m_particles_m[0].m_red, mouse_n.m_particles_m[0].m_green, mouse_n.m_particles_m[0].m_blue);
    glBegin(GL_POINTS);
    if (m_point == true)
        point_n.setPointMultipleUpdate();
    if (m_point_r == true)
        point_n.setPointOneUpdate(length);
    if (m_point_rd == true)
        point_n.setPointDoubleUpdate(length);
    if (m_point_accel == true)
        point_n.setAccel();
    if (m_point_decel == true)
        point_n.setDecel();
    if (m_global == true)
        global_n.setUpdateRandomMov();
    if (m_global_blk == true)
        global_n.setUpdateRandomBlink();
    if (m_global_rain == true)
        global_n.setUpdateRain();
    if (m_global_accel == true)
        global_n.setAccel();
    if (m_global_decel == true)
        global_n.setDecel();
    if (m_mouse == true)
        mouse_n.setMouseParticleUpdate(m_xmouse_pos, m_ymouse_pos);
    if (m_mouse_accel == true)
        mouse_n.setAccel();
    if (m_mouse_decel == true)
        mouse_n.setDecel();
    if (m_liniar == true)
        liniar_n.setLiniarUpdate();
    if (m_liniar_accel == true)
        liniar_n.setAccel();
    if (m_liniar_decel == true)
        liniar_n.setDecel();
    if (m_point == true || m_point_r == true || m_point_rd == true) {
        for (int i = 0; i < point_n.m_count; i++) 
            glVertex2f(point_n.m_particles[i].m_xpos, point_n.m_particles[i].m_ypos);
    }
    if (m_global == true || m_global_blk == true || m_global_rain == true) {
        for (int i = 0; i < global_n.m_count; i++) 
            glVertex2f(global_n.m_particles_r[i].m_xpos, global_n.m_particles_r[i].m_ypos);
    }
    if (m_liniar == true) {
        for (int i = 0; i < liniar_n.m_count; i++) 
            glVertex2f(liniar_n.m_particles_l[i].m_xpos, liniar_n.m_particles_l[i].m_ypos);
    }
    if (m_mouse == true) {
        for (int i = 0; i < mouse_n.m_count; i++) 
            glVertex2f(mouse_n.m_particles_m[i].m_xpos, mouse_n.m_particles_m[i].m_ypos);
    }
    glEnd();
    glutSwapBuffers();

}


void resizeWindow(int w, int h) {
    double scale, center;
    double windowXmin, windowXmax, windowYmin, windowYmax;
    glViewport( 0, 0, w, h );
    w = (w==0) ? 1 : w;
    h = (h==0) ? 1 : h;
    if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
        scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
        center = (Xmax+Xmin)/2;
        windowXmin = center - (center-Xmin)*scale;
        windowXmax = center + (Xmax-center)*scale;
        windowYmin = Ymin;
        windowYmax = Ymax;
    }
    else {
        scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
        center = (Ymax+Ymin)/2;
        windowYmin = center - (center-Ymin)*scale;
        windowYmax = center + (Ymax-center)*scale;
        windowXmin = Xmin;
        windowXmax = Xmax;
    }
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -1, 1 );
}



int main(int argc,char *argv[]){
    float x, y;
    float (*coord)[2];
    float x1, y1, x2, y2;
    float red, green, blue;
    char tr_red, tr_green, tr_blue;
    float lifetime, speed, size;
    int number;
    string m_str;
    m_str = argv[1];
    if (m_str == "point") {
    m_point = true;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x = atof(m_str.c_str());
    m_str = argv[4];
    y = atof(m_str.c_str());
    m_str = argv[5];
    red = atof(m_str.c_str());
    m_str = argv[6];
    green = atof(m_str.c_str());
    m_str = argv[7];
    blue = atof(m_str.c_str());
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
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    }
    else {
        m_str = argv[12];
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    }


    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    glutReshapeFunc( resizeWindow );
    point_n.setParticle(number, x, y, red, green, blue, lifetime, speed, size);
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();

    
    }
    else if (m_str == "point_r") {
    m_point_r = true;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x = atof(m_str.c_str());
    m_str = argv[4];
    y = atof(m_str.c_str());
    m_str = argv[5];
    red = atof(m_str.c_str());
    m_str = argv[6];
    green = atof(m_str.c_str());
    m_str = argv[7];
    blue = atof(m_str.c_str());
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
    if (m_TrClr == true) {
    m_str = argv[12];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[13];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[14];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[15];
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    m_str = argv[16];
    length = atoi(m_str.c_str());
    }
    else {
        m_str = argv[12];
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    m_str = argv[13];
    length = atoi(m_str.c_str());
    }
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    glutReshapeFunc( resizeWindow );
    point_n.setParticle(number, x, y, red, green, blue, lifetime, speed, size);
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();
    }
    else if (m_str == "point_rd") {
    m_point_rd = true;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    x = atof(m_str.c_str());
    m_str = argv[4];
    y = atof(m_str.c_str());
    m_str = argv[5];
    red = atof(m_str.c_str());
    m_str = argv[6];
    green = atof(m_str.c_str());
    m_str = argv[7];
    blue = atof(m_str.c_str());
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
    if (m_TrClr == true) {
    m_str = argv[12];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[13];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[14];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[15];
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    m_str = argv[16];
    length = atoi(m_str.c_str());
    }
    else {
        m_str = argv[12];
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    m_str = argv[13];
    length = atoi(m_str.c_str());
    }
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    glutReshapeFunc( resizeWindow );
    point_n.setParticle(number, x, y, red, green, blue, lifetime, speed, size);
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();
    }
    else if (m_str == "liniar") {
    m_liniar = true;
    int aux;

    m_str = argv[2];;
    number = atoi(m_str.c_str());
    if (argc % 2 == 1) {
        coord = new float[(argc - 11) / 2][2];
        for(int i = 0; i < (argc - 11) / 2; i++) {
            m_str = argv[3 + 2 * i];
            x = atof(m_str.c_str());
            coord[i][0] = x;
            
            m_str = argv[3 + 2 * i + 1];
            y = atof(m_str.c_str());
            coord[i][1] = y;
        }
    aux = (argc - 11);
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
    red = atof(m_str.c_str());
    m_str = argv[4 + aux];
    green = atof(m_str.c_str());
    m_str = argv[5 + aux];
    blue = atof(m_str.c_str());
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
        m_liniar_accel = true;
    else if (m_str == "decel")
        m_liniar_decel = true;
    }
    else {
        m_str = argv[10 + aux];
    if (m_str == "accel")
        m_liniar_accel = true;
    else if (m_str == "decel")
        m_liniar_decel = true;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    liniar_n.setParticles(number, coord, red, green, blue, lifetime, speed, size);
    glutReshapeFunc( resizeWindow );
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();
    }
    else if (m_str == "random") {
    m_global = true;
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
    red = atof(m_str.c_str());
    m_str = argv[8];
    green = atof(m_str.c_str());
    m_str = argv[9];
    blue = atof(m_str.c_str());
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
        m_global_accel = true;
    else if (m_str == "decel")
        m_global_decel = true;
    }
    else {
        m_str = argv[14];
    if (m_str == "accel")
        m_global_accel = true;
    else if (m_str == "decel")
        m_global_decel = true;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    global_n.setParticle(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size);
    glutReshapeFunc( resizeWindow );
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();
    }
    else if (m_str == "random_blk") {
    m_global_blk = true;
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
    red = atof(m_str.c_str());
    m_str = argv[8];
    green = atof(m_str.c_str());
    m_str = argv[9];
    blue = atof(m_str.c_str());
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
        m_global_accel = true;
    else if (m_str == "decel")
        m_global_decel = true;
    }
    else {
        m_str = argv[14];
    if (m_str == "accel")
        m_global_accel = true;
    else if (m_str == "decel")
        m_global_decel = true;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    global_n.setParticle(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size);
    glutReshapeFunc( resizeWindow );
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();
    }
    else if (m_str == "random_rain") {
    m_global_rain = true;	
    m_str = argv[2];
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
    red = atof(m_str.c_str());
    m_str = argv[8];
    green = atof(m_str.c_str());
    m_str = argv[9];
    blue = atof(m_str.c_str());
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
        m_global_accel = true;
    else if (m_str == "decel")
        m_global_decel = true;
    }
    else {
        m_str = argv[14];
    if (m_str == "accel")
        m_global_accel = true;
    else if (m_str == "decel")
        m_global_decel = true;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    global_n.setParticle(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size);
    glutReshapeFunc( resizeWindow );
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();
    }
    
    else if (m_str == "mouse") {
    float length;
    m_mouse = true;
    m_str = argv[2];;
    number = atoi(m_str.c_str());
    m_str = argv[3];
    length = atof(m_str.c_str());
    m_str = argv[4];
    red = atof(m_str.c_str());
    m_str = argv[5];
    green = atof(m_str.c_str());
    m_str = argv[6];
    blue = atof(m_str.c_str());
    m_str = argv[7];
    lifetime = atof(m_str.c_str());
    m_str = argv[8];
    speed = atof(m_str.c_str());
    m_str = argv[9];
    size = atof(m_str.c_str());
    m_str = argv[10];
    if (m_str == "random")
        m_RndClr = true;
    else if (m_str == "colortrans")
        m_TrClr = true;
    if (m_TrClr) {
    m_str = argv[11];
    tr_red = (char)atoi(m_str.c_str());
    m_str = argv[12];
    tr_green = (char)atoi(m_str.c_str());
    m_str = argv[13];
    tr_blue = (char)atoi(m_str.c_str());
    m_str = argv[14];
    if (m_str == "accel")
        m_mouse_accel = true;
    else if (m_str == "decel")
        m_mouse_decel = true;
    }
    else {
        m_str = argv[11];
    if (m_str == "accel")
        m_mouse_accel = true;
    else if (m_str == "decel")
        m_mouse_decel = true;
    }


    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glPointSize(size);
    glutReshapeFunc( resizeWindow );
    mouse_n.setParticle(number, length, red, green, blue, lifetime, speed, size);
    glutPassiveMotionFunc(setmouseMovement);
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);

    glutMainLoop();

    
    }

return 0;
}
