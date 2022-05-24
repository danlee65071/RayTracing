//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_CYLINDER_HPP
#define RT_CYLINDER_HPP

#include "AFigure.hpp"

class Cylinder: public AFigure
{
private:
	Vector3f	_orientation{};
	float		_diameter{};
	float 		_height{};
public:
	Cylinder() = default;
	explicit Cylinder(const s_cylinder& cylinderParams);
	~Cylinder() override = default;

//	print params
public:
	void PrintParams() const override;
};
#endif //RT_CYLINDER_HPP
