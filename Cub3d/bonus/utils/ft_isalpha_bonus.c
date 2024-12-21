/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:56:20 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/21 00:11:56 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	is_alpha(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (ft_isalpha(c[i]))
			return (1);
		i++;
	}
	if (ft_atoi(c) < 0 || ft_atoi(c) > 255)
		return (1);
	return (0);
}
