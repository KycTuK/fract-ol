#ifndef FTACTOL_H
# define FTACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
// # include <mlx.h>
# include "mlx.h"

# define __MAX_K__ 100000
# define __WINDOW_RESIZE_PREC___ 20

# define __EXIT_SUCCESS__ 0
# define __EXIT_FAILURE__ 1

# define WIDTH	900
# define COLOR_1 8200
# define COLOR_2 4600

enum BOOLEAN
{
    false,
    true
};

/*	Events:
________________
02	KeyPress
03	KeyRelease
04	ButtonPress
05	ButtonRelease
06	MotionNotify
07	EnterNotify
08	LeaveNotify
*/

enum KEYS
{
	ESC		= 53,
	ALT		= 259,
	W_KEY	= 13
};

enum EVENTS
{
	KeyPress		= 2,
	KeyRelease		= 3,
	ButtonPress		= 4,
	ButtonRelease	= 5,
    MotionNotify	= 6,
    EnterNotify		= 7,
	LeaveNotify		= 8
};

/* KeyPressMasks */
# define __KeyPressMask__ (1L<<0)
# define __EnterWindowMask__ (1L<<4)
# define __LeaveWindowMask__ (1L<<5)


// typedef struct	s_vars 
// {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

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

/* point */
typedef struct
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct
{
	double	precision;
	int		color;
}			t_draw;

typedef struct	s_fract
{
	t_point	pos;
	int		name;
	double	i;
	double	re;	
	int		iter;
	int		color_plus;
	int		color_x;	
	int		bpp;
	int		sl;
	int		endian;
	double	zoom;
}			t_fract;

typedef	struct	s_circle
{
	t_point	center;
	t_draw	info;
	int		radius;
}			t_circle;

typedef	struct	s_rectangle
{
	t_point	center;
	t_point	min;
	t_point	max;
	t_draw	info;
	t_size	size;
}			t_rectangle;

/* mlx */ 
void	ft_mlx_init(t_frame *fr, int fr_width, int fr_height, char *fr_title);
void	ft_mlx_pixel_put(t_data *data, t_point *pixel);
void	ft_mlx_draw_pixel(t_frame *fr, t_point *p);

/* hooks */
int		key_hook(int keycode, t_frame *fr);
int		mouse_hook(int button, int x, int y, t_frame *fr);

/* draw figures */
void	ft_put_rectangle(t_frame *fr, t_rectangle rect);
void	ft_put_circle(t_frame *fr, t_circle circ);

# endif