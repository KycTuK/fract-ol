#include <fractol.h>

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

void	ft_rectangle_init(t_rectangle *rect)
{
	rect->min.x = rect->center.x - rect->width / 2;
	rect->min.y = rect->center.y - rect->height / 2;
	rect->max.x = rect->center.x + rect->width / 2;
	rect->max.y = rect->center.y + rect->height / 2;
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

void	ft_mlx_init(t_frame *fr, int fr_width, int fr_height, char *fr_title)
{
	fr->data.img.width = fr_width;
	fr->data.img.height = fr_height;
	fr->data.img.title = fr_title;

	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, fr_width, fr_height, fr_title);
	fr->data.img.ptr = mlx_new_image(fr->mlx_ptr, fr_width, fr_height);
	fr->data.addr = mlx_get_data_addr(fr->data.img.ptr, \
										&fr->data.bits_per_pixel, \
										&fr->data.line_length, \
										&fr->data.endian);
}

int main()
{
	t_frame fr;
	ft_mlx_init(&fr, 1920, 1080, "Hello world!");

	t_circle circ;
	circ.center.x =	100;
	circ.center.y =	100;
	circ.radius =	90;
	circ.info.precision = 0.01;
	circ.info.color	=	0x00FF00;

	t_rectangle rect;
	rect.center.x = 500;
	rect.center.y = 500;
	rect.width = 300;
	rect.height = 300;
	rect.info.precision = 0.1;
	rect.info.color	=	0xFFBF00;
	
	ft_put_circle(&fr, circ);
	ft_put_rectangle(&fr, rect);

	mlx_loop(fr.mlx_ptr);

	// min.re = -2.0;
	// max.re = 2.0;
	// min.im = -2.0;
	// max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	// usleep();

	return 0;
}