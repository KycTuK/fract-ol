#include "fractol.h"

int	key_hook(int keycode, t_frame *fr);
int mouse_hook(int button, int x, int y, t_frame *fr);


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