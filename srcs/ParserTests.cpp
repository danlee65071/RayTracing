//
// Created by Hazzea Charlsie on 5/19/22.
//

#include "Parser.hpp"

void Parser::testReadFile()
{
	for (auto& el: this->_vConfig)
		std::cout << el << std::endl;
}

void Parser::testParseAmbient()
{
	for (auto& el: this->_v_ambient)
	{
		if (el->key != "A") continue;
		std::cout << "key: " << el->key << std::endl;
		std::cout << "intensive: " << el->intensive << std::endl;
		std::cout << "color:\n";
		std::cout << "red: " << static_cast<int>(el->color.getRed()) << std::endl;
		std::cout << "green: " << static_cast<int>(el->color.getGreen()) << std::endl;
		std::cout << "blue: " << static_cast<int>(el->color.getBlue()) << std::endl;
	}
}

void Parser::testParseCamera()
{
	for (auto& el: this->_v_camera)
	{
		std::cout << "key: " << el->key << std::endl;
		std::cout << "coordinates:\n";
		std::cout << "x: " << el->coordinates.getX() << std::endl;
		std::cout << "y: " << el->coordinates.getY() << std::endl;
		std::cout << "z: " << el->coordinates.getZ() << std::endl;
		std::cout << "direction:\n";
		std::cout << "x: " << el->direction.getX() << std::endl;
		std::cout << "y: " << el->direction.getY() << std::endl;
		std::cout << "z: " << el->direction.getZ() << std::endl;
		std::cout << "fov: " << el->fov << std::endl;
	}
}

void Parser::testParseLight()
{
	for (auto& p: this->_v_ambient)
	{
		if (p->key != "L") continue;
		auto el = std::static_pointer_cast<s_light>(p);
		std::cout << "key: " << el->key << std::endl;
		std::cout << "coordinates:\n";
		std::cout << "x: " << el->coordinates.getX() << std::endl;
		std::cout << "y: " << el->coordinates.getY() << std::endl;
		std::cout << "z: " << el->coordinates.getZ() << std::endl;
		std::cout << "intensive: " << el->intensive << std::endl;
		std::cout << "color:\n";
		std::cout << "red: " << static_cast<int>(el->color.getRed()) << std::endl;
		std::cout << "green: " << static_cast<int>(el->color.getGreen()) << std::endl;
		std::cout << "blue: " << static_cast<int>(el->color.getBlue()) << std::endl;
	}
}

void Parser::testParseCylinder()
{
	for (auto& p: this->_v_figure)
	{
		if (p->key != "cy") continue;
		auto el = std::static_pointer_cast<s_cylinder>(p);
		std::cout << "key: " << el->key << std::endl;
		std::cout << "coordinates:\n";
		std::cout << "x: " << el->coordinates.getX() << std::endl;
		std::cout << "y: " << el->coordinates.getY() << std::endl;
		std::cout << "z: " << el->coordinates.getZ() << std::endl;
		std::cout << "orientation:\n";
		std::cout << "x: " << el->orientation.getX() << std::endl;
		std::cout << "y: " << el->orientation.getY() << std::endl;
		std::cout << "z: " << el->orientation.getZ() << std::endl;
		std::cout << "diameter: " << el->diameter << std::endl;
		std::cout << "height: " << el->height << std::endl;
		std::cout << "color:\n";
		std::cout << "red: " << static_cast<int>(el->color.getRed()) << std::endl;
		std::cout << "green: " << static_cast<int>(el->color.getGreen()) << std::endl;
		std::cout << "blue: " << static_cast<int>(el->color.getBlue()) << std::endl << std::endl;
	}
}

void Parser::testParseSphere()
{
	for (auto& p: this->_v_figure)
	{
		if (p->key != "sp") continue;
		auto el = std::static_pointer_cast<s_sphere>(p);
		std::cout << "key: " << el->key << std::endl;
		std::cout << "center:\n";
		std::cout << "x: " << el->center.getX() << std::endl;
		std::cout << "y: " << el->center.getY() << std::endl;
		std::cout << "z: " << el->center.getZ() << std::endl;
		std::cout << "diameter: " << el->diameter << std::endl;
		std::cout << "color:\n";
		std::cout << "red: " << static_cast<int>(el->color.getRed()) << std::endl;
		std::cout << "green: " << static_cast<int>(el->color.getGreen()) << std::endl;
		std::cout << "blue: " << static_cast<int>(el->color.getBlue()) << std::endl << std::endl;
	}
}

void Parser::testParsePlane()
{
	for (auto& p: this->_v_figure)
	{
		if (p->key != "pl") continue;
		auto el = std::static_pointer_cast<s_plane>(p);
		std::cout << "key: " << el->key << std::endl;
		std::cout << "coordinates:\n";
		std::cout << "x: " << el->coordinates.getX() << std::endl;
		std::cout << "y: " << el->coordinates.getY() << std::endl;
		std::cout << "z: " << el->coordinates.getZ() << std::endl;
		std::cout << "direction:\n";
		std::cout << "x: " << el->direction.getX() << std::endl;
		std::cout << "y: " << el->direction.getY() << std::endl;
		std::cout << "z: " << el->direction.getZ() << std::endl;
		std::cout << "color:\n";
		std::cout << "red: " << static_cast<int>(el->color.getRed()) << std::endl;
		std::cout << "green: " << static_cast<int>(el->color.getGreen()) << std::endl;
		std::cout << "blue: " << static_cast<int>(el->color.getBlue()) << std::endl << std::endl;
	}
}
