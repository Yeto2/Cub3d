/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:18:35 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/16 19:52:30 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_map
{
    char **map;
    int map_w;
    int map_h;
    char *map_path;
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
    char        *we;
    
}   t_data;



#endif