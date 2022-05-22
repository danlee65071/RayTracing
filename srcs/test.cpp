//
// Created by Hazzea Charlsie on 5/22/22.
//

#include "../mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void myMlxPixePut(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
//	s.rendering();

	void		*mlx;
	void		*mlx_win;
	t_data		img;
	int winWidth = 700;
	int winHeight = 700;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, winWidth, winHeight,(char*)"RT");
	img.img = mlx_new_image(mlx, winWidth, winHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								 &img.line_length, &img.endian);
//	rendering
	myMlxPixePut(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}