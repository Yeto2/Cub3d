/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:23:54 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/05 17:03:52 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void load_weapon_images(t_data *data)
// {
//     int i = 0;
// 	t_mlx *mlx;

// 	mlx = &data->mlx;
//     while (i < NUM_FRAMES)
//     {
//         char *filename = ft_strjoin("path/to/weapon/frame", ft_itoa(i), 0); // Create file path
//         data->weapon_frames[i] = set_png_texture(data, filename);
//         free(filename);
//         i++;
//     }
// }

// void draw_weapon(t_data *data)
// {
// 	t_mlx *mlx;
// 	int curr;
	
// 	mlx = &data->mlx;
// 	curr = data->current_frame;

//     int x = (S_W / 2) - (80 / 2); // Centering it
//     int y = S_H - 90; // Bottom of the screen
	
// 	data->mlx.img_p = mlx_new_image(mlx->mlx_p, 100, 100);
	
	
// 	mlx_image_to_window(mlx->mlx_p, mlx->img_p, x, y);
//     // mlx_put_image_to_window(mlx->mlx_p, mlx->img, data->weapon_frames[curr], x, y);
// }

// void update_animation(t_data *data) {
//     data->current_frame = (data->current_frame + 1) % NUM_FRAMES; // Loop through frames
// }

// void main_loop(void *data) {
//     update_animation(data);
//     // draw_weapon(data);
// }
void set_player(t_data *data)// test
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	data->current_frame = 0;
	mlx_texture_t *texture;
	mlx_image_t		*img;
	texture = mlx_load_png("./mandatory/images/player/StechkinEx18.png");
	
	img = mlx_texture_to_image(mlx->mlx_p, texture);
	
	mlx_image_to_window(mlx->mlx_p, img, 30, 30);
}


// void set_player(t_data *data)
// {
// 	t_mlx	*mlx;

// 	mlx = &data->mlx;
// 	data->current_frame = 0;
// 	    // Initialize MLX, load images, etc.
//     // load_weapon_images(data);
//     // mlx_key_hook(mlx->img, handle_keypress, &mlx);
// 	// mlx_loop_hook(mlx->mlx_p, main_loop, &data);
// 	mlx_texture_t *texture;
// 	mlx_image_t		*img;
// 	texture = mlx_load_png("/images/player/StechkinEx4.png");
// 	// data->mlx.img_p = mlx_new_image(mlx->mlx_p, 100, 100);
	
// 	img = mlx_texture_to_image(mlx->mlx_p, texture);
	
// 	mlx_image_to_window(mlx->mlx_p, img, 10, 10);
//     mlx_loop(mlx->mlx_p);
// }
