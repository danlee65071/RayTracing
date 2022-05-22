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
#include "IFigure.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include "mlx.h"

class Scene
{
//	vectors of objects
private:
	std::vector<std::shared_ptr<Ambient> >	_vAmbient;
	std::vector<std::shared_ptr<Camera> >	_vCamera;
	std::vector<std::shared_ptr<IFigure> >	_vFigure;

//	mlx vars
private:
	void		*_mlx{};
	void		*_mlx_win{};
	t_data		_img{};
	int			_winWidth{};
	int			_winHeight{};

public:
	Scene() = default;
	~Scene() = default;

//	rendering
public:
	void rendering();
private:
	static void _myMlxPixePut(t_data *data, int x, int y, int color);

//	set objects
public:
	void SetAmbient(const std::vector<std::shared_ptr<s_ambient> >& v);
	void SetCamera(const std::vector<std::shared_ptr<s_camera> >& v);
	void SetFigure(const std::vector<std::shared_ptr<s_figure> >& v);


//	get objects
public:
	[[nodiscard]] const std::vector<std::shared_ptr<Ambient> >& getAmbientV() const;
	[[nodiscard]] const std::vector<std::shared_ptr<Camera> >& getCameraV() const;
	[[nodiscard]] const std::vector<std::shared_ptr<IFigure> >& getFigureV() const;
};


#endif //RT_SCENE_HPP
