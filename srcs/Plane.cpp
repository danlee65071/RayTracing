//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Plane.hpp"


Plane::Plane(const s_plane &planeParams)
{
	this->_key = planeParams.key;
	this->_center = planeParams.coordinates;
	this->_direction = planeParams.direction;
	this->_color = planeParams.color;
}

void Plane::PrintParams() const
{
	std::cout << "Plane class:\n";
	std::cout << "key: " << this->_key << std::endl;
	std::cout << "coordinates:\n";
	this->_center.PrintParams();
	std::cout << "direction:\n";
	this->_direction.PrintParams();
	this->_color.PrintParams();
	std::cout << std::endl;
}
