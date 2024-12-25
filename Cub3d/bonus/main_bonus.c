/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/25 09:33:22 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

mlx_image_t	*set_image(t_data *data, mlx_texture_t *textures)
{
	mlx_image_t	*img;
	
	if(!textures)
		print_err("failed to load texture\n"); // here
	img = mlx_texture_to_image(data->mlx.mlx_p, textures);
	if (!img)
		print_err("failed to load texture\n"); // here
	return (img);
}

void	init_textures(t_data *data)
{
	data->textures.so = set_png_texture(data, data->so);
	data->textures.no = set_png_texture(data, data->no);
	data->textures.ea = set_png_texture(data, data->ea);
	data->textures.we = set_png_texture(data, data->we);
	data->mlx.mlx_p = mlx_init(S_W, S_H, "cub3d", 0);
	data->mlx.img_m = mlx_new_image(data->mlx.mlx_p, 200, 200);
	data->mlx.img_r = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
	// data->mlx.img_p = mlx_new_image(data->mlx.mlx_p, 200, 200);
	data->pl_txt = set_png_texture(data, "./bonus/images/player/Stechkin01.png");
	data->door_txt = set_png_texture(data, "./bonus/images/walls/door.png");
	data->default_img = set_image(data, data->pl_txt);
}

// void f()
// {
// 	system("leaks cub3d");
// }

int	main(int ac, char const *av[])
{
	t_data	data;
	
	// atexit(f);
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
	init_player(&data);
	init_textures(&data);
	start_game(&data);
	return (0);
}
