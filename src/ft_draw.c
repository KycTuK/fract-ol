#include "fractol.h"

void	ft_mlx_pixel_put(t_data *data, t_point *p)
{
	char	*dst;

	dst = data->addr + (\
			(int)p->y * data->line_length +\
			(int)p->x * (data->bits_per_pixel / 8)\
		);
	*(unsigned int*)dst = p->color;
}

void	ft_mlx_draw_pixel(t_frame *fr, t_point *p)
{
	ft_mlx_pixel_put(&fr->data, p);
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->data.img.ptr, 10, 10);
}

void	ft_mlx_init(t_frame *fr, int fr_width, int fr_height, char *fr_title)
{
	fr->data.img.size.width = fr_width;
	fr->data.img.size.height = fr_height;
	fr->data.img.title = fr_title;

	fr->win.size.width = fr_width;
	fr->win.size.height = fr_height;
	fr->win.title = fr_title;

	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, \
								 fr->win.size.width, \
								 fr->win.size.height, \
								 fr->win.title \
								 );
	fr->data.img.ptr = mlx_new_image(fr->mlx_ptr, \
									 fr->data.img.size.width, \
									 fr->data.img.size.height \
									 );
	fr->data.addr = mlx_get_data_addr(fr->data.img.ptr, \
										&fr->data.bits_per_pixel, \
										&fr->data.line_length, \
										&fr->data.endian);
}