//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Light.hpp"

Light::Light(const s_light &lightParams): Ambient(lightParams)
{
	this->_coordinates = lightParams.coordinates;
}

const Vector3f &Light::getCoordinates() const
{
	return this->_coordinates;
}

void Light::PrintParams() const
{
	std::cout << "Light class:\n";
	std::cout << "key: " << this->_key << std::endl;
	this->_coordinates.PrintParams();
	std::cout << "intensive: " << this->_intensive << std::endl;
	this->_color.PrintParams();
	std::cout << std::endl;
}


