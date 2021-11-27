#include "fractol.h"

typedef struct s_mandelbrot
{
	int		row;
	int		col;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	x_new;
	int		iter;
}				t_mandelbrot;

static void	initialize(t_mandelbrot *m, t_data *img)
{
	m->c_re = ((m->col - WIDTH / 2) * img->scale / WIDTH)
		- img->offset_x / WIDTH * 4.0;
	m->c_im = ((m->row - HEIGHT / 2) * img->scale / WIDTH)
		- img->offset_y / HEIGHT * 4.0;
	m->x = 0;
	m->y = 0;
	m->iter = 0;
}

void	mandelbrot(t_data img)
{
	t_mandelbrot	m;

	m.row = 0;
	m.col = 0;
	while (m.row < HEIGHT)
	{
		while (m.col < WIDTH)
		{
			initialize(&m, &img);
			while (m.x * m.x + m.y * m.y <= 4 && m.iter < img.precision)
			{
				m.x_new = m.x * m.x - m.y * m.y + m.c_re;
				m.y = 2 * m.x * m.y + m.c_im;
				m.x = m.x_new;
				m.iter++;
			}
			if (m.iter < img.precision)
				px(&img, m.col, m.row, RGB(m.iter / 2, m.iter * 5, m.iter));
			m.col++;
		}
		m.col = 0;
		m.row++;
	}
}
