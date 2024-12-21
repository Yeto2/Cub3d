/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esolate_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:37:44 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/20 19:38:07 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int parse_doors(t_data **data)
{
	t_data *tmp;
	int i;
	int j;
	bool lr_door;
	bool tb_door;
	
	tmp = *data;
	i = 0;
	lr_door = false;
	tb_door = false;
	while( i < tmp->map.map_h)
	{
		j = 0;
		while (j < tmp->map.map_w)
		{
			if ((*data)->map.map[i][j] == 'C')
			{
				printf("--> Door found at %d %d\n", i, j);
				if ((*data)->map.map[i][j + 1] == '1' && (*data)->map.map[i][j - 1] == '1')
					lr_door = true;
				else if ((*data)->map.map[i + 1][j] == '1' && (*data)->map.map[i - 1][j] == '1')
					tb_door = true;
				
				if (!lr_door && !tb_door)
					print_err("door position is invalid");
				(*data)->map.map[i][j] = '0'; // set door to 0
			}
			else if (ft_isalpha((*data)->map.map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	// in this function i store the position of the doors
	return (0);
}

void	set_dementions(t_data **data, int height, size_t width)
{
	(*data)->map.map_h = height;
	(*data)->map.map_w = width;
	// int i = 0; // <-----
	// int j = 0;
	// while ((*data)->map.map[i])
	// {
	// 	j = 0;
	// 	while ((*data)->map.map[i][j])
	// 	{
	// 		if ((*data)->map.map[i][j] == 'D')
	// 			printf("Door found at %d %d\n", i, j);
	// 		j++;
	// 	}
	// 	i++;
	// }
	if (check_map_validity(data))
		print_err("Invalid map data"); // nahi hogaya
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
	if (data->map_dtls[j] && data->map_dtls[j][0] != '1')
		print_err("Invalid map data");
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
