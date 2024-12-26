/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:21:30 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 02:56:37 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	wsnecf1(char c)
{
	if (c == 'S' || c == 'W' || c == 'E' || c == 'N'
		|| c == 'C' || c == 'F' || c == '1' || c == 'D')
		return (1);
	return (0);
}

int	wsne_cf1(char *ln)
{
	if (ln[0] == 'S' || ln[0] == 'W' || ln[0] == 'E' || ln[0] == 'N'
		|| ln[0] == ' ' || ln[0] == 'C' || ln[0] == 'F'
		|| ln[0] == '1' || ln[0] == '0' || ln[0] == 'D')
		return (1);
	return (0);
}

int	skip_spc_check(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!wsnecf1(line[i]))
		return (1);
	return (0);
}

int	valid_letter(char *line)
{
	if (wsne_cf1(line))
	{
		if (line[0] == ' ' && skip_spc_check(line))
			return (1);
		return (0);
	}
	return (1);
}
