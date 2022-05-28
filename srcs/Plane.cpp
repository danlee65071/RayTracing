//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Plane.hpp"


Plane::Plane(const s_plane &planeParams)
{
	this->_key = planeParams.key;
	this->_center = planeParams.coordinates;
	this->_n = planeParams.direction;
	this->_n.norm();
	this->_n.absVector();
	this->_color = planeParams.color;
	this->_specular = planeParams.specular;
}

void Plane::PrintParams() const
{
	std::cout << "Plane class:\n";
	std::cout << "key: " << this->_key << std::endl;
	std::cout << "coordinates:\n";
	this->_center.PrintParams();
	std::cout << "direction:\n";
	this->_n.PrintParams();
	this->_color.PrintParams();
	std::cout << "specular: " << this->_specular << std::endl;
	std::cout << std::endl;
}

std::pair<float, float>
Plane::intersectRay(const Vector3f &O, const Vector3f &D)
{
	std::pair<float, float> decision(std::numeric_limits<float>::infinity(), 1);
	Vector3f OC = O - this->_center;
	float k1 = OC.dot(this->_n);
	float k2 = D.dot(this->_n);
	if (k2 == 0) decision.first = 1;
	decision.first = -k1 / k2;
	return decision;
}
