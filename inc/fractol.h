#ifndef FTACTOL_H
# define FTACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# define __MAX_K__ 10000000
# define __WINDOW_RESIZE_PREC___ 20

// # define __EXIT_SUCCESS__ 0
// # define __EXIT_FAILURE__ 1

# define __WIDTH__	900
# define __HEIGHT__	900

// enum BOOLEAN
// {
//     false,
//     true
// };

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

enum MOUSE_KEYS
{
	LEFT_KEY	= 1,
	RIGHT_KEY	= 2,
	MIDDLE_KEY	= 3,
	ZOOM_OUT	= 4,
	ZOOM_IN		= 5
};

enum KEYBOARD_KEYS
{
	ESC		= 53,
	ALT		= 259,
	W_KEY	= 13,
	G_KEY	= 5,
	H_KEY	= 4
};

enum COLORS
{
	COLOR1	= 8200,
	COLOR2	= 4600,
	COLOR3	= 5100,
	COLOR4	= 1200
};

enum FRACTALS
{
	JULIA		= 1,
	MANDELBROT	= 2,
	BROWNIAN	= 3
};

// enum EVENTS
// {
// 	KeyPress		= 2,
// 	KeyRelease		= 3,
// 	ButtonPress		= 4,
// 	ButtonRelease	= 5,
//     MotionNotify	= 6,
//     EnterNotify		= 7,
// 	LeaveNotify		= 8
// };

/* KeyPressMasks */
# define __KeyPressMask__ (1L<<0)
# define __EnterWindowMask__ (1L<<4)
# define __LeaveWindowMask__ (1L<<5)


typedef struct
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct s_fnbr
{
	double	n;
	size_t	j;
	int		sign;
	int		dot;
	int		k;
	double	i;
}		t_fnbr;

typedef struct	s_fract
{
	int		name;
	double	y0;
	double	x0;
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

typedef struct	s_size
{
	double	width;
	double	height;
}			t_size;

typedef struct	s_image
{
	void	*ptr;
	char	*title;
	t_size	size;
}			t_image;

typedef struct	s_menu
{
	t_point lu_corner;
}			t_menu;

/* data */
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

/* frame */
typedef struct	s_frame
{
	void	*win_ptr;
	void	*mlx_ptr;
	t_win	win;	
	t_data	data;
	t_fract	fract;
	t_menu	menu;
}			t_frame;

/* side */
typedef struct s_draw
{
	double	precision;
	int		color;
}			t_draw;

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

/* draw */ 
void	ft_mlx_pixel_put(t_data *data, double x, double y, int color);
// void	ft_mlx_pixel_put(t_data *data, t_point *pixel);
void	ft_mlx_draw_img(t_frame *fr);
void	ft_menu(t_frame *fr);

/* inits */
void	ft_mlx_init_def(t_frame *fr, double width, double height, char *title);
int		ft_init_fractal(t_fract *fract, int argc, char **argv);

/* calcs */
void	calc_fract(t_frame *fr);

/* hooks */
int		key_hook(int keycode, t_frame *fr);
int		mouse_hook(int button, int x, int y, t_frame *fr);
void	ft_close(char *message);

/* utils */
int		ft_fatoi(t_fnbr *f, const char *str);
int		ft_strcmp(const char *s1, const char *s2);

/* draw figures */
/* circle rectangle */
void	ft_init_circle_def(t_circle *circ);
void	ft_put_circle(t_frame *fr, t_circle *circ);

void	ft_init_rectangle_def(t_rectangle *rect);
void	ft_put_rectangle(t_frame *fr, t_rectangle *rect);

# endif