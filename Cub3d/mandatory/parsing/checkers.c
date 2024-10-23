/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:21:30 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/23 20:24:38 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int WSNECF1(char c)
{
    if (c == 'S' || c == 'W' || c == 'E' || c == 'N' || c == 'C' || c == 'F' || c == '1')
        return 1;
    return 0;
}

int WSNE_CF1(char *line)
{
    if (line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == 'N' || line[0] == ' ' || line[0] == 'C' || line[0] == 'F' || line[0] == '1')
        return 1;
    return 0;
}

int skip_spc_check(char *line)
{
    int i = 0;

    while (is_space(line[i]))
    {
        i++;
    }
    if (!WSNECF1(line[i]))
        return (1);
    return (0);
}

int valid_letter(char *line)
{
    if (WSNE_CF1(line))
    {
        if (line[0] == ' ' && skip_spc_check(line))
            return 1;
        return (0);
    }
    return 1;
}