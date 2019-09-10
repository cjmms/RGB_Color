
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
double alpha = 0.3;

double polygonVertices[] = 
{
	20, 100, 0,
	40, 100, 0,
	60, 150, 0
};

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	// draw the white bar at the bottom of the screen
	glRectf(-1.0f,-1.0f, 1.0f, -0.9f);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	gluLookAt(	1.0, 1.0, 1.0, 
				0.0, 0.0, 0.0,
				0.0, 1.0, 0.0 );


	
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

	
 
  	glFlush();
  	glutSwapBuffers();
}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(480, 480);
	glutInitWindowPosition(400, 400);
	glutCreateWindow("RGB_Cube");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


	// register callback func
	glutDisplayFunc(display);


	// glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
	// glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

	// gluLookAt(	1.0, 1.0, 1.0, 
	// 			0.0, 0.0, 0.0,
	// 			0.0, 1.0, 0.0 );

	glutMainLoop();
	return 0;
}



