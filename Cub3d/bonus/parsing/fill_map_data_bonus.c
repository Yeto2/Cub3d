/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:17:54 by yessemna          #+#    #+#             */
/*   Updated: 2024/11/01 12:53:49 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*prepare_line(char *line)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = g_malloc(ft_strlen(line) + 1, MALLOC);
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		ret[j] = line[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*read_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		print_err("empty file");
	return (line);
}

int	fill_map_data(t_data *data)
{
	char	*last_line;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open((data)->map_path, O_RDONLY, 0666);
	if (fd == -1)
		print_err("cannot open rhe map file");
	(data)->data_map = g_malloc(sizeof(char *) * (count_lines(data) + 1),
			MALLOC);
	if (!(data)->data_map)
		print_err("malloc failed");
	line = read_line(fd);
	while (line)
	{
		last_line = line;
		(data)->data_map[i++] = prepare_line(line);
		line = get_next_line(fd);
	}
	if (last_line[ft_strlen(last_line) - 1] == '\n' || !last_line)
		return (1);
	(data)->data_map[i] = NULL;
	return (0);
}
