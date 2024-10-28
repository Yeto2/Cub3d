/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:35:01 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/28 11:19:24 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_if_valid(t_data *data)
{
    int i = 0;

    while (data->data_map[i] && data->data_map[i][0] != '1' && data->data_map[i][0] != '0')
        i++;
    while (data->data_map[i])
    {
        if (data->data_map[i][0] == '1' || data->data_map[i][0] == '0')
            i++;
        else if (data->data_map[i][0] == ' ')
        {
            if (skip_spc_check(data->data_map[i]))
                return (1);
            i++;
        }
        else
            return (1);
    }
    return (0);
}


int prepare_data(t_data *data)
{
    int i = 0;
    int j = 0;
    int len = 0;

    while ((data)->data_map[i])
    {
        if (!valid_letter((data)->data_map[i]) || !(data)->data_map[i][0])
            len++;
        else if (!null_check((data)->data_map[i]))
            print_err("Invalid map data");
        i++;
    }
    (data)->map_dtls = g_malloc(sizeof(char *) * (len + 1), MALLOC);
    if (!(data)->map_dtls)
        printf("malloc failed\n"); // error
    i = 0;
    while ((data)->data_map[i])
    {
        if (!valid_letter((data)->data_map[i]))
        {
            // len++; // why?
            (data)->map_dtls[j++] = ft_strdup((data)->data_map[i]);
        }
        i++;
    }
    data->map_dtls[j] = NULL;
    return 0;
}

void handle_color(char *color, char type, t_data **data)
{
    int i = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    char **tmp;

    tmp = ft_split(color, ',');
    if(!tmp)
        print_err("Invalid color");
    while (tmp[i])
    {
        if (is_alpha(tmp[i]))
            print_err("Invalid color");
        if (i == 0)
            r = ft_atoi(tmp[i]);
        else if (i == 1)
            g = ft_atoi(tmp[i]);
        else if (i == 2)
            b = ft_atoi(tmp[i]);
        i++;
    }
    if (i != 3)
        print_err("Invalid color");
    if (type == 'F')
    {
        (*data)->ciel.red = r;
        (*data)->ciel.green = g;
        (*data)->ciel.blue = b;
    }
    else if (type == 'C')
    {
        (*data)->floor.red = r;
        (*data)->floor.green = g;
        (*data)->floor.blue = b;
    }
    free(tmp);
}
