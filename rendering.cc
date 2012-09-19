#include<iostream>
#include "mouse.h"
using namespace std;
#include<fstream>
#include "graphix.h"
#include<png.h>
#include <cstdio>
#include <string.h>

bool m_RndClr_point = false;
bool m_RndClr_global = false;
bool m_RndClr_liniar = false;
bool m_RndClr_mouse = false;
bool m_point[31];
bool m_point_r[31];
bool m_point_rd[31];
bool m_point_accel = false;
bool m_point_decel = false;
bool m_global[31];
bool m_global_blk[31];
bool m_global_rain[31];
bool m_global_accel = false;
bool m_global_decel = false;
bool m_liniar[31];
bool m_liniar_accel = false;
bool m_liniar_decel = false;
bool m_mouse[31];
bool m_mouse_accel = false;
bool m_mouse_decel = false;
short nr_point = 0, nr_liniar = 0, nr_global = 0, nr_mouse = 0;
short start = 1;
const double Xmin = 0.0, Xmax = 1000.0;
const double Ymin = 0.0, Ymax = 1000.0;
point point_n[31];
global global_n[31];
liniar liniar_n[31];
mouse mouse_n[31];
char *texfile[31];
string evfile[31];
time_t start1,end1;
int length;
GLubyte *textureImage;
FILE *fp;
int fpsnr=0;


	bool loadPngImage(char *name, int &outWidth, int &outHeight, bool &outHasAlpha, GLubyte **outData) { 
	    png_structp png_ptr;
	    png_infop info_ptr;
	    unsigned int sig_read = 0;
	    if ((fp = fopen(name, "rb")) == NULL)
  return false;

	    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
	            NULL, NULL, NULL);
	 
	    if (png_ptr == NULL) {
	        fclose(fp);
	        return false;
	    }

	    info_ptr = png_create_info_struct(png_ptr);
	    if (info_ptr == NULL) {
	        fclose(fp);
	        png_destroy_read_struct(&png_ptr, png_infopp_NULL, png_infopp_NULL);
	        return false;
	    }

	    if (setjmp(png_jmpbuf(png_ptr))) {

	        png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
	        fclose(fp);

	        return false;
	    }

	    png_init_io(png_ptr, fp);

	    png_set_sig_bytes(png_ptr, sig_read);
	 

	    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, png_voidp_NULL);
	 
	    outWidth = info_ptr->width;
	    outHeight = info_ptr->height;
	    switch (info_ptr->color_type) {
	        case PNG_COLOR_TYPE_RGBA:
	            outHasAlpha = true;
	            break;
	        case PNG_COLOR_TYPE_RGB:
	            outHasAlpha = false;
	            break;
	        default:
	            
	            png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	            fclose(fp);
	            return false;
	    }
	    unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
	    *outData = (unsigned char*) malloc(row_bytes * outHeight);
	 
	    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
	 
	    for (int i = 0; i < outHeight; i++) {

	        memcpy(*outData+(row_bytes * (outHeight-1-i)), row_pointers[i], row_bytes);
	    }

	    png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
	fclose(fp);
	    return true;
	}

float m_xmouse_pos, m_ymouse_pos;
void setmouseMovement(int x, int y) {
    m_xmouse_pos = ((float)x / 800) * 1400 - 200;
    m_ymouse_pos = ((((float)y - 600) * -1) / 600) * 1000;
    glutPostRedisplay();
}

