#include "fractol.h"

typedef struct s_julia
{
	int			x;
	int			y;
	double		c_x;
	double		c_y;
	int			iter;
	double		z_x;
	double		z_y;
	double		tmp;
}				t_julia;

static void	initialize(t_julia *j, t_data *img)
{
	j->x = 0;
	j->y = 0;
	j->c_x = img->c_x;
	j->c_y = img->c_y;
}

static void	set_z(t_julia *j, t_data *img)
{
	j->z_x = 1.0 * (j->x - WIDTH / 2) / (0.5 / img->scale * WIDTH)
		- img->offset_y / WIDTH;
	j->z_y = 1.0 * (j->y - HEIGHT / 2) / (0.5 / img->scale * HEIGHT)
		- img->offset_x / HEIGHT;
}

void	julia(t_data img)
{
	t_julia	j;

	initialize(&j, &img);
	while (j.y < HEIGHT)
	{
		while (j.x < WIDTH)
		{
			set_z(&j, &img);
			j.iter = 0;
			while (j.z_x * j.z_x + j.z_y * j.z_y < 4 && j.iter < img.precision)
			{
				j.tmp = j.z_x * j.z_x - j.z_y * j.z_y + j.c_x;
				j.z_y = 2.0 * j.z_x * j.z_y + j.c_y;
				j.z_x = j.tmp;
				j.iter++;
			}
			if (j.iter < img.precision)
				px(&img, j.y, j.x, RGB(j.iter * 2, j.iter * 4, j.iter));
			j.x++;
		}
		j.x = 0;
		j.y++;
	}
}

void	set_shape_for_julia(t_data *img, char shape)
{
	if (shape == '1')
	{
		img->c_x = -0.4;
		img->c_y = 0.6;
	}
	if (shape == '2')
	{
		img->c_x = -0.7269;
		img->c_y = 0.1889;
	}
	if (shape == '3')
	{
		img->c_x = 0.285;
		img->c_y = 0.01;
	}
	if (shape == '4')
	{
		img->c_x = -0.70176;
		img->c_y = -0.3842;
	}
	if (shape == '5')
	{
		img->c_x = -0.8;
		img->c_y = 0.156;
	}
}
