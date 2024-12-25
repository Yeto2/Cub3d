/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:02:22 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/25 17:07:30 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

void	move_mouse(double xpos, double ypos, void *d)
{
	t_data		*data;
	int			mouse_x;
	int			mouse_y;
	static int	mouse_x_old;
	int			move_mouse;

	data = d;
	(void)xpos;
	(void)ypos;
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_M))
	{
		if (data->abe_mouse == 1)
			data->abe_mouse = 0;
		else
			data->abe_mouse = 1;
	}
	if (data->abe_mouse == 0)
	{
		return ;
	}
	mlx_get_mouse_pos(data->mlx.mlx_p, &mouse_x, &mouse_y);
	move_mouse = mouse_x - mouse_x_old;
	data->ang += (double)(move_mouse) *0.001;
	mouse_x_old = mouse_x;
}

// void 	enable_mouse(int keycode, void *d)
// {
// 	t_data	*data;

// 	data = d;
// 	if (keycode == MLX_KEY_M)
// 	{
// 		if (data->abe_mouse == 1)
// 			data->abe_mouse = 0;
// 		else
// 			data->abe_mouse = 1;
// 	}
// }

void	start_game(t_data *data)
{
	data->player = pos_in_map(data->player);
	data->ang = set_angle(data->player);
	data->scale = 20;
	data->unite = data->scale / TILE_SIZE;
	data->dor_open = 0;
	data->abe_mouse = 1;
	clear_image(data);
	ray_cast(data);
	// render_2d(data);
	// mlx_key_hook(data->mlx.mlx_p, enable_mouse, data);
	render_2d_map(data);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_r, 0, 0);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_m, 10, 10);
	data->default_img = mlx_texture_to_image(data->mlx.mlx_p,
			data->pl_txt);
	mlx_image_to_window(data->mlx.mlx_p, data->default_img, 80, 40);
	mlx_cursor_hook(data->mlx.mlx_p, move_mouse, data); // mouse event still not working
	mlx_loop_hook(data->mlx.mlx_p, pl_animation, data); // player animation need more work
	mlx_loop_hook(data->mlx.mlx_p, handell_keys, data);
	mlx_set_cursor_mode(data->mlx.mlx_p, MLX_MOUSE_DISABLED);
	mlx_loop(data->mlx.mlx_p);
}
