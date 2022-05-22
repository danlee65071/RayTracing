//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Camera.hpp"

Camera::Camera(const s_camera &cameraParams)
{
	this->_key = cameraParams.key;
	this->_coordinates = cameraParams.coordinates;
	this->_direction = cameraParams.direction;
	this->_fov = cameraParams.fov;
}

void Camera::PrintParams() const
{
	std::cout << "Camera class:\n";
	std::cout << "key: " << this->_key << std::endl;
	std::cout << "coordinates:\n";
	this->_coordinates.PrintParams();
	std::cout << "direction:\n";
	this->_direction.PrintParams();
	std::cout << "fov: " << this->_fov << std::endl;
	std::cout << std::endl;
}
