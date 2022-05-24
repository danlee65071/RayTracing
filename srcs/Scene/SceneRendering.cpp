//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Scene.hpp"

Scene*	g_currentInstance;

extern "C"
void g_displayCallBack()
{
	g_currentInstance->_display();
}

void Scene::rendering(int argc, char** argv)
{
	this->_winWidth = 700;
	this->_winHeight = 700;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(this->_winWidth, this->_winHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("RT");
	this->_init();
	this->_setUpDisplayCallBack();
	glutMainLoop();
}

void Scene::_init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	this->_makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void Scene::_makeCheckImage()
{
	int c;
	c = 255;
	_checkImage[0][0][0]=(GLubyte)c;
	_checkImage[0][0][1]=(GLubyte)c;
	_checkImage[0][0][2]=(GLubyte)c;
}

void Scene::_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0,0);
	glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, this->_checkImage);
	glFlush();
}

void Scene::_setUpDisplayCallBack()
{
	::g_currentInstance = this;
	::glutDisplayFunc(::g_displayCallBack);
}
