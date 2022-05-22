//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_AMBIENT_HPP
#define RT_AMBIENT_HPP

#include <iostream>
#include "Color.hpp"
#include "utils.hpp"

class Ambient
{
protected:
	std::string	_key{};
	float		_intensive{};
	Color		_color{};
public:
	Ambient() = default;
	explicit Ambient(const s_ambient& ambientParams);
	~Ambient() = default;

//	get params
public:
	[[nodiscard]] const std::string& getKey() const;
	[[nodiscard]] float getIntensive() const;
	[[nodiscard]] const Color& getColor() const;

//	print params
public:
	virtual void PrintParams() const;
};

#endif //RT_AMBIENT_HPP
