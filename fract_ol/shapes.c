#include "fractol.h"

void	draw_vertical_line(t_data img, int x, int y, int length)
{
	int	start;

	start = y;
	while (y < length + start)
	{
		px(&img, x, y, 0x00FF0000);
		y++;
	}
}

void	draw_horizontal_line(t_data img, int x, int y, int length)
{
	int	start;

	start = x;
	while (x < length + start)
	{
		px(&img, x, y, 0x00FF0000);
		x++;
	}
}

void	draw_square(t_data img, int x, int y, int size)
{
	draw_horizontal_line(img, x, y, size);
	draw_horizontal_line(img, x, y + size, size);
	draw_vertical_line(img, x, y, size);
	draw_vertical_line(img, x + size, y, size);
}

void	draw_circle(t_data img, int x, int y, int radius)
{
	double	x_start;
	double	y_start;

	x_start = 0;
	while (x_start < radius)
	{
		y_start = sqrt(pow(radius, 2) - pow(x_start, 2));
		px(&img, x_start + x, y_start + y, 0xFF8000);
		px(&img, x_start + x, y - y_start, 0xFF8000);
		px(&img, x_start * -1 + x, y_start + y, 0xFF8000);
		px(&img, x_start * -1 + x, y - y_start, 0xFF8000);
		x_start += 0.001;
	}
}

void	draw_disk(t_data img, int x, int y, double radius)
{
	double	x_start;
	double	y_start;

	while (radius > 0)
	{
		x_start = 0;
		while (x_start < radius)
		{
			y_start = sqrt(pow(radius, 2) - pow(x_start, 2));
			px(&img, x_start + x, y_start + y, 0xFF8000);
			px(&img, x_start + x, y - y_start, 0xFF8000);
			px(&img, x_start * -1 + x, y_start + y, 0xFF8000);
			px(&img, x_start * -1 + x, y - y_start, 0xFF8000);
			x_start += 0.001;
		}
		radius -= 1;
	}
}
