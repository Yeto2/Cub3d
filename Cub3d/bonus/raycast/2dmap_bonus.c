/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:02:22 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/24 20:11:04 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

// int	calculate_scale(t_data *data)
// {
// 	int	scale;
// 	int	width;
// 	int	height;

// 	width = round((float)(data->mlx.img_m)->width / data->map.map_w);
// 	height = round((float)(data->mlx.img_m)->height / data->map.map_h);
// 	if (width < height)
// 		scale = width;
// 	else
// 		scale = height;
// 	return (scale);
// }

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


void	move_mouse(double x_pos, double y_pos, void *arg) // move mouse function
{
	t_data	*data;
	double	x;

	(void) y_pos;
	data = (t_data *)arg;
	x = x_pos - (S_W / 2);
	data->ang += x * 0.001;
	mlx_set_mouse_pos(data->mlx.mlx_p, S_W / 2, S_H / 2);
	printf("x = %f\n", x);
}


void	start_game(t_data *data)
{
	data->player = pos_in_map(data->player);
	data->ang = set_angle(data->player);
	data->scale = 20;
	data->unite = data->scale / TILE_SIZE;
	data->dor_open = 0;
	clear_image(data);
	ray_cast(data);
	// render_2d(data);
	render_2d_map(data);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_r, 0, 0);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_m, 10, 10);
	data->default_img = mlx_texture_to_image(data->mlx.mlx_p, data->pl_txt);
	mlx_image_to_window(data->mlx.mlx_p, data->default_img, 80, 40);
	// mlx_cursor_hook(data->mlx.mlx_p, move_mouse, &data); // mouse event still not working
	mlx_loop_hook(data->mlx.mlx_p, pl_animation, data); // player animation need more work
	mlx_loop_hook(data->mlx.mlx_p, handell_keys, data);
	mlx_set_cursor_mode(data->mlx.mlx_p, MLX_MOUSE_DISABLED);
	mlx_loop(data->mlx.mlx_p);
}


