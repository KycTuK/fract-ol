#include "fractol.h"

void	ft_init_circle_def(t_circle *circ)
{
	circ->center.x			= 200;
	circ->center.y			= 200;
	circ->radius			= 150;
	circ->info.precision	= 0.001;
	circ->info.color		= 0x00FF00;
}

void	ft_put_circle(t_frame *fr, t_circle *circ)
{
	double i = 0;
	int k = 0;
	t_point p;
	p.color = circ->info.color;
	while (k++ < __MAX_K__)
	{
		i += M_PI * circ->info.precision;
		p.x = circ->center.x + sin(i) * circ->radius;
		p.y = circ->center.y + cos(i) * circ->radius;
		ft_mlx_pixel_put(&fr->data, p.x, p.y, p.color);
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->data.img.ptr, 0, 0);
}
