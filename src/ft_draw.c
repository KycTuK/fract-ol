#include "fractol.h"

void	ft_mlx_pixel_put(t_data *data, t_point *pixel)
{
	char	*dst;

	dst = data->addr + (\
			(int)pixel->y * data->line_length +\
			(int)pixel->x * (data->bits_per_pixel / 8)\
		);
	*(unsigned int*)dst = pixel->color;
}

void	ft_mlx_draw_pixel(t_frame *fr, t_point *pixel)
{
	ft_mlx_pixel_put(&fr->data, pixel);
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->data.img.ptr, 0, 0);
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

// static void	ft_init_mlx_win_img(t_fract *fract)
// {
// 	fract->mlx_ptr = mlx_init();
// 	fract->win_ptr = mlx_new_window(fract->mlx_ptr,	WIDTH + WIDTH / 3, WIDTH, "");
// 	fract->img = mlx_new_image(fract->mlx_ptr, WIDTH, WIDTH);
// 	fract->img_ptr = mlx_get_data_addr(fract->img, &fract->bpp, &fract->sl, &fract->endian);
// 	ft_menu(fract);
// 	calc_fract(fract);
// 	mlx_mouse_hook(fract->win_ptr, mouse_hook, fract);
// 	mlx_key_hook(fract->win_ptr, key_hook, fract);
// 	mlx_loop(fract->mlx_ptr);
// }

// typedef struct s_fract
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*img;
// 	void	*img_ptr;
// 	int		name;
// 	double	y0;
// 	double	x0;
// 	double	i;
// 	double	re;	
// 	int		iter;
// 	int		color_plus;
// 	int		color_x;	
// 	int		bpp;
// 	int		sl;
// 	int		endian;
// 	double	zoom;
// }				t_fract;