//
// Created by Hazzea Charlsie on 5/20/22.
//

#ifndef RT_COLOR_HPP
#define RT_COLOR_HPP

#include <iostream>
#include <vector>

class Color
{
private:
	int	_r;
	int	_g;
	int	_b;
public:
	Color() = default;
	explicit Color(uint8_t r, uint8_t g, uint8_t b);
	Color& operator=(const Color& other);
	~Color() = default;

	void setColor(const std::vector<uint8_t>& color);
	[[nodiscard]] uint8_t getRed() const;
	[[nodiscard]] uint8_t getGreen() const;
	[[nodiscard]] uint8_t getBlue() const;

//	operators
public:
	[[nodiscard]] Color operator+(const Color& other) const;
	[[nodiscard]] Color& multNum(float num);

//	print params
public:
	void PrintParams() const;
};

#endif //RT_COLOR_HPP
