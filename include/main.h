/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 12:27:25 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define MLX_KEY_A              97
# define MLX_KEY_S              115
# define MLX_KEY_D              100
# define MLX_KEY_W              119
# define MLX_KEY_LEFT           65361
# define MLX_KEY_RIGHT          65363
# define MLX_KEY_SHIFT_L        65505
# define MLX_KEY_ESCAPE         65307
# define MLX_KEY_PLUS			61
# define MLX_KEY_MINUS			45
# define MLX_KEY_UP				65362
# define MLX_KEY_DOWN			65364
# define PRESS					1
# define RELEASE				0
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include "stdio.h"

typedef enum e_errors
{
	INVALID_NUM_OF_ARGS_ERROR = -100,
	FILE_DOES_NOT_OPEN_ERROR,	
	INVALID_MAP_ERROR,
	CALLOC_ERROR,
	ERROR,
}	t_errors;

typedef struct s_keyflags
{
	int	right;
	int	left;
	int	w;
	int	a;
	int	s;
	int	d;
	int	plus;
	int	minus;
	int	up;
	int	down;
}	t_keyflags;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_main
{
	int			**z_matix;
	int			width;
	int			height;
	int			screen_width;
	int			screen_height;
	int			zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	float		cos;
	float		sin;
	int			x;
	int			y;
	int			z;
	int			color;
	t_img		img;
	t_keyflags	keyflags;
}	t_main;

typedef struct s_xy
{
	float	x0;
	float	y0;
}	t_xy;

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *np);
int		ft_isspace(char c);
int		ft_isdigit(int c);
void	*ft_memset(void *dest, int c, size_t n);
char	**ft_split(char const *s, char c);
int		exit_hook(void *data);
void	normalize_matrix(t_main *data);
float	max_num(float a, float b);
int		scan_map(char *filename, t_main *data);
int		fill_matrix(t_main *data, char *filename);
int		set_size(int fd, t_main *data);
int		ft_error(t_errors code, t_main *data);
int		scan_map_helper(int fd, t_main *data);
int		ft_free(void **ptr);
int		free_matrix(t_main *data);
void	bresenham(t_xy xy, float x1, float y1, t_main *data);
int		count_of_nums_in_line(char *line);
void	my_mlx_pixel_put(t_main *data, int x, int y, int color);
int		init_mlx(t_main *data);
int		render_frame(void *data);
void	set_hooks(t_main *data);
void	draw_background(t_main *data);
void	draw_isometric(t_main *data);
void	rotate_x(t_main *data, float *x, float *y, int *z);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const void *s, int c);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
int		ft_memdel(char **ptr);
ssize_t	get_rs(char *buf, int fd, ssize_t *rs);

#endif
