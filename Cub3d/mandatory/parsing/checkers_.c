/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:13:22 by yessemna          #+#    #+#             */
/*   Updated: 2024/11/12 13:01:47 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	null_check(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!line[i])
		return (1);
	return (0);
}

int	dir(char c)
{
	if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
		return (1);
	return (0);
}
