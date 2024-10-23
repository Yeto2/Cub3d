/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/23 23:08:16 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void prepare(char *line, t_data **data)
{
    // int i = 0;
    // int j = 0;
    (void)data;
    char **tmp;

        tmp = ft_split(line, ' ');
        if(!tmp)
            ft_printf("Error\n");
        if(tmp[0][0] == 'S' && tmp[0][1] == 'O')
        {
            if((*data)->so)
                ft_printf("Error\n");
            (*data)->so = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'W'  && tmp[0][1] == 'E')
        {
            if((*data)->we)
                ft_printf("Error\n");
            (*data)->we = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'E'  && tmp[0][1] == 'A')
        {
            if((*data)->ea)
                ft_printf("Error\n");
            (*data)->ea = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'N'  && tmp[0][1] == 'O')
        {
            if((*data)->no)
                ft_printf("Error\n");
            (*data)->no = ft_strdup(tmp[1]);
        }
        else if (tmp[0][0] == 'F' || tmp[0][0] == 'C')
        {
            handle_color(tmp[1], tmp[0][0], data);
        }

        free(tmp);
}



int check_map_validity(t_data **data)
{
    int i = 0;
    
    while ((*data)->map.map[i])
    {
        printf("%s\n", (*data)->map.map[i]);
        i++;
    }
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
        ft_printf("Error\n");
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
    check_map_validity(&data);
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
    

    
    // color floor 
    return 0;
}
