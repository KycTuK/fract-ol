#ifndef FTACTOL_H
# define FTACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# define __MAX_K__ 10000
# define __WINDOW_RESIZE_PREC___ 20

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

enum EVENTS
{
	KeyPress		= 2,
	KeyRelease		= 3,
	ButtonPress		= 4,
	ButtonRelease	= 5,
    MotionNotify	= 6,
    EnterNotify		= 7,
	LeaveNotify		= 8
}	ev;

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
	int		color;
}			t_point;

typedef struct
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

void	ft_mlx_init(t_frame *fr, int fr_width, int fr_height, char *fr_title);
void	ft_mlx_draw_pixel(t_frame *fr, t_point *p);

void	ft_put_rectangle(t_frame *fr, t_rectangle rect);
void	ft_put_circle(t_frame *fr, t_circle circ);


# endif