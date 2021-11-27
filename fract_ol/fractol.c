#include "fractol.h"

int	render_next_frame(t_data *img)
{
	mlx_key_hook(img->mlx_win, arrows, img);
	mlx_hook(img->mlx_win, 4, 0, scroll, img);
	mlx_hook(img->mlx_win, 2, 1L << 0, close_win, img);
	return (1);
}

void	draw_mandelbrot(void)
{
	t_data	img;

	img.name = 1;
	img.scale = 16.0;
	img.zoom = 1;
	img.precision = 100;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Mandelbrot!");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mandelbrot(img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

void	draw_julia(char *shape)
{
	t_data	img;

	set_shape_for_julia(&img, *shape);
	img.offset_x = 0.0;
	img.offset_y = 0.0;
	img.precision = 300;
	img.scale = 2;
	img.zoom = 1;
	img.name = 2;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Julia!");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	julia(img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

int	error_shape(char *shape)
{
	if (ft_strlen(shape) != 1)
		return (1);
	if ((*shape != '1' && *shape != '2'
			&& *shape != '3' && *shape != '4' && *shape != '5'))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && *argv[1] == '1')
		draw_mandelbrot();
	else if (argc == 3 && *argv[1] == '2' && !error_shape(argv[2]))
		draw_julia(argv[2]);
	else
	{
		printf("Please provide an argument after the executable:\n");
		printf("'1' for Mandelbrot set\n");
		printf("'2' for Julia set + 1-5 as second parameter\n");
	}
	return (1);
}
