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

extern "C"
void g_moveCamera(unsigned char key, int x, int y)
{
	Vector3f OVector;
	int sign = 1;

	(void)x;
	(void)y;
	if (key == 'w' || key == 's')
	{
		if (key == 's')
			sign = -1;
		OVector = g_currentInstance->getCameraV()[0]->getDirection().multNum(STEP_CAMERA * sign) + g_currentInstance->getCameraV()[0]->getCoordinates();
	}
	else if (key == 'a' || key == 'd')
	{
		Vector3f OY(0, 1, 0);
		Quaternion q(cosf(45 * M_PI / 180), OY.multNum(sinf(45 * M_PI / 180)));
		OVector = g_currentInstance->getCameraV()[0]->getDirection();
		OVector = q.rotateVector(OVector);
		if (key == 'd')
			sign = -1;
		OVector = OVector.multNum(STEP_CAMERA * sign) + g_currentInstance->getCameraV()[0]->getCoordinates();
	}
	else
		return;
	g_currentInstance->getCameraV()[0]->setCoordinates(OVector.getX(), OVector.getY(), OVector.getZ());
	g_currentInstance->_display();
}

extern "C"
void g_keyUp(int key, int x, int y)
{
//	Vector3f rotationVector;
//	int sign = 1;
//	(void)x;
//	(void)y;
//	if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
//	{
//		Vector3f OX(1, 0, 0);
//		if (key == GLUT_KEY_DOWN)
//			sign = -1;
//		Quaternion q(cosf(ANGLE_ROTATION_CAMERA * sign / 2), OX.multNum(sinf(ANGLE_ROTATION_CAMERA * sign / 2)));
//		rotationVector = q.rotateVector(g_currentInstance->getCameraV()[0]->getDirection());
//	}
//	else if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT)
//	{
//		Vector3f OY(0, 1, 0);
//		if (key == GLUT_KEY_RIGHT)
//			sign = -1;
//		Quaternion q(cosf(ANGLE_ROTATION_CAMERA * sign / 2), OY.multNum(sinf(ANGLE_ROTATION_CAMERA * sign / 2)));
//		rotationVector = q.rotateVector(g_currentInstance->getCameraV()[0]->getDirection());
//	}
//	else
//		return;
//	g_currentInstance->getCameraV()[0]->setDirection(rotationVector.getX(), rotationVector.getY(), rotationVector.getZ());
//	g_currentInstance->_display();
}

void Scene::rendering(int argc, char** argv)
{
//	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(Scene::_winWidth, Scene::_winHeight);
//	glutInitWindowPosition(0,0);
//	glutCreateWindow("RT");
//	this->_init();
//	this->_setUpDisplayCallBack();
//	glutMainLoop();

    glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GL_FALSE);
//    glfwInitHint(GLFW_COCOA_MENUBAR, GL_TRUE);
    glfwInitHint(GLFW_COCOA_MENUBAR, GL_FALSE);
    if (!glfwInit())
        PrintErrorAndExit("GLFW init error!");
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(Scene::_winWidth, Scene::_winHeight, "RT", monitor, NULL);
    if (!window)
        PrintErrorAndExit("Window init error!");
//    glfwMakeContextCurrent(window);
//    if (!gladLoadGL())
//        PrintErrorAndExit("GLAD load Gl failed!");
//
    auto time = static_cast<float>(glfwGetTime());
    float lastFramesPrint = time;
    float framesCount = 0;
    while (!glfwWindowShouldClose(window))
    {
        framesCount++;
        auto newTime = static_cast<float>(glfwGetTime());
        float deltaTime = newTime - time;
        time = newTime;
        if (newTime - lastFramesPrint > 1.0f)
        {
            std::cout << "FPS: " << framesCount << std::endl;
            lastFramesPrint = newTime;
            framesCount = 0;
        }
    }
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
	Vector3f OZ(0, 0, 1);
	float angle = this->_vCamera[0]->getDirection().getAngle(OZ);
	auto rotationAxis = OZ.product(this->_vCamera[0]->getDirection());
	Quaternion q(cos(angle / 2), rotationAxis.multNum(sin(angle / 2)));

	rotationAxis.norm();
	for (float x = -1; x <= 1;)
	{
		for (float y = -1; y <= 1;)
		{
			Vector3f D((x * this->_viewPortWidth) / 2, (y * this->_viewPortHeight) / 2, this->_distToViewPort);
			D = q.rotateVector(D);
			auto color = this->_traceRay(this->_vCamera[0]->getCoordinates(), D);

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
//	glClear(GL_COLOR_BUFFER_BIT);
//	glRasterPos2f(-1, -1);
//	this->_makeImage();
//	glDrawPixels(Scene::_winWidth, Scene::_winHeight, GL_RGB, GL_UNSIGNED_BYTE, this->_checkImage);
//	glFlush();
//	glutSwapBuffers();
}

void Scene::_setUpDisplayCallBack()
{
//	::g_currentInstance = this;
//	::glutDisplayFunc(::g_displayCallBack);
//	::glutKeyboardFunc(::g_moveCamera);
//	::glutSpecialFunc(g_keyUp);
}

Color Scene::_traceRay(const Vector3f& O, const Vector3f &D, int depth, float min, float max)
{
	float closest_t = INF;
	std::shared_ptr<AFigure> closest_shape = this->_closestIntersection(O, D, closest_t, min, max);

	if (closest_shape == nullptr)
		return Color(0, 0, 0);
	Vector3f P(O + D.multNum(closest_t));
	closest_shape->setN(P);
	auto light = this->_computeLightning(P, closest_shape->getNorm(), D.multNum(-1), closest_shape->getSpecular());
	auto color = (closest_shape->getColor() + light.getColor()).multNum(light.getIntensive());
	float r = closest_shape->getSpecular();
	if (depth <= 0 || r <= 0)
		return color;
	auto R = Scene::_reflectRay(D.multNum(-1), closest_shape->getNorm());
	Color reflectColor = this->_traceRay(P, R, depth - 1, EPSILON, INF);
	return color.multNum(1 - r) + reflectColor.multNum(r);
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

			float shadow_t = INF;
			auto shadow_fig = this->_closestIntersection(P, L, shadow_t, EPSILON, 1);
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

float Scene::getDistToViewPort() const
{
	return this->_distToViewPort;
}

float Scene::getWinWidth()
{
	return Scene::_winWidth;
}

float Scene::getWinHeight()
{
	return Scene::_winHeight;
}
