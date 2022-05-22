//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Parser.hpp"

void Parser::_createScene()
{
	this->_scene.SetAmbient(this->_vAmbient);
	this->_scene.SetCamera(this->_vCamera);
	this->_scene.SetFigure(this->_vFigure);
}

const Scene& Parser::getScene() const
{
	return this->_scene;
}
