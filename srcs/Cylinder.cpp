//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Cylinder.hpp"


Cylinder::Cylinder(const s_cylinder &cylinderParams)
{
	this->_key = cylinderParams.key;
	this->_center = cylinderParams.coordinates;
	this->_orientation = cylinderParams.orientation;
	this->_diameter = cylinderParams.diameter;
	this->_height = cylinderParams.height;
	this->_color = cylinderParams.color;
}

void Cylinder::PrintParams() const
{
	std::cout << "Cylinder class:\n";
	std::cout << "key: " << this->_key << std::endl;
	std::cout << "center:\n";
	this->_center.PrintParams();
	std::cout << "orientation:\n";
	this->_orientation.PrintParams();
	std::cout << "diameter: " << this->_diameter << std::endl;
	std::cout << "height: " << this->_height << std::endl;
	this->_color.PrintParams();
	std::cout << std::endl;
}
