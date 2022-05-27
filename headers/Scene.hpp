//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_SCENE_HPP
#define RT_SCENE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Ambient.hpp"
#include "Light.hpp"
#include "utils.hpp"
#include "Camera.hpp"
#include "AFigure.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include <limits>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

class Scene
{
//	vectors of objects
private:
	std::vector<std::shared_ptr<Ambient> >	_vAmbient;
	std::vector<std::shared_ptr<Camera> >	_vCamera;
	std::vector<std::shared_ptr<AFigure> >	_vFigure;

private:
	static const int						_winWidth{700};
	static const int						_winHeight{700};
	GLubyte									_checkImage[_winHeight][_winWidth][3]{};
	float									_distToViewPort{1};
	float									_aspectRatio{};
	float									_viewPortWidth{1};
	float									_viewPortHeight{};

public:
	Scene() = default;
	~Scene() = default;

//	rendering
public:
	void rendering(int argc, char** argv);
	void _display();
private:
	void _init();
	void _makeImage();
	void _setUpDisplayCallBack();
	[[nodiscard]] Color _traceRay(const Vector3f& D, int depth = 3);
	[[nodiscard]] Ambient _computeLightning(const Vector3f& P, const Vector3f& N, const Vector3f& V, float specular);
	[[nodiscard]] static Vector3f _reflectRay(const Vector3f& D, const Vector3f& N);
	[[nodiscard]] std::shared_ptr<AFigure> _closestIntersection(const Vector3f& O,
		const Vector3f& D, float& closest_t, float min = 1, float max = std::numeric_limits<float>::infinity());

//	set objects
public:
	void SetAmbient(const std::vector<std::shared_ptr<s_ambient> >& v);
	void SetCamera(const std::vector<std::shared_ptr<s_camera> >& v);
	void SetFigure(const std::vector<std::shared_ptr<s_figure> >& v);


//	get objects
public:
	[[nodiscard]] const std::vector<std::shared_ptr<Ambient> >& getAmbientV() const;
	[[nodiscard]] const std::vector<std::shared_ptr<Camera> >& getCameraV() const;
	[[nodiscard]] const std::vector<std::shared_ptr<AFigure> >& getFigureV() const;
};

#endif //RT_SCENE_HPP
