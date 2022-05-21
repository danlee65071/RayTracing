//
// Created by Hazzea Charlsie on 5/20/22.
//

#ifndef RT_UTILS_HPP
#define RT_UTILS_HPP

#include "Color.hpp"
#include "Vector3f.hpp"

struct s_ambient
{
	std::string	key;
	float		intensive;
	Color		color;
};

struct s_light: public s_ambient
{
	Vector3f	coordinates;
};

struct s_camera
{
	std::string	key;
	Vector3f	coordinates;
	Vector3f	direction;
	float		fov;
};

struct s_figure
{
	std::string	key;
	Color		color;
} ;

struct s_plane: public s_figure
{
	Vector3f	coordinates;
	Vector3f	direction;
};

struct s_sphere: public s_figure
{
	Vector3f	center;
	float		diameter;
};

struct s_cylinder: public s_figure
{
	Vector3f	coordinates;
	Vector3f	orientation;
	float		diameter;
	float 		height;
};

struct s_cone: public s_figure
{
};

#endif //RT_UTILS_HPP
