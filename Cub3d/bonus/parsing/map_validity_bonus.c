/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:05:49 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/29 12:03:10 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	find_player(t_data **data)
{
	int	i;
	int	j;
	int	player;

	(1) && (i = 0, j = 0, player = 0);
	while ((*data)->map.map[++i])
	{
		j = 0;
		while ((*data)->map.map[i][++j])
		{
			if (dir((*data)->map.map[i][j]))
			{
				if (player)
					return (1);
				(1) && (player++, (*data)->player.x = j, (*data)->player.y = i,
					(*data)->player.dir = (*data)->map.map[i][j],
					(*data)->map.map[i][j] = '0');
			}
		}
	}
	if (player > 1 || player == 0)
		return (1);
	return (0);
}

void	tabs_found(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			print_err("Error\nTabs are not allowed in the map\n");
		i++;
	}
}

int	check_map_validity(t_data **data)
{
	size_t	width;
	int		i;
	int		j;

	i = 0;
	j = 0;
	width = (*data)->map.map_w;
	if (is_rounded(data))
		return (1);
	if (find_player(data))
		return (1);
	i = 0;
	while ((*data)->map.map[i])
	{
		tabs_found((*data)->map.map[i]);
		if (ft_strlen((*data)->map.map[i]) < width)
		{
			while (ft_strlen((*data)->map.map[i]) < width)
				(*data)->map.map[i] = join_char((*data)->map.map[i], ' ');
		}
		i++;
	}
	if (is_zero_surrounded(data))
		return (1);
	return (0);
}
