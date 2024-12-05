/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:37:19 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/05 12:43:29 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// ft_itoa

char    *ft_itoa(int n)
{
    char	*str;
    int		len;
    int		nbr;

    len = 1;
    nbr = n;
    while (nbr /= 10)
        len++;
    if (n < 0)
        len++;
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n < 0)
        str[0] = '-';
    while (len-- > (n < 0))
    {
        str[len] = (n % 10) * (n < 0 ? -1 : 1) + '0';
        n /= 10;
    }
    return (str);
}




