/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:56:56 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/21 00:11:50 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
