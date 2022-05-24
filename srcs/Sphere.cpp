//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Sphere.hpp"


Sphere::Sphere(const s_sphere &sphereParams)
{
	this->_key = sphereParams.key;
	this->_center = sphereParams.center;
	this->_diameter = sphereParams.diameter;
	this->_color = sphereParams.color;
}

void Sphere::PrintParams() const
{
	std::cout << "Sphere class:\n";
	std::cout << "key: " << this->_key << std::endl;
	std::cout << "center:\n";
	this->_center.PrintParams();
	std::cout << "diameter: " << this->_diameter << std::endl;
	this->_color.PrintParams();
	std::cout << std::endl;
}

std::pair<float, float>
Sphere::intersectRay(const Vector3f &O, const Vector3f &D)
{
	std::pair<float, float> decision(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
	Vector3f OC = O - this->_center;
	float k1 = D.dot(D);
	float k2 = 2 * OC.dot(D);
	float k3 = OC.dot(OC) - powf(this->_diameter / 2, 2);
	float discriminant = powf(k2, 2) - 4 * k1 * k3;

	if (discriminant < 0)
		return decision;
	decision.first = (-k2 + sqrtf(discriminant)) / (2 * k1);
	decision.second = (-k2 - sqrtf(discriminant)) / (2 * k1);
	return decision;
}
