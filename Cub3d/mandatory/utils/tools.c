/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 08:55:52 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 06:14:49 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	init_data_vars(t_data **data)
{
	(*data)->no = NULL;
	(*data)->so = NULL;
	(*data)->ea = NULL;
	(*data)->we = NULL;
}

void	check_extention(const char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u'
		|| file[i - 3] != 'c' || file[i - 4] != '.')
		print_err("Error\n");
}

int	count_lines(t_data *data, t_fd_col *collector)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = ft_open(collector, data->map_path, O_RDONLY, 0666);
	if (fd == -1)
		print_err("Error\n");
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
