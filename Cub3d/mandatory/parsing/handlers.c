/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:35:01 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/19 14:19:13 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_if_valid(t_data *data)
{
	int	i;

	i = 0;
	while (data->data_map[i] && data->data_map[i][0] != '1'
		&& data->data_map[i][0] != '0')
		i++;
	while (data->data_map[i])
	{
		if (data->data_map[i][0] == '1' || data->data_map[i][0] == '0')
			i++;
		else if (data->data_map[i][0] == ' ')
		{
			if (skip_spc_check(data->data_map[i]))
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	prepare_data(t_data *data)
{
	int	i;
	int	j;
	int	len;

	(1) && (i = 0, j = 0, len = 0);
	while ((data)->data_map[i])
	{
		if (!valid_letter((data)->data_map[i]) || !(data)->data_map[i][0])
			len++;
		else if (!null_check((data)->data_map[i]))
			print_err("Invalid map data");
		i++;
	}
	(data)->map_dtls = g_malloc(sizeof(char *) * (len + 1), MALLOC);
	if (!(data)->map_dtls)
		print_err("Malloc failed");
	i = 0;
	while ((data)->data_map[i])
	{
		if (!valid_letter((data)->data_map[i]))
			(data)->map_dtls[j++] = ft_strdup((data)->data_map[i]);
		i++;
	}
	data->map_dtls[j] = NULL;
	return (0);
}

void	ciel(t_data **data, int *r, int *g, int *b)
{
	(*data)->ciel.r = *r;
	(*data)->ciel.g = *g;
	(*data)->ciel.b = *b;
}

void	flooor(t_data **data, int *r, int *g, int *b)
{
	(*data)->floor.r = *r;
	(*data)->floor.g = *g;
	(*data)->floor.b = *b;
}

void	handle_color(char *color, char type, t_data **data)
{
	t_var	var;

	(1) && (var.tmp = NULL, var.i = 0, var.r = 0, var.g = 0, var.b = 0);
	var.tmp = ft_split(color, ',');
	if (!var.tmp)
		print_err("Invalid color");
	while (var.tmp[var.i])
	{
		if (is_alpha(var.tmp[var.i]))
			print_err("Invalid color");
		if (var.i == 0)
			var.r = ft_atoi(var.tmp[var.i]);
		else if (var.i == 1)
			var.g = ft_atoi(var.tmp[var.i]);
		else if (var.i == 2)
			var.b = ft_atoi(var.tmp[var.i]);
		var.i++;
	}
	if (var.i != 3)
		print_err("Invalid color");
	if (type == 'F')
		flooor(data, &var.r, &var.g, &var.b);
	else if (type == 'C')
		ciel(data, &var.r, &var.g, &var.b);
	free(var.tmp);
}
