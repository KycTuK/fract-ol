#include "fractol.h"

// int	key_hook(int keycode, t_frame *fr)
// {
// 	static int keycode_prev;

// 	if (keycode == ESC)
// 		ft_close(0);
// 	else
// 	{
// 		printf("Hello from key_hook! %d\n", keycode);
// 		keycode_prev = keycode;
// 	}
// 	return (0);
// }

// int mouse_hook(int button, int x, int y, t_frame *fr)
// {
// 	int k = __WINDOW_RESIZE_PREC___;
// 	printf("Hello from mouse_hook! b[%d] x[%d] y[%d]\n", button, x, y);
// 	if (button == LEFT_KEY)
// 	{
// 		if (x >= (fr->data.img.size.width - k) && (y < k || y >= (fr->data.img.size.height - k)) )
// 			printf("Catch resize try! b[%d] x[%d] y[%d]\n", button, x, y);
// 	}
// 	return (0);
// }

void ft_close(char *message)
{
	if (message)
		printf("%s\n", message);
	exit (0);
}


static void	ft_black_screen(t_frame *fr)
{
	int width;
	int	y;

	width = __WIDTH__;
	y = 0;
	while (y < width)
		ft_mlx_pixel_put(&fr->data, width - 1, y++, 0);
	ft_mlx_draw_img(fr);
}

int	mouse_hook(int button, int x, int y, t_frame *fr)
{
	t_fract *fract;
	double	z;
	int width;
	
	fract = &fr->fract;
	z = 1.3;
	width = __WIDTH__;
	if (button == ZOOM_OUT)
	{
		fract->zoom	= fract->zoom * z;
		fract->x0	= fract->x0 - (x - width / 2 - fract->x0) * (z - 1);
		fract->y0	= fract->y0 - (width / 2 - y - fract->y0) * (z - 1);
	}
	else if (button == ZOOM_IN)
	{
		fract->zoom	= fract->zoom / z;
		fract->x0	= fract->x0 + (x - width / 2 - fract->x0) * (1 - 1 / z);
		fract->y0	= fract->y0 + (width / 2 - y - fract->y0) * (1 - 1 / z);
	}
	ft_black_screen(fr);
	calc_fract(fr);
	return (0);
}

int	key_hook(int keycode, t_frame *fr)
{
	t_fract *fract;
	fract = &fr->fract;

	if (keycode == ESC)
		ft_close(0);
	if (keycode == 8)
		fract->color_plus = COLOR1;
	if (keycode == 9)
		fract->color_plus = COLOR4;
	if (keycode == 34)
		fract->iter = fract->iter + 50;
	if (keycode == 6)
		fract->color_x = fract->color_x + 50;
	if (keycode == 7)
		fract->color_x = fract->color_x - 50;
	if (keycode == 126 || keycode == 125)
		fract->y0 = fract->y0 - 20 + 40 * (126 - keycode);
	if (keycode == 123)
		fract->x0 = fract->x0 - 20;
	if (keycode == 124)
		fract->x0 = fract->x0 + 20;
	ft_black_screen(fr);
	calc_fract(fr);
	return (0);
}
