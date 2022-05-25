//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Scene.hpp"

void Scene::SetAmbient(const std::vector<std::shared_ptr<s_ambient>> &v)
{
	for (auto& el: v)
	{
		if (el->key == "A")
			this->_vAmbient.push_back(std::make_shared<Ambient>(*el));
		else
			this->_vAmbient.push_back(std::make_shared<Light>(dynamic_cast<s_light&>(*el)));
	}
}

const std::vector<std::shared_ptr<Ambient> > &Scene::getAmbientV() const
{
	return this->_vAmbient;
}

void Scene::SetCamera(const std::vector<std::shared_ptr<s_camera>> &v)
{
	for (auto& el: v)
		this->_vCamera.push_back(std::make_shared<Camera>(*el));
}

const std::vector<std::shared_ptr<Camera> > &Scene::getCameraV() const
{
	return this->_vCamera;
}

void Scene::SetFigure(const std::vector<std::shared_ptr<s_figure>> &v)
{
	for (auto& el: v)
	{
		if (el->key == "sp")
			this->_vFigure.push_back(std::make_shared<Sphere>(dynamic_cast<s_sphere&>(*el)));
//		else if (el->key == "cy")
//			this->_vFigure.push_back(std::make_shared<Cylinder>(dynamic_cast<s_cylinder&>(*el)));
//		else if (el->key == "pl")
//			this->_vFigure.push_back(std::make_shared<Plane>(dynamic_cast<s_plane&>(*el)));
	}
}

const std::vector<std::shared_ptr<AFigure> > &Scene::getFigureV() const
{
	return this->_vFigure;
}
