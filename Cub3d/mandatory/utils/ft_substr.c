/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:55:52 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/16 19:56:27 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen ;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, 1));
	if (len >= slen - start)
		len = slen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}