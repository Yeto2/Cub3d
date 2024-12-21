/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/21 01:22:55 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	data->textures.so = set_png_texture(data, data->so);
	data->textures.no = set_png_texture(data, data->no);
	data->textures.ea = set_png_texture(data, data->ea);
	data->textures.we = set_png_texture(data, data->we);
}

void f()
{
	system("leaks cub3d");
}

int	main(int ac, char const *av[])
{
	t_data	data;
	
	atexit(f);
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
	init_textures(&data);
	start_game(&data);
	return (0);
}
