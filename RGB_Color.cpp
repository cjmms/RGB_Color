
#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "stdio.h"
#include <stdlib.h>


double side_length = 2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1, 1.0, 20.0);  // specify a viewing frustum
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	//glLoadIdentity();	
	
	// 
	glBegin(GL_POLYGON);
  	glColor3f( 1.0, 0.0, 1.0 );     glVertex3f(  side_length, -1 * side_length, -1 * side_length );      
  	glColor3f( 1.0, 1.0, 1.0 );     glVertex3f(  side_length,  side_length, -1 * side_length );      
  	glColor3f( 0.0, 1.0, 1.0 );     glVertex3f( -1 * side_length,  side_length, -1 * side_length );     
  	glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );      
	glEnd();

  	// Left
  	glBegin(GL_POLYGON);
  	glColor3f( 1.0, 0.0, 1.0 );		glVertex3f(  side_length, -1 * side_length, side_length );	
  	glColor3f( 1.0, 1.0, 1.0 );		glVertex3f(  side_length,  side_length, side_length );		// white
  	glColor3f( 0.0, 1.0, 1.0 );		glVertex3f( -1 * side_length,  side_length, side_length );
  	glColor3f( 0.0, 0.0, 1.0 );		glVertex3f( -1 * side_length, -1 * side_length, side_length );	// blue
  	glEnd();
 
  	// right
  	glBegin(GL_POLYGON);
  	glColor3f( 1.0, 0.0, 0.0 );		glVertex3f( side_length, -1 * side_length, -1 * side_length );
  	glColor3f( 1.0, 1.0, 0.0 );		glVertex3f( side_length,  side_length, -1 * side_length );
  	glColor3f( 1.0, 1.0, 1.0 );		glVertex3f( side_length,  side_length,  side_length );
  	glColor3f( 1.0, 0.0, 1.0 );		glVertex3f( side_length, -1 * side_length,  side_length );
  	glEnd();
 
  	// Green side  LEFT
  	glBegin(GL_POLYGON);
  	glColor3f(   0.0,  1.0,  0.0 );
  	glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glVertex3f( -1 * side_length,  side_length,  side_length );
  	glVertex3f( -1 * side_length,  side_length, -1 * side_length );
  	glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
 
  	// top
  	glBegin(GL_POLYGON);
  	glColor3f( 1.0, 1.0, 1.0 );		glVertex3f(  side_length,  side_length,  side_length );				// white
  	glColor3f( 1.0, 1.0, 0.0 );		glVertex3f(  side_length,  side_length, -1 * side_length );			// yellow
  	glColor3f( 0.0, 1.0, 0.0 );		glVertex3f( -1 * side_length,  side_length, -1 * side_length );		// green
  	glColor3f( 0.0, 1.0, 1.0 );		glVertex3f( -1 * side_length,  side_length,  side_length );			// green + blue
  	glEnd();
 
  	// Red side  BOTTOM
  	glBegin(GL_POLYGON);
  	glColor3f(   1.0,  0.0,  0.0 );
  	glVertex3f(  side_length, -1 * side_length, -1 * side_length );
  	glVertex3f(  side_length, -1 * side_length,  side_length );
  	glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
 
  	glFlush();
  	glutSwapBuffers();
}



int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("EVA");
	glEnable(GL_DEPTH_TEST);


	// register callback func
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}



