/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:18:35 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 09:31:19 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# define HEXA "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"
# define S_W 1300 // screen width
# define S_H 800 // screen height
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define TILE_SIZE 64
# define MOV_SPEED 7
# define NUM_FRAMES 10

typedef struct s_map
{
	char	**map;
	int		map_w;
	int		map_h;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;
// enum deriction
// {
// 	up,
// 	dwn,
// 	right,
// 	left
// };

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_player
{
	double		x;
	double		y;
	char		dir;
}	t_player;

typedef struct s_mlx
{
	mlx_image_t		*img;	// the image
	mlx_image_t		*img_r;
	mlx_image_t		*img_m;
	mlx_image_t		*img_p;
	mlx_t			*mlx_p;	// the mlx pointer
}	t_mlx;

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_textures;

typedef struct s_data
{
	mlx_texture_t	*texture;
	t_textures		textures;
	t_player		player;
	t_player		tmp_pl;
	t_player		tmp_pl1;
	t_color			floor;
	t_color			ciel;
	t_map			map;
	t_mlx			mlx;
	char			*no;
	char			*so;
	char			*ea;
	char			*map_path;
	char			**data_map;
	char			**map_dtls;
	char			*we;
	int				clr;
	double			scale;
	double			unite;
	double			ang;
	double			ray_dst;
	int				hor;
	int				ray_x;
	int				wall_hght;
	int				top_pixel;
	int				bottom_pixel;
	double			v_inter;
	double			h_inter;
	int				offsetx;
	int				direct;
	void			*weapon_frames[NUM_FRAMES];
	int				current_frame;
}	t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_var
{
	char	**tmp;
	int		j;
	int		sc;
	int		i;
	int		r;
	int		g;
	int		b;
}	t_var;

typedef struct s_render_var
{
	uint32_t		*p_clrs;
	double			wall_hght;
	double			dst;
	int				top;
	int				bottom;
	int				j;
	int				txt_y;
	int				color;
}	t_render_var;

typedef struct s_fd_col
{
	int	fds[OPEN_MAX];
	int	count;
}	t_fd_col;

// parsing
uint32_t		get_coller(int r, int g, int b, int a);
mlx_texture_t	*set_png_texture(t_data *data, char *path);
mlx_texture_t	*return_texture(t_data *data, t_textures *textures, double ray);
void			init_data_vars(t_data **data);
void			check_extention(const char *file);
void			handle_color(char *color, char type, t_data **data);
int				fill_map_data(t_data *data, t_fd_col *collector);
int				skip_spc_check(char *line);
int				valid_letter(char *line);
int				check_if_valid(t_data *data);
int				prepare_data(t_data *data);
int				count_lines(t_data *data, t_fd_col *collector);
int				wsnecf10(char c);
int				dir(char c);
char			*join_char(char *str, char c);
void			esolate_check(t_data *data);
int				is_zero_surrounded(t_data **data);
int				is_rounded(t_data **data);
void			prepare(char *line, t_data **data);
int				check_map_validity(t_data **data);
int				txt_clr(unsigned int c);
// tools
int				is_alpha(char *c);
size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2, int len);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strdup(const char *s);
int				is_space(char c);
int				ft_atoi(const char *str);
void			print_err(char *err);
int				wsne_cf1(char *ln);
int				null_check(char *line);
int				ft_isalpha(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_itoa(int n);
void			load_weapon_images(t_data *data);
int				is_alpha(char *c);
void			terminate_mlx(t_data *data);
int				prepare_data(t_data *data);
// ft_open

void			init_fd_collector(t_fd_col *collector);
int				ft_open(t_fd_col *collector,
					const char *filename, int flags, mode_t mode);
void			close_all_fds(t_fd_col *collector);

// ft_malloc

typedef struct s_col
{
	void			*ptr;
	struct s_col	*next;
}	t_col;

typedef enum e_call
{
	FREE,
	MALLOC
}	t_call;

void			clear_all(t_col **head);
void			*g_malloc(size_t size, t_call call);
void			add_back(t_col	**head, t_col *new);
t_col			*last_node(t_col **head);
t_col			*new_node(void	*ptr);

//ft_printf
void			ft_putchar(char c, int *count);
int				ft_printf(const char *format, ...);
void			ft_putstr(char *str, int *count);
void			ft_putnbr(int n, int *count);
void			ft_put_u_nbr(unsigned int n, int *count);
void			ft_hexa(unsigned int n, int *count, char *HEXA_);
void			ft_hexap(unsigned long long n, int *count, char *HEXA_);

// reycasting

// bresnhamm
t_player		pos_in_map(t_player pl);
// void		draw_line(t_cor a, t_cor b, t_data *data, int stuts);
// void		draw_map(t_data *data);
void			start_game(t_data *data);
void			ray_cast(t_data	*data);
double			ft_normalize(double ang);
double			set_angle(t_player pl);
int				ray_datiction_dwn(double ang);
int				ray_dariction_right(double ang);
void			siting_up_steps(double	*x, double *y, double ang);
void			find_pixel(double hght, int *top, int *bottum);
double			find_horiznatal_inter(t_player pl, double ang, t_data *data);
float			find_vertical_inter(t_player pl, double ang, t_data *data);
void			render(t_data *data, double ray, int i);
void			handell_keys(void *pram);
int				check_map(t_data *data, double x, double y);
void			clear_image(t_data *data);
#endif