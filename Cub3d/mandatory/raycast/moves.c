/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:21:56 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/25 14:36:40 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = x / TILE_SIZE;
	j = y / TILE_SIZE;
	if (data->map.map[j][i] == '0')
		return (1);
	return (0);
}

void	move_front_back(t_data *data, int dirc)
{
	t_pos	pos;
	t_pos	check;
	int		dst_to_wall;

	dst_to_wall = MOV_SPEED + 20;
	pos.x = data->player.x + dirc * MOV_SPEED * cos(data->ang);
	pos.y = data->player.y + dirc * MOV_SPEED * sin(data->ang);
	check.x = data->player.x + dirc * dst_to_wall * cos(data->ang);
	check.y = data->player.y + dirc * dst_to_wall * sin(data->ang);
	if (check_map(data, data->player.x, pos.y)
		&& check_map(data, data->player.x, check.y))
		data->player.y = pos.y;
	if (check_map(data, pos.x, data->player.y)
		&& check_map(data, check.x, data->player.y))
		data->player.x = pos.x;
}

void	move_right_left(t_data *data, int dirc)
{
	t_pos	pos;
	t_pos	check;
	int		dst_to_wall;

	dst_to_wall = MOV_SPEED + 20;
	pos.x = data->player.x + MOV_SPEED * cos(data->ang + dirc * M_PI / 2);
	pos.y = data->player.y + MOV_SPEED * sin(data->ang + dirc * M_PI / 2);
	check.y = data->player.y + dst_to_wall * sin(data->ang + dirc * M_PI / 2);
	check.x = data->player.x + dst_to_wall * cos(data->ang + dirc * M_PI / 2);
	if (check_map(data, data->player.x, pos.y)
		&& check_map(data, data->player.x, check.y))
		data->player.y = pos.y;
	if (check_map(data, pos.x, data->player.y)
		&& check_map(data, check.x, data->player.y))
		data->player.x = pos.x;
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
		terminate_mlx(data);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_LEFT))
		data->ang -= M_PI / 50;
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_RIGHT))
		data->ang += M_PI / 50;
	data->ang = ft_normalize(data->ang);
	clear_image(data);
	ray_cast(data);
}
