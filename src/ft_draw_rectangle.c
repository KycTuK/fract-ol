#include "fractol.h"

void	ft_rectangle_init(t_rectangle *rect)
{
	rect->min.x = rect->center.x - rect->size.width / 2;
	rect->min.y = rect->center.y - rect->size.height / 2;
	rect->max.x = rect->center.x + rect->size.width / 2;
	rect->max.y = rect->center.y + rect->size.height / 2;
}

void	ft_put_rectangle(t_frame *fr, t_rectangle rect)
{
	int k = 0;
	t_point p;
	p.color = rect.info.color;
	ft_rectangle_init(&rect);
 	p.x = rect.min.x;
	while (p.x < rect.max.x && k++ < __MAX_K__)
	{
		p.y = rect.min.y;
		ft_mlx_draw_pixel(fr, &p);
		p.y = rect.max.y;
		ft_mlx_draw_pixel(fr, &p);
		p.x += rect.info.precision;
	}
	k = 0;
	p.y = rect.min.y;
	while (p.y < rect.max.y && k++ < __MAX_K__)
	{
		p.x = rect.min.x;
		ft_mlx_draw_pixel(fr, &p);
		p.x = rect.max.x;
		ft_mlx_draw_pixel(fr, &p);
		p.y += rect.info.precision;
	}
}