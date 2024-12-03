/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esolate_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:37:44 by yessemna          #+#    #+#             */
/*   Updated: 2024/11/28 22:42:15 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_dementions(t_data **data, int height, size_t width)
{
	(*data)->map.map_h = height;
	(*data)->map.map_w = width;
	if (check_map_validity(data))
		print_err("Invalid map data");
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
