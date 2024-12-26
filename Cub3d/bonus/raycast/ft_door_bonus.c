/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:58:33 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 02:58:42 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	open_dor(t_data *data)
{
	t_pos	check;
	double	dst_to_dor;
	int		i;
	int		j;

	dst_to_dor = 50;
	check.x = data->player.x + dst_to_dor * cos(data->ang);
	check.y = data->player.y + dst_to_dor * sin(data->ang);
	i = check.x / TILE_SIZE;
	j = check.y / TILE_SIZE;
	if (data->map.map[j][i] == 'C')
	{
		data->dor_pos.x = i;
		data->dor_pos.y = j;
		data->map.map[j][i] = 'O';
		data->dor_open = 1;
	}
}

void	close_dor(t_data *data)
{
	double	dst_to_close;
	t_pos	pos;

	pos.x = data->dor_pos.x * TILE_SIZE + TILE_SIZE / 2;
	pos.y = data->dor_pos.y * TILE_SIZE + TILE_SIZE / 2;
	dst_to_close = sqrt(pow(data->player.x - pos.x, 2)
			+ pow(data->player.y - pos.y, 2));
	if (data->dor_open == 0)
		return ;
	if (!(data->player.x / TILE_SIZE == data->dor_pos.x
			&& data->player.y / TILE_SIZE == data->dor_pos.y)
		&& dst_to_close > 90)
	{
		data->map.map[(int)data->dor_pos.y][(int)data->dor_pos.x] = 'C';
		data->dor_open = 0;
	}
}
