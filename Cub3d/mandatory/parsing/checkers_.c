/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:13:22 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/30 23:13:58 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int null_check(char *line)
{
    int i = 0;
    
    while (is_space(line[i]))
        i++;
    if (!line[i])
        return (1);
    return (0);
}

int dir(char c)
{
    if (c == 'A' || c == 'S' || c == 'D' || c == 'W')
        return 1;
    return 0;
}
