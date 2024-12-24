/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lastudent.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:21:56 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/22 10:11:54 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_map(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = x / TILE_SIZE;
	j = y / TILE_SIZE;
	if (data->map.map[j][i] == '0' || data->map.map[j][i] == 'O')
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
	// if (check_map(data, pos.x, pos.y) && check_map(data, check.x, check.y)
	// 	&& check_map(data, data->player.x, check.y) && check_map(data, check.x, data->player.y))
	// {
	// 	data->player.x = pos.x;
	// 	data->player.y = pos.y;
	// }
    if (check_map(data, data->player.x, pos.y) && check_map(data, data->player.x, check.y))
        data->player.y = pos.y;
    if (check_map(data, pos.x, data->player.y) && check_map(data, check.x, data->player.y))
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
	// if (check_map(data, pos.x, pos.y) && check_map(data, check.x, check.y)
	// 	&& check_map(data, data->player.x, check.y) && check_map(data, check.x, data->player.y))
	// {
	// 	data->player.x = pos.x;
	// 	data->player.y = pos.y;
	// }
    if (check_map(data, data->player.x, pos.y) && check_map(data, data->player.x, check.y))
        data->player.y = pos.y;
    if (check_map(data, pos.x, data->player.y) && check_map(data, check.x, data->player.y))
        data->player.x = pos.x;
}

void	open_dor(t_data *data)
{
	t_pos	check;
	double	dst_to_dor;
	int		i;
	int		j;

	// data->dor_open = 0;
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
	// i = data->player.x / TILE_SIZE;
	// j = data->player.y / TILE_SIZE;
	// if (data->map.map[j][i] == 'C')
	// {
	// 	data->dor_pos = check;
	// 	data->map.map[j][i] = 'O';
	// 	data->dor_open = 1; 
	// }
}

void	close_dor(t_data *data)
{
	double	dst_to_close;
	t_pos	pos;

	pos.x = data->dor_pos.x * TILE_SIZE + TILE_SIZE / 2;
	pos.y = data->dor_pos.y * TILE_SIZE + TILE_SIZE / 2;
	dst_to_close = sqrt(pow(data->player.x - pos.x, 2) + pow(data->player.y - pos.y, 2));
	// printf("cc\n");
	if (data->dor_open == 0)
		return ;
	if (!(data->player.x/ TILE_SIZE == data->dor_pos.x
		&& data->player.y/ TILE_SIZE == data->dor_pos.y)
		&& dst_to_close > 90)
	{
		data->map.map[(int)data->dor_pos.y][(int)data->dor_pos.x] = 'C';
		data->dor_open = 0;
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
		// terminate_mlx(data);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_LEFT))
		data->ang -= M_PI / 50;
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_RIGHT))
		data->ang += M_PI / 50;
	open_dor(data);
	close_dor(data);
	data->ang = ft_normalize(data->ang);
	clear_image(data);
	ray_cast(data);
	render_2d_map(data);
	// render_2d(data);
}
