#include "fractol.h"

void	ft_put_circle(t_frame *fr, t_circle circ)
{
	double i = 0;
	int k = 0;
	t_point p;
	p.color = circ.info.color;
	while (k++ < __MAX_K__)
	{
		i += M_PI * circ.info.precision;
		p.x = circ.center.x + sin(i) * circ.radius;
		p.y = circ.center.y + cos(i) * circ.radius;
		ft_mlx_draw_pixel(fr, &p);
	}
}
