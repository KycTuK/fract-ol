#include "fractol.h"

void	ft_mlx_draw_img(t_frame *fr)
{
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->data.img.ptr, 0, 0);
}

void	ft_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;
	if (x < 0 || y < 0 || y >= __HEIGHT__ || x >= __WIDTH__)
		return ;
	dst = data->addr + (\
			(int)y * data->line_length +\
			(int)x * (data->bits_per_pixel / 8)\
		);
	*(unsigned int*)dst = color;
}

void	ft_menu(t_frame *fr)
{
	t_point *m;
	
	m = &fr->menu.lu_corner;
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, m->x, m->y			\
					, m->color, "[ESC]   : exit");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, m->x, m->y + m->z		\
					, m->color, "MOUSE   : zoom");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, m->x, m->y + 2 * m->z	\
					, m->color, "ARROWS  : move");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, m->x, m->y + 3 * m->z	\
					, m->color, "c,v,x,z : move colors");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, m->x, m->y + 4 * m->z	\
					, m->color, "i       : add iter");
}