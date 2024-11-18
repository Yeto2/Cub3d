/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:10:41 by lamhal            #+#    #+#             */
/*   Updated: 2024/11/17 15:15:54 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	increment(int a, int b, int *cur)
{
	if (b > a)
		*cur += 1;
	else
		*cur -= 1;
}

int	sloop_less_than_one(t_cor a, t_cor b)
{
	int	dx;
	int	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) < abs(dy))
		return (0);
	return (1);
}

void	put_pixel(t_data *data, int x, int y, int i)
{
	int		tmp;

	if (i == 1)
	{
		tmp = x;
		x = y;
		y = tmp;
	}
	if (x < 0 || x > (int)(data->mlx.img_m)->width || y < 0
		|| y > (int)(data->mlx.img_m)->height)
		return ;
	mlx_put_pixel(data->mlx.img_m, x, y, data->clr);
}

void	bresnham_line_alg(t_cor a, t_cor b, t_data *data, int i)
{
	int		dx;
	int		dy;
	int		p;
	t_cor	cur;

	cur = a;
	dx = b.x - a.x;
	dy = b.y - a.y;
	p = 2 * abs(dy) - abs(dx);
	put_pixel(data, cur.x, cur.y, i);
	while (cur.y != b.y || cur.x != b.x)
	{
		increment(a.x, b.x, &cur.x);
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			p += 2 * abs(dy) - 2 * abs(dx);
			increment(a.y, b.y, &cur.y);
		}
		put_pixel(data, cur.x, cur.y, i);
	}
}

void	draw_line(t_cor a, t_cor b, t_data *data)
{
	int	tmp;

	if (sloop_less_than_one(a, b))
		bresnham_line_alg(a, b, data, 0);
	else
	{
		tmp = a.x;
		a.x = a.y;
		a.y = tmp;
		tmp = b.x;
		b.x = b.y;
		b.y = tmp;
		bresnham_line_alg(a, b, data, 1);
	}
}
