#include <stdio.h>
#include "mlx_macos/mlx.h"

typedef struct	s_size
{
	double	width;
	double	height;
}		t_size;

typedef struct	s_image
{
	void	*ptr;
	char	*title;
	t_size	size;
}			t_image;

typedef struct	s_data
{
	t_image	img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

/* window */
typedef struct	s_window
{
	char	*title;
	t_size	size;
}			t_win;

typedef struct	s_frame
{
	void	*win_ptr;
	void	*mlx_ptr;
	t_win	win;	
	t_data	data;
}			t_frame;



void	ft_mlx_init(t_frame *fr, int fr_width, int fr_height, char *fr_title)
{
	fr->data.img.size.width = fr_width;
	fr->data.img.size.height = fr_height;
	fr->data.img.title = fr_title;

	fr->win.size.width = fr_width;
	fr->win.size.height = fr_height;
	fr->win.title = fr_title;

	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, \
								 fr->win.size.width, \
								 fr->win.size.height, \
								 fr->win.title \
								 );
	fr->data.img.ptr = mlx_new_image(fr->mlx_ptr, \
									 fr->data.img.size.width, \
									 fr->data.img.size.height \
									 );
	fr->data.addr = mlx_get_data_addr(fr->data.img.ptr, \
										&fr->data.bits_per_pixel, \
										&fr->data.line_length, \
										&fr->data.endian);
}

int main()
{
    printf("wtf");

	t_frame fr;
	// t_vars	vars;
	ft_mlx_init(&fr, 1920, 1080, "Hello world!");

    return 0;
}