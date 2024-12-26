/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 06:54:04 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

mlx_image_t	*set_image(t_data *data, mlx_texture_t *textures)
{
	mlx_image_t	*img;

	if (!textures)
		print_err("failed to load texture\n");
	img = mlx_texture_to_image(data->mlx.mlx_p, textures);
	if (!img)
		print_err("failed to load texture\n");
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
	data->pl_txt = set_png_texture(data,
			"./bonus/images/player/Stechkin01.png");
	data->door_txt = set_png_texture(data, "./bonus/images/walls/door.png");
	data->default_img = set_image(data, data->pl_txt);
}

int	main(int ac, char const *av[])
{
	t_data		data;
	t_fd_col	collector;

	if (ac != 2)
		print_err("Error\n");
	collector.count = 0;
	check_extention(av[1]);
	data.map_path = ft_strdup(av[1]);
	if (fill_map_data(&data, &collector))
		return (ft_printf("Error\n"), 1);
	close_all_fds(&collector);
	if (check_if_valid(&data))
		return (ft_printf("Error\n"), 1);
	if (prepare_data(&data))
		return (ft_printf("Error\n"), 1);
	esolate_check(&data);
	init_player(&data);
	init_textures(&data);
	start_game(&data);
	terminate_mlx(&data);
	return (0);
}
