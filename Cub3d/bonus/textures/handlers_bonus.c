/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:32:11 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/22 16:53:39 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

mlx_texture_t	*set_png_texture(t_data *data, char *path)
{
	mlx_texture_t	*texture;
	(void)data; // to destroy images later
	texture = mlx_load_png(path);
	if (texture == NULL)
		write(2, "Error\nfaild to load png", 24);
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
