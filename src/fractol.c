#include <fractol.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_put_circle(t_circle circ, void *mlx, void *mlx_win, t_data *img, int color)
{
	double i = 0;
	int k = 0;
	while (circ.center.x && circ.center.y && k++ < 1000)
	{
		i += M_PI / 100;
		my_mlx_pixel_put(img, circ.center.x + sin(i) * circ.radius, circ.center.y + cos(i) * circ.radius, color);
		mlx_put_image_to_window(mlx, mlx_win, img->img, 10, 10);
	}
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int x = 5, y = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// while (x < 100)
	// {
	// 	my_mlx_pixel_put(&img, x++, y++, 0x00FF00);
	// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// }
	t_circle circ;
	circ.center.x = 100;
	circ.center.y = 100;
	circ.radius = 90;
	int color = 0x00FF00;
	// double i = 0;
	// int k = 0;
	// while (circ.center.x && circ.center.y && k++ < 10000)
	// {
	// 	i += M_PI / 1000;
	// 	my_mlx_pixel_put(&img, circ.center.x + sin(i) * circ.radius, circ.center.y + cos(i) * circ.radius, color);
	// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
	// }

	ft_put_circle(circ, mlx, mlx_win, &img, color);


	mlx_loop(mlx);

	// min.re = -2.0;
	// max.re = 2.0;
	// min.im = -2.0;
	// max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	// usleep();

	return 0;
}