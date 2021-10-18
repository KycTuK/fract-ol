#include "fractol.h"

int main(int argc, char *argv[])
{
	t_frame frame;
	if (argc == 1)
		ft_close("First argument must be 'j' or 'm' or 'b'");
	else if (ft_init_fractal(&frame.fract, argc, argv))
		ft_mlx_init_def(&frame, __WIDTH__, __HEIGHT__, "Fract-ol");	
	
	// printf("%d",ft_init_fractal(&frame.fract, argc, argv));





	// printf("bit = %lld\n", ft_get_bits(7));
	// ft_get_bits(0xFFFFFF);
	// ft_get_bits(0xFF000000);
	// printf("COLOR = %d\n", 54321000&0xFFFFFF);
	// vars.mlx = fr.mlx_ptr;
	// vars.win = fr.win_ptr;

	// ft_menu(&fr);

	// mlx_mouse_hook (fr.win_ptr, mouse_hook, &fr);
	// mlx_key_hook (fr.win_ptr, key_hook, &fr);
	

	// ft_black_screen(&fr);
	// mlx_hook(fr.win_ptr, KeyPress, __KeyPressMask__, ft_close, &fr);
	// mlx_hook(fr.win_ptr, MotionNotify, __EnterWindowMask__, ft_enter_window, &fr);
	// mlx_hook(fr.win_ptr, MotionNotify, __LeaveWindowMask__, ft_leave_window, &fr);
	
	// mlx_loop(fr.mlx_ptr);

	// min.re = -2.0;
	// max.re = 2.0;
	// min.im = -2.0;
	// max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	// usleep();

	return 0;
}