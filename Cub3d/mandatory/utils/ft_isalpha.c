/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:56:20 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/19 12:56:42 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
