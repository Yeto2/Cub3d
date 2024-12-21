/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_angl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:46:06 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/19 22:20:06 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

t_player	pos_in_map(t_player pl)
{
	t_player	tmp;

	tmp.x = pl.x * TILE_SIZE + (TILE_SIZE / 2);
	tmp.y = pl.y * TILE_SIZE + (TILE_SIZE / 2);
	tmp.dir = pl.dir;
	return (tmp);
}

double	ft_normalize(double ang)
{
	if (ang < 0)
		ang += 2 * M_PI;
	if (ang >= 2 * M_PI)
		ang -= 2 * M_PI;
	return (ang);
}

double	set_angle(t_player pl)
{
	double	ang;

	ang = 0;
	if (pl.dir == 'N')
		ang = 3 * M_PI / 2;
	else if (pl.dir == 'E')
		ang = 0;
	else if (pl.dir == 'S')
		ang = M_PI / 2;
	else if (pl.dir == 'W')
		ang = M_PI;
	ang = ft_normalize(ang);
	return (ang);
}
