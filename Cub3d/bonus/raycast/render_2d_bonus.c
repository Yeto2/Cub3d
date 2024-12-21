/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:12:47 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/21 03:34:52 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_rect(t_data *data, int x, int y, int scale)
{
	int		i;
	int		j;
	int		tmp_x;
	int		tmp_y;

	tmp_x = x * scale;
	tmp_y = y * scale;
	if (data->map.map[y][x] == '1')
		data->clr = 0x000000FF;
	else if (data->map.map[y][x] == '0')
		data->clr = 0xFFFFFFFF;
	i = 0;
	while (i <= scale)
	{
		j = 0;
		while (j <= scale)
		{
			mlx_put_pixel(data->mlx.img_m, tmp_x + i, tmp_y + j, data->clr);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	scale;

	(1) && (j = -1, scale = data->scale);
	while (++j < data->map.map_h)
	{
		i = -1;
		while (++i < data->map.map_w)
			draw_rect(data, i, j, scale);
	}
	j = 0;
	while (++j < data->map.map_h)
	{
		i = -1;
		while (++i < data->map.map_w * data->scale)
			mlx_put_pixel(data->mlx.img_m, i, j * scale, 0x000000FF);
	}
	i = 0;
	while (++i < data->map.map_w)
	{
		j = 0;
		while (++j < data->map.map_h * data->scale)
			mlx_put_pixel(data->mlx.img_m, i * scale, j, 0x000000FF);
	}
}

void	draw_player(mlx_image_t *img, int x_pl, int y_pl)
{
	int	raduis;
	int	x;
	int	y;

	raduis = 2;
	y = -2;
	while (y < raduis)
	{
		x = -2;
		while (x < raduis)
		{
			if (x * x + y * y <= raduis * raduis)
				if ((x_pl + x >= 0 && y_pl + y >= 0)
					&& (x_pl + x <= S_W && y_pl + y <= S_H))
					mlx_put_pixel(img, x_pl + x, y_pl + y, 0xFF0000FF);
			x++;
		}
		y++;
	}
}

void	render_2d(t_data *data)
{
	draw_map(data);
	data->tmp_pl.x = data->player.x * data->unite;
	data->tmp_pl.y = data->player.y * data->unite;
	draw_player(data->mlx.img_m, data->tmp_pl.x, data->tmp_pl.y);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_m, 10, 10);
}
