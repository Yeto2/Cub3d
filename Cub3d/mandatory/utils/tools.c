/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 08:55:52 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/29 23:59:08 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void init_data_vars(t_data **data)
{
    (*data)->no = NULL;
    (*data)->so = NULL;
    (*data)->ea = NULL;
    (*data)->we = NULL;
}

void check_extention(const char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    if (file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' || file[i - 4] != '.')
    {
        ft_printf("Error\n"); // error
        exit(1);
    }
}

int count_lines(t_data *data)
{
    int fd;
    int i = 0;
    char *line;

    fd = open(data->map_path, O_RDONLY, 0666);
    if (fd == -1)
    {
        ft_printf("Error\n"); // error
        exit(1);
    }
    while ((line = get_next_line(fd)))
        i++;
    return i;
}

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_alpha(char *c)
{
    int i=0;
    while (c[i])
    {
        if (ft_isalpha(c[i]))
        {
            return 1;
        }
        i++;
    }
    if (ft_atoi(c) < 0 || ft_atoi(c) > 255)
        return 1;
    return 0;
}
