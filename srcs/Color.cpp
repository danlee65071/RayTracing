//
// Created by Hazzea Charlsie on 5/20/22.
//

#include "Color.hpp"

Color::Color(uint8_t r, uint8_t g, uint8_t b): _r(r), _g(g), _b(b) {}

void Color::setColor(const std::vector<uint8_t>& color)
{
	this->_r = color[0];
	this->_g = color[1];
	this->_b = color[2];
}

uint8_t Color::getRed() const
{
	return this->_r;
}

uint8_t Color::getGreen() const
{
	return this->_g;
}

uint8_t Color::getBlue() const
{
	return this->_b;
}
