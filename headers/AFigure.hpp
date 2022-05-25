//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_AFIGURE_HPP
#define RT_AFIGURE_HPP

#include <iostream>
#include "utils.hpp"
#include "Vector3f.hpp"
#include "Color.hpp"

class AFigure
{
protected:
	std::string _key;
	Vector3f	_center;
	Color		_color;
	Vector3f	_n;
public:
	virtual ~AFigure() = default;

public:
	[[nodiscard]] const std::string& getKey() const { return this->_key; };
	[[nodiscard]] const Color& getColor() const { return this->_color; };
	[[nodiscard]] virtual std::pair<float, float> intersectRay(const Vector3f& O, const Vector3f& D) = 0;
	[[nodiscard]] const Vector3f& getNorm() const { return this->_n; };

//	print params
public:
	virtual void PrintParams() const = 0;
};

#endif //RT_AFIGURE_HPP
