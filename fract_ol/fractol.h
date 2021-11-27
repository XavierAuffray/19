#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	double	zoom;
	double	scale;
	double	offset_x;
	double	offset_y;
	int		precision;
	int		name;
	double	c_x;
	double	c_y;
}				t_data;

void			draw_vertical_line(t_data img, int x, int y, int length);
void			draw_horizontal_line(t_data img, int x, int y, int length);
void			draw_square(t_data img, int x, int y, int size);
void			draw_circle(t_data img, int x, int y, int radius);
void			draw_disk(t_data img, int x, int y, double radius);
void			px(t_data *data, int x, int y, int color);
void			mandelbrot(t_data img);
void			move_right(t_data *img);
void			move_left(t_data *img);
void			move_top(t_data *img);
void			move_bottom(t_data *img);
void			zoom(t_data *img);
void			unzoom(t_data *img);
void			more_precision(t_data *img);
void			less_precision(t_data *img);
void			set_shape_for_julia(t_data *img, char shape);
int				scroll(int roulette, int x, int y, t_data *img);
int				close_win(int key_code, t_data *img);
int				arrows(int key_code, t_data *img);
unsigned long	RGB(int r, int g, int b);
void			julia(t_data img);
size_t			ft_strlen(const char *str);

#endif