//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_SPHERE_HPP
#define RT_SPHERE_HPP

#include "AFigure.hpp"

class Sphere: public AFigure
{
private:
	float	_diameter{};
public:
	Sphere() = default;
	explicit Sphere(const s_sphere& sphereParams);
	~Sphere() override = default;

public:
	[[nodiscard]] virtual std::pair<float, float> intersectRay(const Vector3f& O, const Vector3f& D) override;

//	print params
public:
	void PrintParams() const override;
};

#endif //RT_SPHERE_HPP
