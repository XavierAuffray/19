#include "fractol.h"

void	scroll_zoom(int x, int y, t_data *img)
{
	img->scale /= 1.2;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->offset_x = 500.0 - x + img->offset_x;
	img->offset_y = 500.0 - y + img->offset_y;
	img->zoom *= 1.2;
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	printf("Zoom x %.2f   ---  precision = %d\n", img->zoom, img->precision);
}

void	scroll_unzoom(t_data *img)
{
	img->scale *= 1.2;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->zoom /= 1.2;
	if (img->name == 1)
		mandelbrot(*img);
	else if (img->name == 2)
		julia(*img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	printf("Zoom x %.2f   ---  precision = %d\n", img->zoom, img->precision);
}

int	scroll(int roulette, int x, int y, t_data *img)
{
	if (roulette == 4)
		scroll_zoom(x, y, img);
	else if (roulette == 5)
		scroll_unzoom(img);
	return (1);
}
