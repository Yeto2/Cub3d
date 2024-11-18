/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:00:10 by lamhal            #+#    #+#             */
/*   Updated: 2024/11/18 18:19:35 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player   pos_in_map(t_player pl)
{
	pl.x = pl.x * TILE_SIZE + (TILE_SIZE / 2);
	pl.y = pl.y * TILE_SIZE + (TILE_SIZE / 2);
	return (pl);
}

float	set_angle(t_player pl)
{
	float	ang;

	if (pl.dir == 'N')
		ang = 3 * M_PI / 2;
	else if (pl.dir == 'E')
		ang = 0;
	else if (pl.dir == 's')
		ang = M_PI / 2;
	else if (pl.dir == 'w')
		ang = M_PI;
	return (ang);
}

float	ft_normalize(float ang)
{
	if (ang < 0)
		ang += 2 * M_PI;
	if (ang >= 2 * M_PI)
		ang -= 2 * M_PI;
	return (ang);
}

t_cor	get_first_intesaction(t_player pl, int ang)
{
	t_cor	inter;

	inter.y = floor(pl.y / TILE_SIZE) * TILE_SIZE;
	inter.x = pl.x + (inter.y - pl.y) / tan(ang);
	return (inter);
}

int	hitt_wall(t_cor inter, t_map map)
{
	inter.x /= TILE_SIZE;
	inter.y /= TILE_SIZE;
	if (map.map[inter.y][inter.x] =='1')
		return (0);
	return (1);
}

int	ray_datiction_dwn(float ang)
{
	if (ang > M_PI && ang < 0)
		return (0);
	return (1);
}

int	ray_dariction_left(float ang)
{
	if (ang >= 0 && ang < M_PI / 2)
		return (0);
	if (ang > 3 * M_PI / 2 && ang < 0)
		return (0);
	return (1);
}

void	siting_up_steps(int	*x, int *y, float ang)
{
	if (!ray_dariction_dwn(ang))
		*x = -(*x);
	if (!ray_dariction_left(ang))
		*y = fabs(*y);
	else
		*y = -fabs(*y);
}

float	find_horiznatal_inter(t_player pl, float ang, t_map map)
{
	t_cor	inter;
	int		x_step;
	int		y_step;

	inter = get_first_intesaction(pl, ang);
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(ang);
	siting_up_steps(&y_step, &x_step, ang);
	while (hitt_wall(inter, map))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	return (sqr(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
}


t_cor	get_first_intesaction1(t_player pl, int ang)
{
	t_cor	inter;

	inter.x = floor(pl.x / TILE_SIZE) * TILE_SIZE ;
	inter.y = pl.y + (inter.x - pl.x) * tan(ang);
	return (inter);
}

