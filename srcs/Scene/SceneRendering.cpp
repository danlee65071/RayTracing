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
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Scene::_winWidth, Scene::_winHeight);
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
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	this->_aspectRatio = static_cast<float>(Scene::_winWidth) / Scene::_winHeight;
	this->_viewPortHeight = this->_viewPortWidth / this->_aspectRatio;
}

void Scene::_makeImage()
{
//	int c = 255;
//	_checkImage[0][0][0]=(GLubyte)c;
//	_checkImage[0][0][1]=(GLubyte)c;
//	_checkImage[0][0][2]=(GLubyte)c;

//	check count camera
	for (float x = -1; x <= 1;)
	{
		for (float y = -1; y <= 1;)
		{
			Vector3f D((x * this->_viewPortWidth) / 2, (y * this->_viewPortHeight) / 2, this->_distToViewPort);
			auto color = this->_traceRay(D);
			_checkImage[x][0][0]=(GLubyte)color.getRed();
			_checkImage[x][0][1]=(GLubyte)color.getGreen();
			_checkImage[x][0][2]=(GLubyte)color.getBlue();
			y += 2. / Scene::_winHeight;
		}
		x += 2. / Scene::_winWidth;
	}
}

void Scene::_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-0.5,-0.5);
	this->_makeImage();
	glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, this->_checkImage);
	glFlush();
}

void Scene::_setUpDisplayCallBack()
{
	::g_currentInstance = this;
	::glutDisplayFunc(::g_displayCallBack);
}

Color Scene::_traceRay(const Vector3f &D)
{
	std::shared_ptr<Camera> camera = std::static_pointer_cast<Camera>(_vCamera[0]);
	std::shared_ptr<AFigure> closest_shape = nullptr;
	float closest_t = std::numeric_limits<float>::infinity();

	for (auto& fig: this->_vFigure)
	{
		if (fig->getKey() != "sp") continue;
		auto decision = fig->intersectRay(camera->getCoordinates(), D);
		if (decision.first > 1 && decision.first < std::numeric_limits<float>::infinity() && decision.first < closest_t)
		{
			closest_t = decision.first;
			closest_shape = std::static_pointer_cast<AFigure>(fig);
		}
		if (decision.second > 1 && decision.second < std::numeric_limits<float>::infinity() && decision.second < closest_t)
		{
			closest_t = decision.second;
			closest_shape = std::static_pointer_cast<AFigure>(fig);
		}
	}
	if (closest_shape == nullptr)
		return Color(0, 0, 0);
	return closest_shape->getColor();
}
