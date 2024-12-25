/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rounded.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:42:30 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/25 07:56:21 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*trim_first_last(char *str)
{
	int	i;
	int	j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')
		i--;
	new = g_malloc(sizeof(char) * (i + 2), MALLOC);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

int	first_and_last(char *first, char *last)
{
	int		i;
	char	*trimed_first;
	char	*trimed_last;

	i = 0;
	trimed_first = trim_first_last(first);
	trimed_last = trim_first_last(last);
	while(trimed_first[i])
	{
		if (trimed_first[i] == '1' || trimed_first[i] == ' ')
			i++;
		else
			return (1);
	}
	i = 0;
	while(trimed_last[i])
	{
		if (trimed_last[i] == '1' || trimed_last[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	last_of_line(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
		return (1);
	return (0);
}

int	is_rounded(t_data **data)
{
	int	i;
	int	j;
	int	last;

	i = 1;
	j = 0;
	last = (*data)->map.map_h - 1;
	if (first_and_last((*data)->map.map[0], (*data)->map.map[last]))
		return (1);
	while ((*data)->map.map[i] && i < last)
	{
		j = 0;
		while ((*data)->map.map[i][j] == ' ')
			j++;
		if ((*data)->map.map[i][j] != '1' || last_of_line((*data)->map.map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_zero_surrounded(t_data **data)
{
	int	i;
	int	j;
	int	last;

	i = 1;
	j = 0;
	last = (*data)->map.map_h - 1;
	while ((*data)->map.map[i] && i < last)
	{
		j = 0;
		while ((*data)->map.map[i][j])
		{
			if ((*data)->map.map[i][j] == '0')
			{
				if ((*data)->map.map[i][j + 1] == ' '
					|| (*data)->map.map[i][j - 1] == ' '
					|| (*data)->map.map[i + 1][j] == ' '
					|| (*data)->map.map[i - 1][j] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
