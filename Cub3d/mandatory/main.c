/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 06:27:26 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	data->textures.so = set_png_texture(data, data->so);
	data->textures.we = set_png_texture(data, data->we);
	data->textures.no = set_png_texture(data, data->no);
	data->textures.ea = set_png_texture(data, data->ea);
}

int	main(int ac, char const *av[])
{
	t_data		data;
	t_fd_col	collector;

	collector.count = 0;
	if (ac != 2)
		print_err("Error\n");
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
	init_textures(&data);
	start_game(&data);
	terminate_mlx(&data);
	return (0);
}