void MyDisplay_point_n(void) {
    
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        time (&end1);
      if (difftime (end1,start1)>=1) {
      cout<<fpsnr/30<<endl;
      fpsnr = 0;
      time (&start1);
      }
      else
      fpsnr++;

    for (int j = 0; j < nr_point; j++) {
    if (evfile[j] != "Null"){
        glLoadIdentity();
        glEnable(GL_TEXTURE_2D);

int width, height;
	    bool hasAlpha;
	    loadPngImage(texfile[j], width, height, hasAlpha, &textureImage);
	    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	    glTexImage2D(GL_TEXTURE_2D, 0, hasAlpha ? 4 : 3, width, height, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, textureImage);

	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glEnable(GL_TEXTURE_2D);
	    glShadeModel(GL_FLAT);
            glEnable(GL_POINT_SPRITE);
            glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
            glBegin(GL_POINTS);
if (m_point[j] == true)
        point_n[j].setPointMultipleUpdate();
    if (m_point_r[j] == true)
        point_n[j].setPointOneUpdate(length);
    if (m_point_rd[j] == true)
        point_n[j].setPointDoubleUpdate(length);
    if (m_point_accel == true)
        point_n[j].setAccel();
    if (m_point_decel == true)
        point_n[j].setDecel();
    if (m_global[j] == true)
        global_n[j].setUpdateRandomMov();
    if (m_global_blk[j] == true)
        global_n[j].setUpdateRandomBlink();
    if (m_global_rain[j] == true)
        global_n[j].setUpdateRain();
    if (m_global_accel == true)
        global_n[j].setAccel();
    if (m_global_decel == true)
        global_n[j].setDecel();
    if (m_mouse[j] == true)
        mouse_n[j].setMouseParticleUpdate(m_xmouse_pos, m_ymouse_pos);
    if (m_mouse_accel == true)
        mouse_n[j].setAccel();
    if (m_mouse_decel == true)
        mouse_n[j].setDecel();
    if (m_liniar[j] == true)
        liniar_n[j].setLiniarUpdate();
    if (m_liniar_accel == true)
        liniar_n[j].setAccel();
    if (m_liniar_decel == true)
        liniar_n[j].setDecel();


    if (point_n[j].setDelay() == 1 && point_n[j].setDuration() == 1) {
    if (m_point[j] == true || m_point_r[j] == true || m_point_rd[j] == true) {
        for (int i = 0; i < point_n[j].m_count; i++)
            glVertex2f((point_n[j].m_particles[i].m_xpos - 500) / 500, (point_n[j].m_particles[i].m_ypos - 500) / 500);
    }	
    }

    if (global_n[j].setDelay() == 1 && global_n[j].setDuration() == 1) {
    if (m_global[j] == true || m_global_blk[j] == true || m_global_rain[j] == true) {
        for (int i = 0; i < global_n[j].m_count; i++) 
            glVertex2f((global_n[j].m_particles_r[i].m_xpos - 500) / 500, (global_n[j].m_particles_r[i].m_ypos - 500) / 500);
    }
    }

    if (liniar_n[j].setDelay() == 1 && liniar_n[j].setDuration() == 1) {
    if (m_liniar[j] == true) {
        for (int i = 0; i < liniar_n[j].m_count; i++) 
            glVertex2f((liniar_n[j].m_particles_l[i].m_xpos - 500) / 500, (liniar_n[j].m_particles_l[i].m_ypos - 500) / 500);
    }
    }

    if (mouse_n[j].setDelay() == 1 && mouse_n[j].setDuration() == 1) {
    if (m_mouse[j] == true) {
        for (int i = 0; i < mouse_n[j].m_count; i++) 
            glVertex2f((mouse_n[j].m_particles_m[i].m_xpos - 500) / 500, (mouse_n[j].m_particles_m[i].m_ypos - 500) / 500);
    }
    }

            glEnd();
            glDeleteTextures(1,(GLuint*)textureImage);
            delete[] textureImage;
            glDisable(GL_POINT_SPRITE);
            glBindTexture(GL_TEXTURE_2D, 0);
            glDisable(GL_TEXTURE_2D);
}

else {
    glBegin(GL_POINTS);
    if (point_n[j].setDelay() == 1&& point_n[j].setDuration() == 1) {
    if (m_point[j] == true || m_point_r[j] == true || m_point_rd[j] == true)
        glColor3f(point_n[j].m_particles[0].m_red, point_n[j].m_particles[0].m_green, point_n[j].m_particles[0].m_blue);  
    }

    if (global_n[j].setDelay() == 1&& global_n[j].setDuration() == 1) {
    if (m_global[j] == true || m_global_blk[j] == true || m_global_rain[j] == true)
        glColor3f(global_n[j].m_particles_r[0].m_red, global_n[j].m_particles_r[0].m_green, global_n[j].m_particles_r[0].m_blue);
    }

    if (liniar_n[j].setDelay() == 1&& liniar_n[j].setDuration() == 1) {
    if (m_liniar[j] == true)
        glColor3f(liniar_n[j].m_particles_l[0].m_red, liniar_n[j].m_particles_l[0].m_green, liniar_n[j].m_particles_l[0].m_blue); 
    }

    if (mouse_n[j].setDelay() == 1&& mouse_n[j].setDuration() == 1) {
    if (m_mouse[j] == true)
        glColor3f(mouse_n[j].m_particles_m[0].m_red, mouse_n[j].m_particles_m[0].m_green, mouse_n[j].m_particles_m[0].m_blue);
    }


    if (m_point[j] == true)
        point_n[j].setPointMultipleUpdate();
    if (m_point_r[j] == true)
        point_n[j].setPointOneUpdate(length);
    if (m_point_rd[j] == true)
        point_n[j].setPointDoubleUpdate(length);
    if (m_point_accel == true)
        point_n[j].setAccel();
    if (m_point_decel == true)
        point_n[j].setDecel();
    if (m_global[j] == true)
        global_n[j].setUpdateRandomMov();
    if (m_global_blk[j] == true)
        global_n[j].setUpdateRandomBlink();
    if (m_global_rain[j] == true)
        global_n[j].setUpdateRain();
    if (m_global_accel == true)
        global_n[j].setAccel();
    if (m_global_decel == true)
        global_n[j].setDecel();
    if (m_mouse[j] == true)
        mouse_n[j].setMouseParticleUpdate(m_xmouse_pos, m_ymouse_pos);
    if (m_mouse_accel == true)
        mouse_n[j].setAccel();
    if (m_mouse_decel == true)
        mouse_n[j].setDecel();
    if (m_liniar[j] == true)
        liniar_n[j].setLiniarUpdate();
    if (m_liniar_accel == true)
        liniar_n[j].setAccel();
    if (m_liniar_decel == true)
        liniar_n[j].setDecel();
    if (m_RndClr_point == true)
        point_n[j].setRandomColor();
    if (m_RndClr_liniar == true)
        liniar_n[j].setRandomColor();
    if (m_RndClr_global == true)
        global_n[j].setRandomColor();
    if (m_RndClr_mouse == true)
        mouse_n[j].setRandomColor();

    if (point_n[j].setDelay() == 1 && point_n[j].setDuration() == 1) {
    if (m_point[j] == true || m_point_r[j] == true || m_point_rd[j] == true) {
        for (int i = 0; i < point_n[j].m_count; i++)
            glVertex2f(point_n[j].m_particles[i].m_xpos, point_n[j].m_particles[i].m_ypos);
    }	
    }

    if (global_n[j].setDelay() == 1 && global_n[j].setDuration() == 1) {
    if (m_global[j] == true || m_global_blk[j] == true || m_global_rain[j] == true) {
        for (int i = 0; i < global_n[j].m_count; i++) 
            glVertex2f(global_n[j].m_particles_r[i].m_xpos, global_n[j].m_particles_r[i].m_ypos);
    }
    }

    if (liniar_n[j].setDelay() == 1 && liniar_n[j].setDuration() == 1) {
    if (m_liniar[j] == true) {
        for (int i = 0; i < liniar_n[j].m_count; i++) 
            glVertex2f(liniar_n[j].m_particles_l[i].m_xpos, liniar_n[j].m_particles_l[i].m_ypos);
    }
    }

    if (mouse_n[j].setDelay() == 1 && mouse_n[j].setDuration() == 1) {
    if (m_mouse[j] == true) {
        for (int i = 0; i < mouse_n[j].m_count; i++) 
            glVertex2f(mouse_n[j].m_particles_m[i].m_xpos, mouse_n[j].m_particles_m[i].m_ypos);
    }
    }
}
    glEnd();
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
    time (&start1);
    float x, y;
    float (*coord)[2];
    float x1, y1, x2, y2;
    float red, green, blue;
    float lifetime, speed, size;
    int number, i;
    float del_time, dur_time;
    string m_str;
    for (i = 1; i < argc; i++) {
    ifstream file;
    file.open(argv[i]);
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "point") {
    m_point[nr_point] = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    x = atof(m_str.c_str());
    file>>m_str;
    y = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_point = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
        file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    point_n[nr_point].setParticle(number, x, y, red, green, blue, lifetime, speed, size, del_time,dur_time);
    nr_point++;

    
    }
    else if (m_str == "point_r") {
    m_point_r[nr_point] = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    x = atof(m_str.c_str());
    file>>m_str;
    y = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_point = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    length = atoi(m_str.c_str());
        file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    point_n[nr_point].setParticle(number, x, y, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;
    }
    else if (m_str == "point_rd") {
    m_point_rd[nr_point] = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    x = atof(m_str.c_str());
    file>>m_str;
    y = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_point = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    length = atoi(m_str.c_str());
        file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    point_n[nr_point].setParticle(number, x, y, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;
    }
    else if (m_str == "liniar") {
    m_liniar[nr_point] = true;
    coord = new float[2][2];
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    coord[0][0] = atof(m_str.c_str());
    file>>m_str;
    coord[0][1] = atof(m_str.c_str());
    file>>m_str;
    coord[1][0] = atof(m_str.c_str());
    file>>m_str;
    coord[1][1] = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_liniar = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
        file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    liniar_n[nr_point].setParticles(number, coord, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;

    }
    else if (m_str == "random") {
    m_global[nr_point] = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    x1 = atof(m_str.c_str());
    file>>m_str;
    y1 = atof(m_str.c_str());
    file>>m_str;
    x2 = atof(m_str.c_str());
    file>>m_str;
    y2 = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_global = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
        file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    global_n[nr_point].setParticle(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;

    }
    else if (m_str == "random_blk") {
    m_global_blk[nr_point] = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    x1 = atof(m_str.c_str());
    file>>m_str;
    y1 = atof(m_str.c_str());
    file>>m_str;
    x2 = atof(m_str.c_str());
    file>>m_str;
    y2 = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_global = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
        file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    global_n[nr_point].setParticle(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;
    }
    else if (m_str == "random_rain") {
    m_global_rain[nr_point] = true;	
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    x1 = atof(m_str.c_str());
    file>>m_str;
    y1 = atof(m_str.c_str());
    file>>m_str;
    x2 = atof(m_str.c_str());
    file>>m_str;
    y2 = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_global = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
        file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    global_n[nr_point].setParticle(number, x1, y1, x2, y2, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;
    }
    
    else if (m_str == "mouse") {
    float length;
    m_mouse[nr_point] = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    number = atoi(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    length = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    red = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    green = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    blue = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;;
    lifetime = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    speed = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    size = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "random")
        m_RndClr_mouse = true;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    if (m_str == "accel")
        m_point_accel = true;
    else if (m_str == "decel")
        m_point_decel = true;
        file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    file>>m_str;
    del_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    dur_time = atof(m_str.c_str());
    file>>m_str;
    file>>m_str;
    file>>m_str;
    texfile[nr_point] = (char*)m_str.c_str();
    evfile[nr_point] = m_str;
    mouse_n[nr_point].setParticle(number, length, red, green, blue, lifetime, speed, size, del_time, dur_time);
    nr_point++;

 }   file.close();
    }
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Particle System");    

    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glEnable( GL_DEPTH_TEST );
    glEnable (GL_BLEND); 
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    glPointSize(size);
    glutReshapeFunc( resizeWindow );
    glutPassiveMotionFunc(setmouseMovement);
    glutDisplayFunc(MyDisplay_point_n);   
    glutIdleFunc(MyDisplay_point_n);
    glutMainLoop();

return 0;
}
