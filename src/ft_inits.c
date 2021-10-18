#include "fractol.h"

static void	ft_init_fnbr(t_fnbr *f)
{
	f->sign = 1;
	f->dot = 0;
	f->k = 0;
	f->n = 0;
	f->j = 0;
}

static void	ft_init_julia(t_fract *fract, int argc, char **argv)
{
	t_fnbr	f;

	fract->x0 = 0;
	fract->color_plus = COLOR2;
	fract->i = 0.75;
	fract->re = -0.2;
	fract->name = JULIA;
	ft_init_fnbr(&f);
	if (argc > 2)
	{
		if (ft_fatoi(&f, argv[2]) == 1 )
		{
			f.i = f.n;
			if (argc > 3)
			{
				ft_init_fnbr(&f);
				if (ft_fatoi(&f, argv[3]) == 1)
					fract->re = f.n;
				fract->i = f.i;
			}
		}
	}
}

int	ft_init_fractal(t_fract *fract, int argc, char **argv)
{
	fract->y0			= 0;
	fract->x0			= 150;
	fract->name			= 0;
	fract->zoom			= 180;
	fract->color_plus	= COLOR1;
	fract->color_x		= 0;
	fract->iter			= 150;

	if (!ft_strcmp(argv[1], "j" ))
		ft_init_julia(fract, argc, argv);
	if (!ft_strcmp(argv[1], "m" ))
		fract->name = MANDELBROT;
	if (!ft_strcmp(argv[1], "b" ))
	{
		fract->name	= BROWNIAN;
		fract->zoom	= 7800;
		fract->x0	= 13600;
		fract->y0	= -235;
	}
	return (fract->name);
}

static void	ft_mlx_init(t_frame *fr)
{
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

void	ft_mlx_init_def(t_frame *fr, double width, double height, char *title)
{
	fr->win.size.width	= width + width / 3;
	fr->win.size.height	= height;
	fr->win.title		= title;

	fr->data.img.size.width		= width;
	fr->data.img.size.height	= height;

	fr->menu.lu_corner.x	= width + 20;
	fr->menu.lu_corner.y	= height / 5;
	fr->menu.lu_corner.z	= 20;
	fr->menu.lu_corner.color= 54321000;
	
	ft_mlx_init(fr);
	ft_menu(fr);

	calc_fract(fr);

	// t_circle circ;
	// ft_init_circle_def(&circ);
	// ft_put_circle(fr, &circ);
	
	// t_rectangle rect;
	// ft_init_rectangle_def(&rect);
	// ft_put_rectangle(fr, &rect);

	mlx_mouse_hook(fr->win_ptr, mouse_hook, fr);
	mlx_key_hook(fr->win_ptr, key_hook, fr);
	mlx_loop(fr->mlx_ptr);
}

