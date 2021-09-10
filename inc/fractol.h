#ifndef FTACTOL_H
# define FTACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct	s_circle
{
	int		radius;
	struct
	{
		int x;
		int y;
	}		center;
}				t_circle;

# endif