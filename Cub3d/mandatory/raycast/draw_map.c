/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:50:52 by lamhal            #+#    #+#             */
/*   Updated: 2024/11/17 17:32:57 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		calculate_scale(t_data *data)
{
	int scale;
	int width;
	int	height;

	width = round((float)(data->mlx.img_m)->width / data->map.map_w);
	height = round((float)(data->mlx.img_m)->height / data->map.map_h);
	if (width < height)
		scale = width;
	else
		scale = height;
	return (scale);
}

void	draw_rect(t_data *data, int x, int y, int scale)
{
	t_cor	a;
	t_cor	b;
	int		i;
	
	if (data->map.map[y][x] == '1')
		data->clr = 0x000000FF;
	else if (data->map.map[y][x] == '0')
		data->clr = 0xFFFFFFFF;
	i = 0;
	while (i <= scale)
	{
		a.x = x * scale ;
		a.y = y * scale + i;
		b.x = x * scale + scale;
		b.y = y * scale + i;
		draw_line(a, b, data);
		i++;
	}
}

void	draw_limes(t_data *data, int scale)
{
	int i;
	int	j;
	t_cor	a;
	t_cor	b;
	
	j = 0;
	i = 0;
	data->clr = 0x000000FF;
	while (j < data->map.map_h)
	{
		a.x = 0;
		a.y = j * scale;
		b.x = data->map.map_w * scale;
		b.y = j * scale;
		draw_line(a, b, data);
		j++;
	}
	while (i < data->map.map_w)
	{
		a.x = i * scale;
		a.y = 0;
		b.x = i * scale;
		b.y = data->map.map_h * scale;
		draw_line(a, b, data);
		i++;
	}
}

void    draw_map(t_data *data)
{
	int	i;
	int	j;
	int	scale;

	j = -1;
	scale = calculate_scale(data);
	data->scale = scale;
	while (++j < data->map.map_h)
	{
		i = -1;
		while (++i < data->map.map_w)
			draw_rect(data, i, j, scale);
	}
	draw_limes(data, scale);
}