/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/05 16:59:15 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_textures(t_data *data)
{
	data->textures.so = set_png_texture(data, data->so);
	data->textures.no = set_png_texture(data, data->no);
	data->textures.ea = set_png_texture(data, data->ea);
	data->textures.we = set_png_texture(data, data->we);
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
	init_textures(&data);
	start_game(&data);
	// set_player(&data);

	
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
