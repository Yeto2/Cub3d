/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_data_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:45:05 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 04:45:30 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	prepare_data(t_data *data)
{
	int	i;
	int	j;
	int	len;

	(1) && (i = 0, j = 0, len = 0);
	while ((data)->data_map[i])
	{
		if (!valid_letter((data)->data_map[i]) || !(data)->data_map[i][0])
			len++;
		else if (!null_check((data)->data_map[i]))
			print_err("Invalid map data");
		i++;
	}
	(data)->map_dtls = g_malloc(sizeof(char *) * (len + 1), MALLOC);
	if (!(data)->map_dtls)
		print_err("Malloc failed");
	i = 0;
	while ((data)->data_map[i])
	{
		if (!valid_letter((data)->data_map[i]))
			(data)->map_dtls[j++] = ft_strdup((data)->data_map[i]);
		i++;
	}
	data->map_dtls[j] = NULL;
	return (0);
}
