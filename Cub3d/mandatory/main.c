/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/11/05 18:25:25 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_player(mlx_image_t *img, int player_x, int player_y) {
    int radius =9;
	int x = -radius;
	int y = -radius;
	
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				if(player_x + x >= 0 && player_x + x < S_W && player_y + y >= 0 && player_y + y < S_H)
					mlx_put_pixel(img, player_x + x, player_y + y, 0xFF0000FF);
			}
			x++;
		}
		y++;
	}
}
void draw_rect(mlx_image_t *img, int x, int y, int w, int h, int color)
{
	int i = 0;
	int j = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (x + j >= 0 && x + j < S_W && y + i >= 0 && y + i < S_H)
				mlx_put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void draw_map(mlx_image_t *img, t_data *data)
{
	
	int x = 0;
	int y = 0;
	
	int width  = round((float)(img->width) / data->map.map_w);
	int height = round((float)(img->height) / data->map.map_h);
	// printf("height = %d\n", height);
	while(y < data->map.map_h)
	{
		x = 0;
		while(x < data->map.map_w)
		{
			if (data->map.map[y][x] == '1')
				draw_rect(img, x * width , y * height, width, height, 0x000000FF);
			else if (data->map.map[y][x] == '0')
				draw_rect(img, x * width, y * height, width, height, 0xFFFFFFFF);
			else
				draw_rect(img, x * width, y * height, width, height, 0x000000FF);
			x++;
		}
		y++;
	}
}

void ft_keypress(void *param)
{
	t_data *data = param;
	
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_W))
		printf("Wwawawawawa\n");
}

void start_game(t_data *data)
{

	mlx_image_t *img_player;
	mlx_image_t *img_map;

	data->mlx.mlx_p = mlx_init(S_W, S_H, "Cub3d", 0);
	
	img_player = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
	img_map = mlx_new_image(data->mlx.mlx_p,S_W , S_H);
	
	draw_map(img_map, data);
	
	int width = round((float)(img_map->width) / data->map.map_w);
	int height = round((float)(img_map->height) / data->map.map_h);

	draw_player(img_player, data->player.x * width, data->player.y * height);
	
	mlx_loop_hook(data->mlx.mlx_p, ft_keypress, data);
	
	mlx_image_to_window(data->mlx.mlx_p, img_map, 0,0);
	mlx_image_to_window(data->mlx.mlx_p, img_player, 0,0);
	mlx_loop(data->mlx.mlx_p);
}

int main(int ac, char const *av[])
{
	t_data  data;

	if (ac != 2)
		print_err("Error\n");
	check_extention(av[1]);
	data.map_path = ft_strdup(av[1]);
	if (fill_map_data(&data))
		return (ft_printf("Error\n"), 1);
	if (check_if_valid(&data))
		return (ft_printf("Error\n"), 1);
	if (prepare_data(&data))
		return (ft_printf("Error\n"), 1);
	esolate_check(&data);
	start_game(&data);

	return 0;
}
