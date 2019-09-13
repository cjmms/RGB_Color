
#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

#define SCALE 0
#define FIXED 1


double side_length = 2.0;	// side length of cube
double screenWidth = 500;
double screenHeight = 500;
double color_value =  1.0;	
double x_offset = 8.5;	// x offset to move slider
double z_offset = 0;	// z offset to move slider
double rec_offset = 8.5;	// original position for slider
GLfloat pixels[3];
//GLfloat hsv[3];
int color_win;
string title;

bool isFixed = false;		// cube state



typedef struct hsv{
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1
} hsv;

	

void drawCube() {
	// OK
	glBegin(GL_POLYGON);
  	glColor3f( color_value, 0.0, 0.0 );     		glVertex3f(  side_length, -1 * side_length, -1 * side_length );      
  	glColor3f( color_value, color_value, 0.0 );     glVertex3f(  side_length,  side_length, -1 * side_length );      
  	glColor3f( 0.0, color_value, 0.0);     			glVertex3f( -1 * side_length,  side_length, -1 * side_length );     
  	glColor3f( 0.0, 0.0, 0.0 );     				glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );      
	glEnd();

  	// Left
  	glBegin(GL_POLYGON);
  	glColor3f( color_value, 0.0, color_value);				glVertex3f(  side_length, -1 * side_length, side_length );	
  	glColor3f( color_value, color_value, color_value);		glVertex3f(  side_length,  side_length, side_length );		// white
  	glColor3f( 0.0, color_value, color_value);				glVertex3f( -1 * side_length,  side_length, side_length );
  	glColor3f( 0.0, 0.0, color_value);						glVertex3f( -1 * side_length, -1 * side_length, side_length );	// blue
  	glEnd();
 
  	// right
  	glBegin(GL_POLYGON);
  	glColor3f( color_value, 0.0, 0.0);						glVertex3f( side_length, -1 * side_length, -1 * side_length );
  	glColor3f( color_value, color_value, 0.0);				glVertex3f( side_length,  side_length, -1 * side_length );
  	glColor3f( color_value, color_value, color_value);		glVertex3f( side_length,  side_length,  side_length );
  	glColor3f( color_value, 0.0, color_value);				glVertex3f( side_length, -1 * side_length,  side_length );
  	glEnd();
 
  	// Green side  LEFT	OK
  	glBegin(GL_POLYGON);
  	glColor3f( 0.0, 0.0, color_value);				glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glColor3f( 0.0, color_value, color_value);		glVertex3f( -1 * side_length,  side_length,  side_length );
  	glColor3f( 0.0, color_value, 0.0);				glVertex3f( -1 * side_length,  side_length, -1 * side_length );
  	glColor3f( 0.0, 0.0, 0.0);						glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
 
  	// top
  	glBegin(GL_POLYGON);
  	glColor3f( color_value, color_value, color_value);		glVertex3f(  side_length,  side_length,  side_length );				// white
  	glColor3f( color_value, color_value, 0.0);				glVertex3f(  side_length,  side_length, -1 * side_length );			// yellow
  	glColor3f( 0.0, color_value, 0.0);						glVertex3f( -1 * side_length,  side_length, -1 * side_length );		// green
  	glColor3f( 0.0, color_value, color_value);				glVertex3f( -1 * side_length,  side_length,  side_length );			// green + blue
  	glEnd();
 
  	// Red side  BOTTOM
  	glBegin(GL_POLYGON);
  	glColor3f( color_value, 0.0, 0.0);				glVertex3f(  side_length, -1 * side_length, -1 * side_length );
  	glColor3f( color_value, 0.0, color_value);		glVertex3f(  side_length, -1 * side_length,  side_length );
  	glColor3f( 0.0, 0.0, color_value);				glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glColor3f( 0.0, 0.0, 0.0);						glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
}


// draw the white bar at the bottom of the scree
void drawSlider() 
{
	glBegin(GL_POLYGON);
	glColor3f( 1, 1, 1);		
	glVertex3f( 0 , -2.3, rec_offset);		// top left
  	glVertex3f( 0 , -3.5, rec_offset );		// bottom left
	glVertex3f( x_offset, -3.5, z_offset );		// bottom right 
  	glVertex3f( x_offset, -2.3, z_offset );		// top right
  	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawCube();
	drawSlider();
 
  	glutSwapBuffers();
}



struct hsv rgb2hsv()
{
    struct hsv         out;
    double      min, max, delta;

