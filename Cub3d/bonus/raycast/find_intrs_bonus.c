/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intrs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:32:37 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/22 16:57:42 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	hitt_wall(double i, double j, t_data *data, int ver)// <----- to check c is hitted
{
	int	x;
	int	y;

	x = i / TILE_SIZE;
	y = j / TILE_SIZE;
	if (x < 0 || y < 0)
		return (0);
	if (x >= data->map.map_w || y >= data->map.map_h)
		return (0);
	if (data->map.map[y][x] == '1')
		return (0);
	if (data->map.map[y][x] == 'C')
	{
		if (ver)
			return (data->dor_v = 1, 0);
		else
			return (data->dor_h = 1, 0);
	}
	return (1);
}

t_pos	get_first_intesaction(t_player pl, double ang)
{
	t_pos	inter;

	inter.y = floor(pl.y / TILE_SIZE) * TILE_SIZE;
	if (ang > 0 && ang < M_PI)
		inter.y += TILE_SIZE;
	inter.x = pl.x + (inter.y - pl.y) / tan(ang);
	return (inter);
}

double	find_horiznatal_inter(t_player pl, double ang, t_data *data)
{
	t_pos	inter;
	double	x_step;
	double	y_step;
	int		pixl;

	pixl = 1;
	data->direct = -1;
	if (ray_datiction_dwn(ang))
	{
		pixl = -1;
		data->direct = 1;
	}
	inter = get_first_intesaction(pl, ang);
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(ang);
	siting_up_steps(&x_step, &y_step, ang);
	while (hitt_wall(inter.x, inter.y - pixl, data, 0))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	data->h_inter = inter.x;
	return (sqrt(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
}

t_pos	get_first_intesaction1(t_player pl, double ang)
{
	t_pos	inter;

	inter.x = floor(pl.x / TILE_SIZE) * TILE_SIZE ;
	if ((ang >= 0 && ang < M_PI / 2)
		|| (ang > 3 * M_PI / 2 && ang < 2 * M_PI))
		inter.x += TILE_SIZE;
	inter.y = pl.y + (inter.x - pl.x) * tan(ang);
	return (inter);
}

float	find_vertical_inter(t_player pl, double ang, t_data *data)
{
	t_pos		inter;
	double		x_step;
	double		y_step;
	int			pixl;

	pixl = 1;
	data->direct = 1;
	if (ray_dariction_right(ang))
	{
		pixl = -1;
		data->direct = -1;
	}
	inter = get_first_intesaction1(pl, ang);
	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(ang);
	siting_up_steps(&x_step, &y_step, ang);
	while (hitt_wall(inter.x - pixl, inter.y, data, 1))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	data->v_inter = inter.y;
	return (sqrt(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
}
