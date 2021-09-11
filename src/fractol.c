#include "fractol.h"

int	key_hook(int keycode, t_frame *fr)
{
	printf("Hello from key_hook! %d\n", keycode);
	return (0);
}

int mouse_hook(int button, int x, int y, t_frame *fr)
{
	int k = __WINDOW_RESIZE_PREC___;
	printf("Hello from mouse_hook! b[%d] x[%d] y[%d]\n", button, x, y);
	if (button == 1)
	{
		if (x >= (fr->data.img.size.width - k) && (y < k || y >= (fr->data.img.size.height - k)) )
			printf("Catch resize try! b[%d] x[%d] y[%d]\n", button, x, y);
	}
	return (0);
}

int	ft_close(int keycode, t_frame *fr)
{
	// static keycode_prev;
	// if (keycode_prev)
	mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
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
	// t_vars	vars;
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
	rect.size.width = 300;
	rect.size.height = 300;
	rect.info.precision = 0.1;
	rect.info.color	=	0xFFBF00;
	
	// ft_put_circle(&fr, circ);
	// ft_put_rectangle(&fr, rect);

	// vars.mlx = fr.mlx_ptr;
	// vars.win = fr.win_ptr;
	mlx_key_hook(fr.win_ptr, key_hook, &fr);
	mlx_mouse_hook (fr.win_ptr, mouse_hook, &fr);
	mlx_hook(fr.win_ptr, KeyPress, __KeyPressMask__, ft_close, &fr);
	mlx_hook(fr.win_ptr, MotionNotify, __EnterWindowMask__, ft_enter_window, &fr);
	mlx_hook(fr.win_ptr, MotionNotify, __LeaveWindowMask__, ft_leave_window, &fr);

	mlx_loop(fr.mlx_ptr);

	// min.re = -2.0;
	// max.re = 2.0;
	// min.im = -2.0;
	// max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	// usleep();

	return 0;
}