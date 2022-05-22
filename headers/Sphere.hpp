//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_SPHERE_HPP
#define RT_SPHERE_HPP

#include "IFigure.hpp"

class Sphere: public IFigure
{
private:
	float	_diameter{};
public:
	Sphere() = default;
	explicit Sphere(const s_sphere& sphereParams);
	~Sphere() override = default;

//	print params
public:
	void PrintParams() const override;
};

#endif //RT_SPHERE_HPP