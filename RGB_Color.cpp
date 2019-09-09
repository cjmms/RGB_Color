
#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "stdio.h"
#include <stdlib.h>


double side_length = 0.5;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();	
	
	// front
	glBegin(GL_POLYGON);
  	glColor3f( 1.0, 0.0, 1.0 );     glVertex3f(  side_length, -1 * side_length, -1 * side_length );      
  	glColor3f( 1.0, 1.0, 1.0 );     glVertex3f(  side_length,  side_length, -1 * side_length );      
  	glColor3f( 0.0, 1.0, 1.0 );     glVertex3f( -1 * side_length,  side_length, -1 * side_length );     
  	glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );      
	glEnd();

  	// White side  BACK
  	glBegin(GL_POLYGON);
  	glColor3f(   1.0,  1.0, 1.0 );
  	glVertex3f(  side_length, -1 * side_length, side_length );
  	glVertex3f(  side_length,  side_length, side_length );
  	glVertex3f( -1 * side_length,  side_length, side_length );
  	glVertex3f( -1 * side_length, -1 * side_length, side_length );
  	glEnd();
 
  	// Purple side  RIGHT
  	glBegin(GL_POLYGON);
  	glColor3f(  1.0,  0.0,  1.0 );
  	glVertex3f( side_length, -1 * side_length, -1 * side_length );
  	glVertex3f( side_length,  side_length, -1 * side_length );
  	glVertex3f( side_length,  side_length,  side_length );
  	glVertex3f( side_length, -1 * side_length,  side_length );
  	glEnd();
 
  	// Green side  LEFT
  	glBegin(GL_POLYGON);
  	glColor3f(   0.0,  1.0,  0.0 );
  	glVertex3f( -1 * side_length, -1 * side_length,  side_length );
  	glVertex3f( -1 * side_length,  side_length,  side_length );
  	glVertex3f( -1 * side_length,  side_length, -1 * side_length );
  	glVertex3f( -1 * side_length, -1 * side_length, -1 * side_length );
  	glEnd();
 
  	// Blue side  TOP
  	glBegin(GL_POLYGON);
  	glColor3f(   0.0,  0.0,  1.0 );
  	glVertex3f(  side_length,  side_length,  side_length );
  	glVertex3f(  side_length,  side_length, -1 * side_length );
  	glVertex3f( -1 * side_length,  side_length, -1 * side_length );
  	glVertex3f( -1 * side_length,  side_length,  side_length );
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



