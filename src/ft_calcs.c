#include "fractol.h"

static int	ft_inf_iter_j_m(double x, double y, t_fract *fract)
{
	int		n;
	double	buff;

	n = 0;
	while (n < fract->iter)
	{
		buff = x;
		x = x * x - y * y + fract->re;
		y = 2 * buff * y + fract->i;
		n++;
		if (sqrtf (x * x + y * y) > 1000)
			return (n);
	}
	return (0);
}

static int	ft_inf_iter_bs(double x, double y, t_fract *fract)
{
	int		n;
	double	buff;

	n = 0;
	while (n < fract->iter)
	{
		buff = x;
		x = x * x - y * y + fract->re;
		y = 2 * fabs (buff * y) + fract->i;
		n++;
		if (sqrtf (x * x + y * y) > 1000)
			return (n);
	}
	return (0);
}

static int	calc_fract_name(t_fract *fract, double x, double y)
{
	int	inf;

	if (fract->name == BROWNIAN)
	{
		fract->re = x;
		fract->i = y;
		inf = ft_inf_iter_bs(x, y, fract);
		return (inf * 10 - 4600 + fract->color_plus);
	}
	if (fract->name == MANDELBROT)
	{
		fract->re = x;
		fract->i = y;
	}
	inf = ft_inf_iter_j_m(x, y, fract);
	return ((2560 * 100 + fract->color_plus + fract->color_x) * inf);
}

void	calc_fract(t_frame *fr)
{
	double	x;
	double	y;
	double	delta;
	double	zoom;
	int		color;
	int		width;
	t_fract *fract;

	fract = &fr->fract;
	width = __WIDTH__;
	zoom = fract->zoom;
	delta = width / zoom / 1000;
	x = -width / zoom / 2 - fract->x0 / zoom;
	while (x < width / zoom / 2 - delta - fract->x0 / zoom)
	{
		y = -width / zoom / 2 + delta + fract->y0 / zoom;
		while (y < width / zoom / 2 - delta + fract->y0 / zoom)
		{
			color = calc_fract_name(fract, x, y);
			ft_mlx_pixel_put(&fr->data, x * zoom + width / 2 + fract->x0,
				   width / 2 + fract->y0 - y * zoom, color);
			y = y + delta;
		}
		x = x + delta;
	}
	ft_mlx_draw_img(fr);
}