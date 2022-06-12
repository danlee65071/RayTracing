//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Camera.hpp"

Camera::Camera(const s_camera &cameraParams)
{
	this->_key = cameraParams.key;
	this->_coordinates = cameraParams.coordinates;
	this->_direction = cameraParams.direction;
	this->_direction.norm();
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

const Vector3f &Camera::getCoordinates() const
{
	return this->_coordinates;
}

const Vector3f &Camera::getDirection() const
{
	return this->_direction;
}

void Camera::setCoordinates(float x, float y, float z)
{
	this->_coordinates.setX(x);
	this->_coordinates.setY(y);
	this->_coordinates.setZ(z);
}

void Camera::setCoordinateX(float x)
{
	this->_coordinates.setX(x);
}

void Camera::setCoordinateY(float y)
{
	this->_coordinates.setY(y);
}

void Camera::setCoordinateZ(float z)
{
	this->_coordinates.setZ(z);
}

void Camera::setDirection(float x, float y, float z)
{
	this->_direction.setX(x);
	this->_direction.setY(y);
	this->_direction.setZ(z);
	this->_direction.norm();
}
