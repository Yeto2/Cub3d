/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:43:24 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/19 23:45:08 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_front_back(t_data *data, int dirc)
{
	t_pos	pos;

	pos.x = data->player.x + dirc * MOV_SPEED * cos(data->ang);
	pos.y = data->player.y + dirc * MOV_SPEED * sin(data->ang);
	if (check_map(data, pos.x, pos.y))
	{
		data->player.x = pos.x;
		data->player.y = pos.y;
	}
}

void	move_right_left(t_data *data, int dirc)
{
	t_pos	pos;

	pos.x = data->player.x + MOV_SPEED * cos(data->ang + dirc * M_PI / 2);
	pos.y = data->player.y + MOV_SPEED * sin(data->ang + dirc * M_PI / 2);
	if (check_map(data, pos.x, pos.y))
	{
		data->player.x = pos.x;
		data->player.y = pos.y;
	}
}

void	handell_keys(void *pram)
{
	t_data	*data;

	data = (t_data *)pram;
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_W))
		move_front_back(data, 1);
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_S))
		move_front_back(data, -1);
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_A))
		move_right_left(data, -1);
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_D))
		move_right_left(data, 1);
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_ESCAPE))
	{
		exit(0);
	}
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_LEFT))
		data->ang -= M_PI / 50;
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_RIGHT))
		data->ang += M_PI / 50;
	data->ang = ft_normalize(data->ang);
	clear_image(data);
	ray_cast(data);
}
