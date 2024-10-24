/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:09 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/24 17:57:20 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*join_char(char *str, char c)
{
	char	*out;
	int		i;
	int		len;

	i = 0;
	if (!str)
		str = ft_strdup("");
	len = ft_strlen(str);
	out = g_malloc(len + 2, MALLOC);
	while (str[i] != '\0')
	{
		out[i] = str[i];
		i++;
	}
	out[i] = c;
	out[i + 1] = '\0';
	return (out);
}
