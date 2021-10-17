#include "fractol.h"

// long long int ft_get_bits(int n)
// {
// 	long long int b = 0;
// 	while (n)
// 	{
// 		b = b * 10 + (n & 1);
// 		n >>= 1;
// 	} 
// 	return b;
// }

void ft_get_bits(unsigned long long n)
{
	static unsigned long long ns;
	if (n)
	{
		if (!ns)
			ns = n;
		ft_get_bits(n >> 1);
		printf("%d",(int)(n & 1));
		if (n == ns)
		{
			printf("\n");
			ns = 0;
		}
	}
}

void	ft_menu(t_frame *fr)
{
	int	x;
	int	d;
	int	y;
	int	c;

	x = WIDTH + 5;
	y = 100;
	d = 20;
	c = 54321000;
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, x, y, c, "[ESC] or [ALT] + [W] : exit");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, x, y + d, c, "MOUSE   : zoom");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, x, y + 2 * d, c, "ARROWS  : move");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, x, y + 3 * d, c, "c v x z : move colors");
	mlx_string_put(fr->mlx_ptr, fr->win_ptr, x, y + 4 * d, c, "i       : add iter");
}

// static void	ft_black_screen(t_frame *fr)
// {
// 	t_point pxl;
// 	pxl.x = WIDTH - 1;
// 	pxl.y = 0;
// 	pxl.color = 0;

// 	while (pxl.y < WIDTH)
// 	{
// 		ft_mlx_pixel_put(&fr, &pxl);
// 		pxl.y++;
// 	}
// 	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->data.img.ptr, 0, 0);
// }

int ft_close(int keycode, t_frame *fr)
{
	static int keycode_prev;

	if (keycode == ESC)
		exit (0);
	// mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
	// else if (keycode == ALT)
	// 	printf("To close the window press [ESC] or [ALT] + [W];");
	else if (keycode == W_KEY && keycode_prev == ALT)
		exit (0);
	else
		keycode_prev = keycode;
	return (0);
}

int	ft_enter_window(int button, int x, int y, t_frame *fr)
{
	if (!x || x == fr->win.size.width || \
		!y || y == fr->win.size.height \
	)
	printf("Hello newer! b[%d] x[%d] y[%d]\n", button, x, y);
	return (0);
}

int	ft_leave_window(int button, int x, int y, t_frame *fr)
{
	if (!x || x == fr->win.size.width || \
		!y || y == fr->win.size.height \
	)
	printf("Bye newer! b[%d] x[%d] y[%d]\n", button, x, y);
	return (0);
}

int main(void)
{
	t_frame fr;


	ft_mlx_init(&fr, WIDTH + WIDTH / 3, WIDTH, "Fract-ol");

	t_circle circ;
	circ.center.x =	100;
	circ.center.y =	100;
	circ.radius =	90;
	circ.info.precision = 0.01;
	circ.info.color	=	0x00FF00;

	t_rectangle rect;
	rect.center.x = 500;
	rect.center.y = 500;
	rect.size.width = 300;
	rect.size.height = 300;
	rect.info.precision = 0.1;
	rect.info.color	=	0xFFBF00;
	
	ft_put_circle(&fr, circ);
	ft_put_rectangle(&fr, rect);

	// printf("bit = %lld\n", ft_get_bits(7));
	// ft_get_bits(0xFFFFFF);
	// ft_get_bits(0xFF000000);
	// printf("COLOR = %d\n", 54321000&0xFFFFFF);
	// vars.mlx = fr.mlx_ptr;
	// vars.win = fr.win_ptr;
	ft_menu(&fr);
	mlx_key_hook(fr.win_ptr, key_hook, &fr);
	mlx_mouse_hook (fr.win_ptr, mouse_hook, &fr);
	mlx_hook(fr.win_ptr, KeyPress, __KeyPressMask__, ft_close, &fr);
	// ft_black_screen(&fr);
	// mlx_hook(fr.win_ptr, MotionNotify, __EnterWindowMask__, ft_enter_window, &fr);
	// mlx_hook(fr.win_ptr, MotionNotify, __LeaveWindowMask__, ft_leave_window, &fr);
	mlx_loop(fr.mlx_ptr);

	// min.re = -2.0;
	// max.re = 2.0;
	// min.im = -2.0;
	// max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	// usleep();

	return 0;
}