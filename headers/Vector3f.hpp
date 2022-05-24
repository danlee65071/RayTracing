//
// Created by Hazzea Charlsie on 5/20/22.
//

#ifndef RT_VECTOR3F_HPP
#define RT_VECTOR3F_HPP

#include <iostream>
#include <vector>
#include <cmath>

class Vector3f
{
private:
	float	_x{};
	float	_y{};
	float	_z{};
public:
	Vector3f() = default;
	explicit Vector3f(float x, float y, float z);
	Vector3f& operator=(const Vector3f& other);
	~Vector3f() = default;

	void setVector3f(const std::vector<float>& v);
	[[nodiscard]] float getX() const;
	[[nodiscard]] float getY() const;
	[[nodiscard]] float getZ() const;

//	operators
public:
	[[nodiscard]]Vector3f operator-(const Vector3f& other) const;
	[[nodiscard]]float dot(const Vector3f& other) const;
//	print params
public:
	void PrintParams() const;
};

#endif //RT_VECTOR3F_HPP
