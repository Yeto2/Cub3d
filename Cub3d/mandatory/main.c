/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:55:55 by yessemna          #+#    #+#             */
/*   Updated: 2024/10/20 12:16:42 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_extention(const char *file)
{
    int i;

    i = 0;
    while(file[i])
        i++;
    if(file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c' || file[i - 4] != '.')
        printf("Error\n"); // error
}

int count_lines(t_data *data)
{
    int fd;
    int i = 0;
    char *line;
    

    fd = open (data->map_path, O_RDONLY, 0666);
    if(fd == -1)
        printf("Error\n");// error
    while((line = get_next_line(fd)))
        i++;
    return i;
}

char *prepare_line(char *line)
{
    char *ret;
    int i;
    int j;

    i = 0;
    j = 0;
    ret = g_malloc(ft_strlen(line) + 1, MALLOC);
    while(line[i])
    {
        if(line[i] == '\n')
            break;
        ret[j] = line[i];
        i++;
        j++;
    }
    ret[j] = '\0';
    return ret;
}

int fill_map_data(t_data *data)
{
    int i;
    int fd;
    char *line;
    char *last_line;

    i = 0;
    fd = open (data->map_path, O_RDONLY, 0666);
    if(fd == -1)
        printf("Error\n");// error
    data->data_map = g_malloc(sizeof(char *) * count_lines(data) + 1, MALLOC);
    if(!data->data_map)
        printf("malloc failed\n");// error
    line = get_next_line(fd);
        if(!line)
            printf("empty file\n"); // error
        while (line)
        {
            last_line = line;
            if(!ft_strcmp(prepare_line(line), "\0"))
            {
                line = get_next_line(fd);
                last_line = line;
                continue;
            }
            data->data_map[i++] = prepare_line(line);
            line = get_next_line(fd);
        }
    if (last_line[ft_strlen(last_line) - 1] == '\n' || !last_line)
        return (1);
    data->data_map[i] = NULL;
    return 0;
}
int skip_spaces(char *line)
{
    int i = 0;
    
    while(is_space(line[i]))
        i++;
    if(line[i] == '\0')
        return (1);
    return (0);
}

void prepare_data(t_data *data)
{
    int i = 0;
    
    while (data->data_map[i])
    {
        if(!ft_strlen(data->data_map[i]) || skip_spaces(data->data_map[i]))
            i++;
        printf("-->%s\n", data->data_map[i]);
        i++;
    }
}

int main(int ac, char const *av[])
{
    (void)av;
    t_data data;
    if(ac != 2)
        printf("Error\n");
    check_extention(av[1]);
    data.map_path = ft_strdup(av[1]);
    if(fill_map_data(&data))
        return (printf("invalid map\n"), 1);
    prepare_data(&data);
    return 0;
}
