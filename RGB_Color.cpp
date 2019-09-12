
#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "stdio.h"
#include <stdlib.h>


double side_length = 2.0;
double alpha = 1.0;
double screenWidth = 500; 
double recLength = screenWidth;	

void drawCube() {
	// OK
	glBegin(GL_POLYGON);
  	glColor4f( 1.0, 0.0, 0.0, alpha);     glVertex3f(  side_length, -1 * side_length, -1 * side_length );      
  	glColor4f( 1.0, 1.0, 0.0, alpha);     glVertex3f(  side_length,  side_length, -1 * side_length );      
  	glColor4f( 0.0, 1.0, 0.0, alpha);     glVertex3f( -1 * side_length,  side_length, -1 * side_length );     
  	glColor4f( 0.0, 0.0, 0.0, alpha);     glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );      
	glEnd();

  	// Left
  	glBegin(GL_POLYGON);
  	glColor4f( 1.0, 0.0, 1.0, alpha);		glVertex3f(  side_length, -1 * side_length, side_length );	
  	glColor4f( 1.0, 1.0, 1.0, alpha);		glVertex3f(  side_length,  side_length, side_length );		// white
  	glColor4f( 0.0, 1.0, 1.0, alpha);		glVertex3f( -1 * side_length,  side_length, side_length );
  	glColor4f( 0.0, 0.0, 1.0, alpha);		glVertex3f( -1 * side_length, -1 * side_length, side_length );	// blue
  	glEnd();
 
  	// right
  	glBegin(GL_POLYGON);
  	glColor4f( 1.0, 0.0, 0.0, alpha);		glVertex3f( side_length, -1 * side_length, -1 * side_length );
  	glColor4f( 1.0, 1.0, 0.0, alpha);		glVertex3f( side_length,  side_length, -1 * side_length );
  	glColor4f( 1.0, 1.0, 1.0, alpha);		glVertex3f( side_length,  side_length,  side_length );
  	glColor4f( 1.0, 0.0, 1.0, alpha);		glVertex3f( side_length, -1 * side_length,  side_length );
  	glEnd();
 
  	// Green side  LEFT	OK
  	glBegin(GL_POLYGON);
  	glColor4f( 0.0, 0.0, 1.0, alpha);		glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glColor4f( 0.0, 1.0, 1.0, alpha);		glVertex3f( -1 * side_length,  side_length,  side_length );
  	glColor4f( 0.0, 1.0, 0.0, alpha);		glVertex3f( -1 * side_length,  side_length, -1 * side_length );
  	glColor4f( 0.0, 0.0, 0.0, alpha);		glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
 
  	// top
  	glBegin(GL_POLYGON);
  	glColor4f( 1.0, 1.0, 1.0, alpha);		glVertex3f(  side_length,  side_length,  side_length );				// white
  	glColor4f( 1.0, 1.0, 0.0, alpha);		glVertex3f(  side_length,  side_length, -1 * side_length );			// yellow
  	glColor4f( 0.0, 1.0, 0.0, alpha);		glVertex3f( -1 * side_length,  side_length, -1 * side_length );		// green
  	glColor4f( 0.0, 1.0, 1.0, alpha);		glVertex3f( -1 * side_length,  side_length,  side_length );			// green + blue
  	glEnd();
 
  	// Red side  BOTTOM
  	glBegin(GL_POLYGON);
  	glColor4f( 1.0, 0.0, 0.0, alpha);		glVertex3f(  side_length, -1 * side_length, -1 * side_length );
  	glColor4f( 1.0, 0.0, 1.0, alpha);		glVertex3f(  side_length, -1 * side_length,  side_length );
  	glColor4f( 0.0, 0.0, 1.0, alpha);		glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glColor4f( 0.0, 0.0, 0.0, alpha);		glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
}


float recLengthConvert(double length) {
	if (length > screenWidth / 2)
	{
		return (length - (screenWidth / 2)) / (screenWidth / 2);
	} else if (length < 250) {
		return ((screenWidth / 2) - (length )) / (screenWidth / 2) * -1.0f;
	} else if (length == 250) {
		return 0;
	} else {
		return -2.0f;	// ERROR
	}
}

void drawRec() 
{
	glBegin(GL_POLYGON);
	double offset = 2.6;
  	glColor4f( 1.0, 1.0, 1.0, alpha);		
	glVertex3f( 0 - offset, -4.5, side_length + offset);		// top left
  	glVertex3f( 0 - offset, -5.5, side_length + offset );		// bottom left
	glVertex3f( side_length + offset, -5.5, 0 - offset );		// bottom right 
  	glVertex3f( side_length + offset, -4.5, 0 - offset );		// top right
  	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	gluLookAt(	1.0, 1.0, 1.0, 
				0.0, 0.0, 0.0,
				0.0, 1.0, 0.0 );

	drawCube();

	drawRec();

	// draw the white bar at the bottom of the screen
	//glRectf(-1.0f, -1.0f, recLengthConvert(recLength), -0.9f);
	
	//glRectf(-1.0f, -1.0f, recLengthConvert(recLength), -0.9f);
 
  	glutSwapBuffers();
}

void processNormalKeys(unsigned char key,int x,int y) 
{ 
    if(key==27) 
        exit(0); 
} 


void processMouse(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (y >= 475){
			printf("x: %d, y: %d\n", x, y);
			recLength = x;
			printf("conversion: %f\n", recLengthConvert(x));
			display();
		}
	} 
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, screenWidth);
	glutInitWindowPosition(400, 400);
	glutCreateWindow("RGB_Cube");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


	// register callback func
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(processMouse);


	glutMainLoop();
	return 0;
}