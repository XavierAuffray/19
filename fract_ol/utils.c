#include "fractol.h"

void	px(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned long	RGB(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	close_win(int key_code, t_data *img)
{
	if (key_code == 53)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}
