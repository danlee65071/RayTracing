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

Color &Color::operator=(const Color &other)
{
	if (this != &other)
	{
		this->_r = other._r;
		this->_g = other._g;
		this->_b = other._b;
	}
	return *this;
}

void Color::PrintParams() const
{
	std::cout << "color:\n";
	std::cout << "red: " << static_cast<int>(this->getRed()) << std::endl;
	std::cout << "green: " << static_cast<int>(this->getGreen()) << std::endl;
	std::cout << "blue: " << static_cast<int>(this->getBlue()) << std::endl;
}

Color Color::operator+(const Color& other) const
{
	Color res{};

	res._r = (this->_r + other._r) > 255 ? 255 : this->_r + other._r;
	res._g = (this->_g + other._g) > 255 ? 255 : this->_g + other._g;
	res._b = (this->_b + other._b) > 255 ? 255 : this->_b + other._b;
	return res;
}

Color& Color::multNum(float num)
{
	this->_r = static_cast<int>(static_cast<float>(this->_r) * num) > 255 ? 255 : static_cast<int>(static_cast<float>(this->_r) * num);
	this->_g = static_cast<int>(static_cast<float>(this->_g) * num) > 255 ? 255 : static_cast<int>(static_cast<float>(this->_g) * num);
	this->_b = static_cast<int>(static_cast<float>(this->_b) * num) > 255 ? 255 : static_cast<int>(static_cast<float>(this->_b) * num);
	return *this;
}
