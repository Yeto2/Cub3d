/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 04:32:26 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/27 07:05:00 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_strcut(char *str, char *cut)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (cut[j])
	{
		str[i] = cut[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	h_c_err(char *str)
{
	if (ft_strlen(str) > 3)
		print_err("Invalid color");
	if (is_alpha(str))
		print_err("Invalid color");
}
