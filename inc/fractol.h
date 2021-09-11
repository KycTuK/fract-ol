#ifndef FTACTOL_H
# define FTACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# define __MAX_K__ 10000

typedef struct	s_image
{
	void	*ptr;
	int		width;
	int		height;
	char	*title;
}			t_image;

typedef struct	s_data
{
	t_image	img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* window */
typedef struct	s_frame
{
	void	*mlx_ptr;
	void	*win_ptr;
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
	double	width;
	double	height;
}			t_rectangle;

# endif