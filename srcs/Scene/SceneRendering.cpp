//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "Scene.hpp"

void Scene::rendering()
{
	this->_winWidth = 700;
	this->_winHeight = 700;
	this->_mlx = mlx_init();
	this->_mlx_win = mlx_new_window(this->_mlx, this->_winWidth, this->_winHeight,(char*)"RT");
	this->_img.img = mlx_new_image(this->_mlx, this->_winWidth, this->_winHeight);
	this->_img.addr = mlx_get_data_addr(this->_img.img, &this->_img.bits_per_pixel,
									   &this->_img.line_length, &this->_img.endian);
//	rendering
	Scene::_myMlxPixePut(&this->_img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(this->_mlx, this->_mlx_win, this->_img.img, 0, 0);
	mlx_loop(this->_mlx);
}

void Scene::_myMlxPixePut(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
