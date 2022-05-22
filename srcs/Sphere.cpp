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
