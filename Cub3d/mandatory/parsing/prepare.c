/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:55:11 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/30 19:55:28 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void prepare(char *line, t_data **data)
{
    int i = 0;
    char **tmp;

        tmp = ft_split(line, ' ');
        if(!tmp)
            print_err("Invalid map data");
        while (tmp[i])
            i++;
        if (i != 2)
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
