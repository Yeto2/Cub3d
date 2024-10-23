/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:09:45 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/22 14:10:04 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sign);
}
