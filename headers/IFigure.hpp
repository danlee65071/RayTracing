//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_IFIGURE_HPP
#define RT_IFIGURE_HPP

#include <iostream>
#include "utils.hpp"
#include "Vector3f.hpp"
#include "Color.hpp"

class IFigure
{
protected:
	std::string _key;
	Vector3f	_center;
	Color		_color;
public:
	virtual ~IFigure() = default;

//	print params
public:
	virtual void PrintParams() const = 0;
};

#endif //RT_IFIGURE_HPP