    min = pixels[0] < pixels[1] ? pixels[0] : pixels[1];
    min = min  < pixels[2] ? min  : pixels[2];

    max = pixels[0] > pixels[1] ? pixels[0] : pixels[1];
    max = max  > pixels[2] ? max  : pixels[2];

    out.v = max;                                // v
    delta = max - min;
    if (delta < 0.00001)
    {
        out.s = 0;
        out.h = 0; // undefined, maybe nan?
        return out;
    }
    if( max > 0.0 ) { // NOTE: if Max is == 0, this divide would cause a crash
        out.s = (delta / max);                  // s
    } else {
        // if max is 0, then r = g = b = 0              
        // s = 0, h is undefined
        out.s = 0.0;
        out.h = NAN;                            // its now undefined
        return out;
    }
    if( pixels[0] >= max )                           // > is bogus, just keeps compilor happy
        out.h = ( pixels[1] - pixels[2] ) / delta;        // between yellow & magenta
    else
    if( pixels[1] >= max )
        out.h = 2.0 + ( pixels[2] - pixels[0] ) / delta;  // between cyan & yellow
    else
        out.h = 4.0 + ( pixels[0] - pixels[1] ) / delta;  // between magenta & cyan

    out.h *= 60.0;                              // degrees

    if( out.h < 0.0 )
        out.h += 360.0;

    return out;
}



void toString() 
{
	stringstream stream;
	stream << "RGB: ( " 
					<< std::fixed << std::setprecision(2) << pixels[0] << ", "
					<< std::fixed << std::setprecision(2) << pixels[1] << ", "
					<< std::fixed << std::setprecision(2) << pixels[2] << ") = ";

	hsv result = rgb2hsv();

	stream << "HSV: ( " 
					<< std::fixed << std::setprecision(2) << result.h << ", "
					<< std::fixed << std::setprecision(2) << result.s << ", "
					<< std::fixed << std::setprecision(2) << result.v << ") ";

	title =  stream.str();
}

void changeBackground() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor( pixels[0],  pixels[1],  pixels[2], 1.0);
	toString();
	glutSetWindowTitle(title.c_str());

  	glutSwapBuffers();
}

void showColor(int x, int y) 
{
	if (y < 475) {
	glReadBuffer( GL_FRONT );	// need this, otherwise it's black
    glReadPixels(x, screenHeight-y, 1, 1, GL_RGB, GL_FLOAT, pixels);
	glutSetWindow(color_win);
	changeBackground();
	}
}

void processNormalKeys(unsigned char key,int x,int y) 
{ 
    if(key==27) exit(0); 
} 

void processMenuEvents(int option)
{
	switch (option) {
	case SCALE:
		isFixed = false;
		break;
	case FIXED:
		isFixed = true;
		break;
	}
}

void createMenu() {
	int menu = glutCreateMenu(processMenuEvents);

	// add entries
	glutAddMenuEntry("Scale", SCALE);
	glutAddMenuEntry("Fixed", FIXED);

	// menu pops up when right button is pressed
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void processMouse(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (y >= 475)
		{	// click slider
			color_value = 1.0 * x / screenWidth;		// change color base on length of slider
			if (!isFixed) side_length = 1.0 * x / screenWidth * 2;				// change cube size
			x_offset = 1.0 * x * rec_offset / screenWidth ;		// move x value
			z_offset = rec_offset - x_offset;					// move z value
			display();
		} 
		else 
			showColor(x, y);
	} 
	else if (button == GLUT_LEFT_BUTTON && state != GLUT_DOWN) 
		if (y < 475) showColor(x, y);
}





void init() 
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	double clipping  = 6;
    glOrtho(-1 * clipping, clipping, -1 * clipping, clipping, -1 * clipping, clipping);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	gluLookAt(	side_length / 2, side_length / 2, side_length / 2, 
				0.0, 0.0, 0.0,
				0.0, side_length / 2, 0.0 );
}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	// win 1
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(screenHeight, screenWidth);
	glutInitWindowPosition(400, 400);
	glutCreateWindow("RGB_Cube");

	init();
	createMenu();

	// register callback func
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(processMouse);
	glutMotionFunc(showColor);

	// win 2
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(screenHeight, screenWidth);
	glutInitWindowPosition(1000, 400);
	color_win = glutCreateWindow("RGB_Cube!!!");
	init();
	glutDisplayFunc(changeBackground);

	glutMainLoop();
	return 0;
}