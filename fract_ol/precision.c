#include "fractol.h"

void	more_precision(t_data *img)
{
	img->precision += 200;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	printf("Zoom x %.2f   ---  precision = %d\n", img->zoom, img->precision);
}

void	less_precision(t_data *img)
{
	img->precision -= 200;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	printf("Zoom x %.2f   ---  precision = %d\n", img->zoom, img->precision);
}
