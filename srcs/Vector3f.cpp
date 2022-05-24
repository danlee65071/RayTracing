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

Vector3f &Vector3f::operator=(const Vector3f& other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
		this->_z = other._z;
	}
	return *this;
}

void Vector3f::PrintParams() const
{
	std::cout << "Vector:\n";
	std::cout << "x: " << this->_x << std::endl;
	std::cout << "y: " << this->_y << std::endl;
	std::cout << "z: " << this->_z << std::endl;
}

Vector3f Vector3f::operator-(const Vector3f &other) const
{
	Vector3f res;

	res._x = this->_x - other._x;
	res._y = this->_y - other._y;
	res._z = this->_z - other._z;
	return res;
}

float Vector3f::dot(const Vector3f &other) const
{
	return (this->_x * other._x + this->_y * other._y + this->_z * other._z);
}
