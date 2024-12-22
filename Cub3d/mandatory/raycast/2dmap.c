/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:02:22 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/22 09:37:34 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calculate_scale(t_data *data)
{
	int	scale;
	int	width;
	int	height;

	width = round((float)(data->mlx.img_m)->width / data->map.map_w);
	height = round((float)(data->mlx.img_m)->height / data->map.map_h);
	if (width < height)
		scale = width;
	else
		scale = height;
	return (scale);
}

uint32_t	get_coller(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear_image(t_data *data)
{
	int	i;
	int	j;
	int	clr;

	j = -1;
	clr = 255 << 24 | 255 << 16 | 255 << 8 | 0;
	while (++j < S_H)
	{
		i = -1;
		while (++i < S_W)
			mlx_put_pixel(data->mlx.img_r, i, j, clr);
	}
}

void	start_game(t_data *data)
{
	data->player = pos_in_map(data->player);
	data->ang = set_angle(data->player);
	data->mlx.mlx_p = mlx_init(S_W, S_H, "cub3d", 0);
	data->mlx.img_m = mlx_new_image(data->mlx.mlx_p, 450, 200);
	if (data->mlx.img_m == NULL)
	{
		// terminate_mlx(data);
		print_err("Error\nimage failed to load");
	}
	data->mlx.img_r = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
	if (data->mlx.img_r == NULL)
	{
		// terminate_mlx(data);
		print_err("Error\nimage failed to load");
	}
	//data->scale = calculate_scale(data);
	data->unite = data->scale / TILE_SIZE;
	clear_image(data);
	ray_cast(data);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_r, 0, 0);
	mlx_loop_hook(data->mlx.mlx_p, handell_keys, data);
	mlx_loop(data->mlx.mlx_p);
}
