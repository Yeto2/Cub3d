/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:32:11 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/26 05:31:05 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

mlx_texture_t	*set_png_texture(t_data *data, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (texture == NULL)
	{
		terminate_mlx(data);
		print_err("faild to load png");
	}
	return (texture);
}

mlx_texture_t	*return_texture(t_data *data, t_textures *textures, double ray)
{
	ray = ft_normalize(ray);
	if (!data->hor)
	{
		if (ray_dariction_right(ray))
			return (textures->ea);
		else
			return (textures->we);
	}
	else
	{
		if (ray_datiction_dwn(ray))
			return (textures->so);
		else
			return (textures->no);
	}
	return (NULL);
}
