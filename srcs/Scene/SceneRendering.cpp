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
//	check count camera
	for (float x = -1; x <= 1;)
	{
		for (float y = -1; y <= 1;)
		{
			Vector3f D((x * this->_viewPortWidth) / 2, (y * this->_viewPortHeight) / 2, this->_distToViewPort);
			auto color = this->_traceRay(D);

			int r = color.getRed();
			int g = color.getGreen();
			int b = color.getBlue();
			if (r > 255) { std::cout << r << std::endl; r = 255; }
			if (g > 255) { std::cout << g << std::endl; g = 255; }
			if (b > 255) { std::cout << b << std::endl; b = 255; }

			_checkImage[static_cast<int>(y * _winHeight / 2 + _winHeight / 2.)][static_cast<int>(x * _winWidth / 2 + _winWidth / 2.)][0]= r;
			_checkImage[static_cast<int>(y * _winHeight / 2 + _winHeight / 2.)][static_cast<int>(x * _winWidth / 2 + _winWidth / 2.)][1]= g;
			_checkImage[static_cast<int>(y * _winHeight / 2 + _winHeight / 2.)][static_cast<int>(x * _winWidth / 2 + _winWidth / 2.)][2]= b;
			y += 1. / Scene::_winHeight;
		}
		x += 1. / Scene::_winWidth;
	}
}

void Scene::_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-1, -1);
	this->_makeImage();
	glDrawPixels(Scene::_winWidth, Scene::_winHeight, GL_RGB, GL_UNSIGNED_BYTE, this->_checkImage);
	glFlush();
}

void Scene::_setUpDisplayCallBack()
{
	::g_currentInstance = this;
	::glutDisplayFunc(::g_displayCallBack);
}

Color Scene::_traceRay(const Vector3f &D, int depth)
{
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(*(this->_vCamera[0]));
	float closest_t = std::numeric_limits<float>::infinity();

	std::shared_ptr<AFigure> closest_shape = this->_closestIntersection(camera->getCoordinates(), D, closest_t);

	if (closest_shape == nullptr)
		return Color(0, 0, 0);
	Vector3f P(camera->getCoordinates() + D.multNum(closest_t));
	closest_shape->setN(P);
	auto light = this->_computeLightning(P, closest_shape->getNorm(), D.multNum(-1), closest_shape->getSpecular());
	auto color = (closest_shape->getColor() + light.getColor()).multNum(light.getIntensive());
	return color;
}

Ambient Scene::_computeLightning(const Vector3f& P, const Vector3f& N, const Vector3f& V, float specular)
{
	Ambient l{};

	for (auto& light: this->_vAmbient)
	{

		if (light->getKey() == "A")
			l = l + *light;
		else if (light->getKey() == "L")
		{
			auto L = std::static_pointer_cast<Light>(light)->getCoordinates() - P;

			float shadow_t = std::numeric_limits<float>::infinity();
			auto shadow_fig = this->_closestIntersection(P, L, shadow_t, 0.001, 1);
			if (shadow_fig != nullptr) continue;

			auto NdotL = N.dot(L);
			if (NdotL > 0)
			{
				l.setIntensive(l.getIntensive() * NdotL / (N.len() * L.len()));
				l = l + *light;
			}

			if (specular > 0.)
			{
				auto R = N.multNum(2 * N.dot(L)) - L;
				auto RDotV = R.dot(V);
				if (RDotV > 0)
					l.setIntensive(l.getIntensive() + (light->getIntensive() * powf(RDotV / (R.len() * V.len()), specular * 1000)));
			}
		}
	}
	return l;
}

Vector3f Scene::_reflectRay(const Vector3f& D, const Vector3f& N)
{
	return N.multNum(2 * N.dot(D)) - D;
}

std::shared_ptr<AFigure> Scene::_closestIntersection(const Vector3f &O, const Vector3f &D, float& closest_t, float min, float max)
{
	std::shared_ptr<AFigure> closest_shape = nullptr;

	for (auto& fig: this->_vFigure)
	{
		if (fig->getKey() != "sp" && fig->getKey() != "pl") continue; // delete
		auto decision = fig->intersectRay(O, D);
		if (decision.first > min && decision.first < max && decision.first < closest_t)
		{
			closest_t = decision.first;
			closest_shape = std::static_pointer_cast<AFigure>(fig);
		}
		if (decision.second > min && decision.second < max && decision.second < closest_t)
		{
			closest_t = decision.second;
			closest_shape = std::static_pointer_cast<AFigure>(fig);
		}
	}
	return closest_shape;
}

