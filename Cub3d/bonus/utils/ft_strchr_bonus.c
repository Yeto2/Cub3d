/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:02:03 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/19 13:00:12 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cr;
	char			*str;
	int				i;

	i = 0;
	cr = (unsigned char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == cr)
			return (str + i);
		i++;
	}
	if (str[i] == cr)
		return (str + i);
	return (0);
}
