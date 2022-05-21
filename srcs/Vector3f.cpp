//
// Created by Hazzea Charlsie on 5/20/22.
//

#include "Vector3f.hpp"

Vector3f::Vector3f(float x, float y, float z): _x(x), _y(y), _z(z) {}

void Vector3f::setVector3f(const std::vector<float>& v)
{
	this->_x = v[0];
	this->_y = v[1];
	this->_z = v[2];
}

float Vector3f::getX() const
{
	return this->_x;
}

float Vector3f::getY() const
{
	return this->_y;
}

float Vector3f::getZ() const
{
	return this->_z;
}
