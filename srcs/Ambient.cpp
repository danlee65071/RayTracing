//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Ambient.hpp"

Ambient::Ambient(const s_ambient& ambientParams)
{
	this->_key = ambientParams.key;
	this->_intensive = ambientParams.intensive;
	this->_color = ambientParams.color;
}

void Ambient::PrintParams() const
{
	std::cout << "Ambient class:\n";
	std::cout << "key: " << this->_key << std::endl;
	std::cout << "intensive: " << this->_intensive << std::endl;
	this->_color.PrintParams();
	std::cout << std::endl;
}

const std::string &Ambient::getKey() const
{
	return this->_key;
}

float Ambient::getIntensive() const
{
	return this->_intensive;
}

const Color &Ambient::getColor() const
{
	return this->_color;
}
