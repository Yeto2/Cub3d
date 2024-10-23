/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:18:35 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/23 22:56:20 by yessemna         ###   ########.fr       */
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
# define HEXA "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_map
{
    char **map;
    int map_w;
    int map_h;
}   t_map;

typedef struct s_color
{
    int red;
    int green;
    int blue;
}   t_color;

typedef struct s_player
{
    int x;
    int y;
    char dir;
}   t_player;

typedef struct s_data
{
    t_player    player;
    t_color     floor;
    t_color     ciel;
    t_map       map;
    char        *no;
    char        *so;
    char        *ea;
    char        *map_path;
    char        **data_map;
    char        **map_dtls;
    char        *we;
    
}   t_data;

typedef struct s_list
{
    void			*content;
    struct s_list	*next;
}	t_list;

// parsing

int fill_map_data(t_data *data);
int skip_spc_check(char *line);
int valid_letter(char *line);
int check_if_valid(t_data *data);
int prepare_data(t_data *data);
void init_data_vars(t_data **data);
void check_extention(const char *file);
int count_lines(t_data *data);
void handle_color(char *color, char type, t_data **data);

// tools
size_t  ft_strlen(const char *s);
char    **ft_split(char const *s, char c);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2, int len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(const char *s);
int	is_space(char c);
int ft_atoi(const char *str);

// ft_open

typedef struct s_fd_col
{
	int	fds[OPEN_MAX];
	int	count;
}	t_fd_col;

void	init_fd_collector(t_fd_col *collector);
int		ft_open(t_fd_col *collector,
			const char *filename, int flags, mode_t mode);
void	close_all_fds(t_fd_col *collector);

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


void	clear_all(t_col **head);
void	*g_malloc(size_t size, t_call call);
void	add_back(t_col	**head, t_col *new);
t_col	*last_node(t_col **head);
t_col	*new_node(void	*ptr);

//ft_printf
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_put_u_nbr(unsigned int n, int *count);
void	ft_hexa(unsigned int n, int *count, char *HEXA_);
void	ft_hexap(unsigned long long n, int *count, char *HEXA_);
#endif