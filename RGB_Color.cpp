
#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "stdio.h"
#include <stdlib.h>






void display()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	//设置alpha通道透明度
	glEnable(GL_BLEND);  //开启混合模式
	glDisable(GL_DEPTH_TEST);  //关闭深度测试
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glColor4f(1,1,0,1); 
	glRectf(-0.5,-0.5,0.8,0.8);
	glFinish();


	glutSwapBuffers();

}



int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(480, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("EVA");


	// register callback func
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}