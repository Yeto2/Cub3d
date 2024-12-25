/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:05:41 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/25 09:35:31 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
void	draw_player(mlx_image_t *img, int x_pl, int y_pl)
{
	int	raduis;
	int	x;
	int	y;

	raduis = 5;
	y = -5;
	while (y < raduis)
	{
		x = 5;
		while (x < raduis)
		{
			if (x * x + y * y <= raduis * raduis)
				if ((x_pl + x >= 0 && y_pl + y >= 0)
					&& (x_pl + x <= 200 && y_pl + y <= 200))
					{
						// printf("yes\n");
						mlx_put_pixel(img, x_pl + x, y_pl + y, 0xFF0000FF);
					}
			x++;
		}
		y++;
	}
}

int	draw_pixel(t_data *data, double x, double y)
{
	int i;
	int j;
	int	clr;

	clr = 0x7F7F7FFF;
	i = x / TILE_SIZE;
	j = y / TILE_SIZE;
	if (i < 0 || j < 0 || i >= data->map.map_w || j >= data->map.map_h)
		return (clr);
	if (data->map.map[j][i] == '1')
		clr = 0x000000FF;
	else if (data->map.map[j][i] == '0')
		clr = 0xFFFFFFFF;
	else if (data->map.map[j][i] == 'C' || data->map.map[j][i] == 'O')
		clr = 0xFFFFFF00;
	return (clr);
}

void	draw_map(t_data *data)
{
	t_pos	start;
	int	i;
	int	j;
	int	clr;
	
	j = 0;
	start.x = data->player.x - 5 * TILE_SIZE;
	start.y = data->player.y - 5 * TILE_SIZE;
	while (++j < 200)
	{
		i = 0;
		while (++i < 200)
		{	
			clr = draw_pixel(data, start.x + i / data->unite, start.y + j/ data->unite);
			mlx_put_pixel(data->mlx.img_m, i, j, clr);
		}
	}
}


void    render_2d_map(t_data *data)
{
	draw_map(data);
	draw_player(data->mlx.img_m, 100, 100);
}