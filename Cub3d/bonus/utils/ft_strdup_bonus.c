/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:27:10 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/18 01:27:25 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	out = g_malloc(ft_strlen(s) + 1, MALLOC);
	while (s && s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
