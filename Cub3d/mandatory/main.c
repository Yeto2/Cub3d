/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/30 22:43:32 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main(int ac, char const *av[])
{
    (void)av;
    t_data data;
    if (ac != 2)
    {
        ft_printf("Error\n"); // error
        exit(1);
    }
    check_extention(av[1]);
    data.map_path = ft_strdup(av[1]);
    if (fill_map_data(&data))
        return (ft_printf("Error\n"), 1);
    if (check_if_valid(&data))
        return (ft_printf("Error\n"), 1);
    if (prepare_data(&data))
        return (ft_printf("Error\n"), 1);
    esolate_check(&data);
    
    int i = 0;
    printf("player x = %d\n", data.player.x);
    printf("player y = %d\n", data.player.y);
    printf("player dir = %c\n", data.player.dir);
    printf("floor r: %d, g: %d, b: %d\n", data.floor.red, data.floor.green, data.floor.blue);
    printf("ciel r: %d, g: %d, b: %d\n", data.ciel.red, data.ciel.green, data.ciel.blue);
    printf("no = %s\n", data.no);
    printf("so = %s\n", data.so);
    printf("ea = %s\n", data.ea);
    printf("we = %s\n", data.we);
    printf("map path = %s\n", data.map_path);
    printf("map_h = %d\n", data.map.map_h);
    printf("map_w = %d\n", data.map.map_w);
    
    while (data.map.map[i])
    {
        ft_printf("%s\n", data.map.map[i]);
        i++;
    }
    return 0;
}
