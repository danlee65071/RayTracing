//
// Created by Hazzea Charlsie on 5/28/22.
//

#ifndef RT_QUATERNIONS_HPP
#define RT_QUATERNIONS_HPP

#include <iostream>
#include <cmath>
#include "Vector3f.hpp"

class Quaternion
{
private:
	float		_s{};
	Vector3f	_v;
public:
	Quaternion() = default;
	explicit Quaternion(float s, const Vector3f& v);
	~Quaternion() = default;

//	operators
public:
	Quaternion& operator=(const Quaternion& other);
	[[nodiscard]]Quaternion operator+(const Quaternion& other) const;
	[[nodiscard]]Quaternion operator-(const Quaternion& other) const;
	[[nodiscard]]Quaternion operator*(const Quaternion& other) const;
	void multNum(float n);
	[[nodiscard]]Quaternion getConjugate() const;
	[[nodiscard]]float getNorma() const;
	void normalization();
	[[nodiscard]]Quaternion getInverse() const;
	[[nodiscard]]Vector3f rotateVector(const Vector3f& v) const;
};

#endif //RT_QUATERNIONS_HPP
