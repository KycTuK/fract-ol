#include "fractol.h"

int			ft_strcmp(const char *s1, const char *s2);
int			ft_fatoi(t_fnbr *f, const char *str);
static int	ft_memcmp(const void *s1, const void *s2, size_t n);
static int	ft_fatoi_dot_sign(t_fnbr *f);
static int	ft_isdigit(int c);
// void        ft_get_bits(unsigned long long n);

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (ft_memcmp(s1 + i, s2 + i, 1) != 0)
			return (ft_memcmp(s1 + i, s2 + i, 1));
		if (s1[i] == '\0' || s2[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		diff = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

int	ft_fatoi(t_fnbr *f, const char *str)
{
	if (str[f->j] == '-')
	{
		f->sign = -f->sign;
		f->j++;
	}
	while (ft_isdigit(str[f->j]) != 0 || str[f->j] == '.')
	{
		f->k++;
		if (str[f->j] == '.')
		{
			if (f->dot == 1)
				return (0);
			f->dot = 1;
			f->k = 0;
		}
		else
			f->n = f->n * 10 + str[f->j] - 48;
		f->j++;
	}
	if (str[f->j] != '\0')
		return (0);
	return (ft_fatoi_dot_sign(f));
}

static int	ft_fatoi_dot_sign(t_fnbr *f)
{
	int	i;

	i = 0;
	while (f->dot == 1 && i < f->k)
	{
		f->n = f->n / 10;
		i++;
	}
	if (f->n == 0 && f->sign == -1)
		return (0);
	f->n = f->n * f->sign;
	return (1);
}

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

// void ft_get_bits(unsigned long long n)
// {
// 	static unsigned long long ns;
// 	if (n)
// 	{
// 		if (!ns)
// 			ns = n;
// 		ft_get_bits(n >> 1);
// 		printf("%d",(int)(n & 1));
// 		if (n == ns)
// 		{
// 			printf("\n");
// 			ns = 0;
// 		}
// 	}
// }

// long long int ft_get_bits(int n)
// {
// 	long long int b = 0;
// 	while (n)
// 	{
// 		b = b * 10 + (n & 1);
// 		n >>= 1;
// 	} 
// 	return b;
// }

// int	ft_enter_window(int button, int x, int y, t_frame *fr)
// {
// 	if (!x || x == fr->win.size.width || \
// 		!y || y == fr->win.size.height \
// 	)
// 	printf("Hello newer! b[%d] x[%d] y[%d]\n", button, x, y);
// 	return (0);
// }

// int	ft_leave_window(int button, int x, int y, t_frame *fr)
// {
// 	if (!x || x == fr->win.size.width || \
// 		!y || y == fr->win.size.height \
// 	)
// 	printf("Bye newer! b[%d] x[%d] y[%d]\n", button, x, y);
// 	return (0);
// }

// static void	ft_black_screen(t_frame *fr)
// {
// 	t_point pxl;
// 	pxl.x = WIDTH - 1;
// 	pxl.y = 0;
// 	pxl.color = 0;

// 	while (pxl.y < WIDTH)
// 	{
// 		ft_mlx_pixel_put(&fr, &pxl);
// 		pxl.y++;
// 	}
// 	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->data.img.ptr, 0, 0);
// }