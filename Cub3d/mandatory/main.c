/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/11/17 17:36:02 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_player(mlx_image_t *img, int player_x, int player_y) {
    int radius = 5;
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

// void draw_rect(mlx_image_t *img, int x, int y, int w, int h, int color)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < h)
// 	{
// 		j = 0;
// 		while (j < w)
// 		{
// 			if (x + j >= 0 && x + j < S_W && y + i >= 0 && y + i < S_H)
// 				mlx_put_pixel(img, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void draw_map(mlx_image_t *img, t_data *data)
// {
	
// 	int x = 0;
// 	int y = 0;
	
// 	int width  = round((float)(img->width) / data->map.map_w);
// 	int height = round((float)(img->height) / data->map.map_h);
// 	// printf("height = %d\n", height);
// 	while(y < data->map.map_h)
// 	{
// 		x = 0;
// 		while(x < data->map.map_w)
// 		{
// 			if (data->map.map[y][x] == '1')
// 				draw_rect(img, x * width , y * height, width, height, 0x000000FF);
// 			else if (data->map.map[y][x] == '0')
// 				draw_rect(img, x * width, y * height, width, height, 0xFFFFFFFF);
// 			else
// 				draw_rect(img, x * width, y * height, width, height, 0x000000FF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear_img(mlx_image_t *img)
{
	uint32_t i = 0;
	uint32_t j = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, get_rgba(0, 0, 0, 0));
			j++;
		}
		i++;
	}
}

void ft_keypress(void *param)
{
	t_data *data = param;
	
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_W))
	{
		data->player.y -= 5;
	}
	else if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_S))
	{
		data->player.y += 5;
	}
	else if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_A))
	{
		data->player.x -= 5;
	}
	else if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_D))
	{
		data->player.x += 5;
	}
	printf("--------> mlx_img = %p\n", data->mlx.img_m);
	clear_img(data->mlx.img_p);
	draw_player(data->mlx.img_p, data->player.x, data->player.y);
}

void start_game(t_data *data)
{
	// t_cor a;
	// t_cor b;

	// a.x = -1;
	// a.y = 10;
	// b.x = 50;
	// b.y = 10;
	// data->clr = 0x000000FF;
	data->mlx.mlx_p = mlx_init(S_W, S_H, "Cub3d", 0);
	
	data->mlx.img_p = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
	data->mlx.img_m = mlx_new_image(data->mlx.mlx_p,S_W , S_H);
	
	// draw_line(a, b , data);
	draw_map(data);
	
	
	// int width = round((float)((data->mlx.img_m)->width) / data->map.map_w);
	//int height = round((float)((data->mlx.img_m)->height) / data->map.map_h);

	data->player.x = (data->player.x * data->scale) + (data->scale / 2);
	data->player.y = (data->player.y * data->scale) + (data->scale / 2);
	draw_player(data->mlx.img_p, data->player.x, data->player.y);
	
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_m, 0,0);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_p, 0,0);
	mlx_loop_hook(data->mlx.mlx_p, ft_keypress, data);
	//  0x60400008e810
	//  0x60400008c810
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
	
	// int	i = 0;
	
	//print map
	// while (i < data.map.map_h)
	// {
	// 	printf("%s\n", data.map.map[i]);
	// 	i++;
	// }
	// printf("data.map_path = %s\n", data.map_path);
	// printf("data.no = %s\n", data.no);
	// printf("data.so = %s\n", data.so);
	// printf("data.ea = %s\n", data.ea);
	// printf("data.we = %s\n", data.we);
	// printf("data.player.x = %d\n", data.player.x);
	// printf("data.player.y = %d\n", data.player.y);
	// printf("data.map.map_w = %d\n", data.map.map_w);
	// printf("data.map.map_h = %d\n", data.map.map_h);

	return 0;
}
