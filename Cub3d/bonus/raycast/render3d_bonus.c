/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:33:41 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/22 16:53:39 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	render_rays(t_data *data, double ang)
{
	t_pos	ray;
	t_pos	step;
	int		pixl;

	ray.x = data->player.x * data->unite;
	ray.y = data->player.y * data->unite;
	step.x = cos(ang) * data->ray_dst * data->unite;
	step.y = sin(ang) * data->ray_dst * data->unite;
	pixl = data->ray_dst * data->unite;
	step.x /= data->ray_dst * data->unite;
	step.y /= data->ray_dst * data->unite;
	while (pixl >= 0)
	{
		mlx_put_pixel(data->mlx.img_m, ray.x, ray.y, 0xFFFF00FF);
		ray.x += step.x;
		ray.y += step.y;
		--pixl;
	}
}

void	find_pixel(double hght, int *top, int *bottum)
{
	*top = S_H / 2 - hght / 2;
	*bottum = S_H / 2 + hght / 2;
	if (*bottum > S_H)
		*bottum = S_H;
}

void	ray_cast(t_data	*data)
{
	int		i;
	double	first_ray;
	double	fov;
	double	v_inter;
	double	h_inter;

	fov = M_PI / 3;
	i = 0;
	first_ray = data->ang - fov / 2;
	while (i < S_W)
	{
		data->dor_h = 0;
		data->dor_v = 0;
		data->hor = 0;
		first_ray = ft_normalize(first_ray);
		v_inter = find_vertical_inter(data->player, first_ray, data);
		h_inter = find_horiznatal_inter(data->player, first_ray, data);
		if (v_inter <= h_inter)
			data->ray_dst = v_inter;
		else
			(1) && (data->ray_dst = h_inter, data->hor = 1);
		render(data, first_ray, i);
		first_ray += fov / S_W;
		i++;
	}
}
