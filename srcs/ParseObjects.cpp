//
// Created by Hazzea Charlsie on 5/21/22.
//

#include "Parser.hpp"

void Parser::_parseAmbient(const std::string &line)
{
	s_ambient	ambient;
	std::string strColor;

	this->_ssClear();
	this->_ss << line;
	this->_ss >> ambient.key;
	this->_ss >> ambient.intensive;
	this->_ss >> strColor;
	ambient.color.setColor(Parser::_parseParamsToVec<uint8_t>(strColor));
	this->_v_ambient.push_back(std::make_shared<s_ambient>(ambient));
}

void Parser::_parseCamera(const std::string &line)
{
	s_camera 	camera;
	std::string strCoordinate;
	std::string strDirection;

	this->_ssClear();
	this->_ss << line;
	this->_ss >> camera.key;
	this->_ss >> strCoordinate;
	camera.coordinates.setVector3f(Parser::_parseParamsToVec<float>(strCoordinate));
	this->_ss >> strDirection;
	camera.direction.setVector3f(Parser::_parseParamsToVec<float>(strDirection));
	this->_ss >> camera.fov;
	this->_v_camera.push_back(std::make_shared<s_camera>(camera));
}

void Parser::_parseLight(const std::string &line)
{
	auto light = std::make_shared<s_light>();
	std::string	strCoordinate;
	std::string strColor;

	this->_ssClear();
	this->_ss << line;
	this->_ss >> light->key;
	this->_ss >> strCoordinate;
	light->coordinates.setVector3f(Parser::_parseParamsToVec<float>(strCoordinate));
	this->_ss >> light->intensive;
	this->_ss >> strColor;
	light->color.setColor(Parser::_parseParamsToVec<uint8_t>(strColor));
	this->_v_ambient.push_back(std::static_pointer_cast<s_light>(light));
}

void Parser::_parseCylinder(const std::string &line)
{
	auto cylinder = std::make_shared<s_cylinder>();
	std::string	strCoordinate;
	std::string strColor;
	std::string strDirection;

	this->_ssClear();
	this->_ss << line;
	this->_ss >> cylinder->key;
	this->_ss >> strCoordinate;
	cylinder->coordinates.setVector3f(Parser::_parseParamsToVec<float>(strCoordinate));
	this->_ss >> strDirection;
	cylinder->orientation.setVector3f(Parser::_parseParamsToVec<float>(strDirection));
	this->_ss >> cylinder->diameter;
	this->_ss >> cylinder->height;
	this->_ss >> strColor;
	cylinder->color.setColor(Parser::_parseParamsToVec<uint8_t>(strColor));
	this->_v_figure.push_back(std::static_pointer_cast<s_cylinder>(cylinder));
}

void Parser::_parseSphere(const std::string &line)
{
	auto sphere = std::make_shared<s_sphere>();
	std::string	strCenter;
	std::string strColor;

	this->_ssClear();
	this->_ss << line;
	this->_ss >> sphere->key;
	this->_ss >> strCenter;
	sphere->center.setVector3f(Parser::_parseParamsToVec<float>(strCenter));
	this->_ss >> sphere->diameter;
	this->_ss >> strColor;
	sphere->color.setColor(Parser::_parseParamsToVec<uint8_t>(strColor));
	this->_v_figure.push_back(std::static_pointer_cast<s_sphere>(sphere));
}

void Parser::_parseCone(const std::string &line)
{

}

void Parser::_parsePlane(const std::string &line)
{
	auto plane = std::make_shared<s_plane>();
	std::string	strCoordinate;
	std::string strColor;
	std::string strDirection;

	this->_ssClear();
	this->_ss << line;
	this->_ss >> plane->key;
	this->_ss >> strCoordinate;
	plane->coordinates.setVector3f(Parser::_parseParamsToVec<float>(strCoordinate));
	this->_ss >> strDirection;
	plane->direction.setVector3f(Parser::_parseParamsToVec<float>(strDirection));
	this->_ss >> strColor;
	plane->color.setColor(Parser::_parseParamsToVec<uint8_t>(strColor));
	this->_v_figure.push_back(std::static_pointer_cast<s_plane>(plane));
}

template<class T>
std::vector<T> Parser::_parseParamsToVec(const std::string& str)
{
	std::stringstream		ss;
	std::string 			tmp;
	std::vector<T>			v;

	ss << str;
	try
	{
		while (std::getline(ss, tmp, ','))
			v.push_back(std::stof(tmp));
	}
	catch(...)
	{
		throw InvalidParameter();
	}
	if (v.size() < 3)
		throw TooLowParameters();
	else if (v.size() > 3)
		throw TooManyParameters();
	return v;
}
