//
// Created by Hazzea Charlsie on 5/28/22.
//

#include "Quaternion.hpp"

Quaternion::Quaternion(float s, const Vector3f &v): _s{s}, _v(v) {}

Quaternion &Quaternion::operator=(const Quaternion &other)
{
	if (this != &other)
	{
		this->_s = other._s;
		this->_v = other._v;
	}
	return *this;
}

Quaternion Quaternion::operator+(const Quaternion &other) const
{
	Quaternion res;

	res._s = this->_s + other._s;
	res._v = this->_v + other._v;
	return res;
}

Quaternion Quaternion::operator-(const Quaternion &other) const
{
	Quaternion res;

	res._s = this->_s - other._s;
	res._v = this->_v - other._v;
	return res;
}

Quaternion Quaternion::operator*(const Quaternion &other) const
{
	Quaternion res;

	res._s = this->_s * other._s - this->_v.dot(other._v);
	res._v = other._v.multNum(this->_s) + this->_v.multNum(other._s) + this->_v.product(other._v);
	return res;
}

void Quaternion::multNum(float n)
{
	this->_s *= n;
	this->_v = this->_v.multNum(n);
}

Quaternion Quaternion::getConjugate() const
{
	Quaternion res;

	res._s = this->_s;
	res._v = this->_v.multNum(-1);
	return res;
}

float Quaternion::getNorma() const
{
	return sqrtf(powf(this->_s, 2) + powf(this->_v.getX(), 2) + powf(this->_v.getY(), 2) + powf(this->_v.getZ(), 2));
}

void Quaternion::normalization()
{
	float norma = this->getNorma();
	this->_s /= norma;
	this->_v = this->_v.multNum(1 / norma);
}

Quaternion Quaternion::getInverse() const
{
	Quaternion res = this->getConjugate();
	float norma = this->getNorma();

	res._s /= powf(norma, 2);
	res._v = res._v.multNum(1 / powf(norma, 2));
	return res;
}

Vector3f Quaternion::rotateVector(const Vector3f& v) const
{
	Quaternion inverse = this->getInverse();
	Quaternion p(0, v);
	Quaternion res = (*this) * p * inverse;
	return res._v;
}


