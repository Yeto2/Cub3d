/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:38:17 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/03 09:41:58 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    ft_color(int r, int g, int b, int a)
{
    return ((((r * 256 + g) * 256) + b) * 256 + a);
}

int    ft_texture_color(unsigned int c)
{
    int    r;
    int    g;
    int    b;
    int    a;

    a = c % 256;
    c /= 256;
    b = c % 256;
    c /= 256;
    g = c % 256;
    c /= 256;
    r = c;
    return (ft_color(a, b, g, r));
}