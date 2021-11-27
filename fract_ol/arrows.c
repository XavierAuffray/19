#include "fractol.h"

int	arrows(int key_code, t_data *img)
{
	if (key_code == 123)
		move_right(img);
	else if (key_code == 124)
		move_left(img);
	else if (key_code == 126)
		move_bottom(img);
	else if (key_code == 125)
		move_top(img);
	else if (key_code == 69)
		zoom(img);
	else if (key_code == 78)
		unzoom(img);
	else if (key_code == 12)
		more_precision(img);
	else if (key_code == 13 && img->precision != 100)
		less_precision(img);
	return (1);
}

void	move_right(t_data *img)
{
	img->offset_x += img->scale * 10;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	move_left(t_data *img)
{
	img->offset_x -= img->scale * 10;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	move_bottom(t_data *img)
{
	img->offset_y += img->scale * 10;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	move_top(t_data *img)
{
	img->offset_y -= img->scale * 10;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
