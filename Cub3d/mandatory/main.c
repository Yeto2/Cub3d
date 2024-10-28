/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/28 11:51:37 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void prepare(char *line, t_data **data)
{
    int i = 0;
    char **tmp;

        tmp = ft_split(line, ' ');
        while (tmp[i])
            i++;
        if (i != 2)
            print_err("Invalid map data");
            
        if(!tmp)
            print_err("Invalid map data");
        if(tmp[0][0] == 'S' && tmp[0][1] == 'O')
        {
            if((*data)->so)
                print_err("We already have a south texture");
            (*data)->so = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'W'  && tmp[0][1] == 'E')
        {
            if((*data)->we)
                print_err("We already have a west texture");
            (*data)->we = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'E'  && tmp[0][1] == 'A')
        {
            if((*data)->ea)
                print_err("We already have a east texture");
            (*data)->ea = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'N'  && tmp[0][1] == 'O')
        {
            if((*data)->no)
                print_err("We already have a north texture");
            (*data)->no = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'F' || tmp[0][0] == 'C')
            handle_color(tmp[1], tmp[0][0], data);
        else
            print_err("Invalid map data");
        free(tmp);
}

int first_and_last(char *first, char *last)
{
    int i = 0;
    while (first[i])
    {
        while(first[i] == ' ')
            i++;
        if (first[i] != '1')
            return 1;
        i++;
    }
    i = 0;
    while (last[i])
    {
        while(last[i] == ' ')
            i++;
        if (last[i] != '1')
            return 1;
        i++;
    }
    return 0;
}
int is_rounded(t_data **data)
{
    int i = 1;
    int j = 0;
    int last = (*data)->map.map_h - 1;
    
    if(first_and_last((*data)->map.map[0], (*data)->map.map[last]))
        return 1;
    while((*data)->map.map[i] && i < last)
    {
        j = 0;
        while((*data)->map.map[i][j] == ' ')
            j++;
        if((*data)->map.map[i][j] != '1' || (*data)->map.map[i][ft_strlen((*data)->map.map[i]) - 1] != '1')
            return 1;
        i++;
    }
    return 0;
}

int is_zero_surrounded(t_data **data)
{
    int i = 1;
    int j = 0;
    int last = (*data)->map.map_h - 1;

    while((*data)->map.map[i] && i < last)
    {
        j = 0;
        while((*data)->map.map[i][j])
        {
            if((*data)->map.map[i][j] == '0')
            {
                if ((*data)->map.map[i][j + 1] == ' ' || (*data)->map.map[i][j - 1] == ' ' || (*data)->map.map[i + 1][j] == ' ' || (*data)->map.map[i - 1][j] == ' ')
                    return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int check_map_validity(t_data **data)
{
    int i = 0;
    int j = 0;
    int player = 0;
    size_t width = (*data)->map.map_w;
    
    if(is_rounded(data))
        return 1;
    while ((*data)->map.map[i])
    {
        j = 0;
        while ((*data)->map.map[i][j])
        {
            if (dir((*data)->map.map[i][j]))
            {
                if (player)
                    return 1;
                player++;
                (*data)->player.x = j;
                (*data)->player.y = i;
                (*data)->player.dir = (*data)->map.map[i][j];
                (*data)->map.map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    if (player > 1 || player == 0)
        return 1;
    i = 0;
    while ((*data)->map.map[i])
    {
        if (ft_strlen((*data)->map.map[i]) < width)
        {
            while (ft_strlen((*data)->map.map[i]) < width)
            {
                (*data)->map.map[i] = join_char((*data)->map.map[i], ' ');
            }
        }
        i++;
    }
    if(is_zero_surrounded(data))
        return 1;
    return 0;
}

void esolate_check(t_data *data)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int height = 0;
    size_t width = 0;
    
    init_data_vars(&data);
    while (data->map_dtls[i] && j < 6)
    {
        prepare(data->map_dtls[i], &data);
        j++;
        i++;
    }
    if (data->map_dtls[j] && data->map_dtls[j][0] != '1')
    {
        ft_printf("Error\n"); //Error
        exit(1);
    }
    
    while (data->map_dtls[j])
    {
        height++;
        j++;
    }
    data->map.map = g_malloc(sizeof(char *) * (height + 1), MALLOC);
    width = ft_strlen(data->map_dtls[i]);
    while (data->map_dtls[i])
    {
            data->map.map[k++] = ft_strdup(data->map_dtls[i]);
            i++;
            if (ft_strlen(data->map_dtls[i]) > width)
                width = ft_strlen(data->map_dtls[i]);
    }
    data->map.map[k] = NULL;
    data->map.map_h = height;
    data->map.map_w = width;
    if (check_map_validity(&data))
    {
        ft_printf("Error\n");// error
        exit(1);
    }
}

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
