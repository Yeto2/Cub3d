/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esolate_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:37:44 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 05:00:31 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	parse_doors(t_data **data)
{
	t_var	v;

	(1) && (v.i = 0, v.lr_door = false, v.tb_door = false);
	while (v.i < (*data)->map.map_h)
	{
		v.j = 0;
		while (v.j++ < (*data)->map.map_w)
		{
			if ((*data)->map.map[v.i][v.j] == 'C')
			{
				if ((*data)->map.map[v.i][v.j + 1] == '1'
					&& (*data)->map.map[v.i][v.j - 1] == '1')
					v.lr_door = true;
				else if ((*data)->map.map[v.i + 1][v.j] == '1'
					&& (*data)->map.map[v.i - 1][v.j] == '1')
					v.tb_door = true;
				if (!v.lr_door && !v.tb_door)
					print_err("door position is invalid");
			}
			else if (ft_isalpha((*data)->map.map[v.i][v.j]))
				return (1);
		}
		v.i++;
	}
	return (0);
}

void	set_dementions(t_data **data, int height, size_t width)
{
	(*data)->map.map_h = height;
	(*data)->map.map_w = width;
	if (check_map_validity(data))
		print_err("Invalid map data");
	if (parse_doors(data))
		print_err("Invalid map data 'doors'");
}

void	esolate_check(t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		height;
	size_t	width;

	(1) && (i = 0, j = -1, k = 0, height = 0, width = 0);
	init_data_vars(&data);
	while (data->map_dtls[i] && ++j < 6)
		prepare(data->map_dtls[i++], &data);
	while (data->map_dtls[j++])
		height++;
	data->map.map = g_malloc(sizeof(char *) * (height + 1), MALLOC);
	width = ft_strlen(data->map_dtls[i]);
	while (data->map_dtls[i])
	{
		data->map.map[k++] = ft_strdup(data->map_dtls[i]);
		i++;
		if (ft_strlen(data->map_dtls[i]) > width)
			width = ft_strlen(data->map_dtls[i]);
	}
	data->map.map[k] = NULL;
	set_dementions(&data, height, width);
}
