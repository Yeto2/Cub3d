/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:59:59 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/19 23:32:39 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ret_offset_x(double wall_hit_x, double wall_hit_y,
		bool is_vr, mlx_texture_t *txt)
{
	int	off_x;

	if (!is_vr)
		off_x = ((int)(wall_hit_y * txt->width) / TILE_SIZE) % txt->width;
	else
		off_x = ((int)(wall_hit_x * txt->width) / TILE_SIZE) % txt->width;
	return (off_x);
}

void	func(t_data *data, t_render_var *t, double ray, mlx_texture_t *txt)
{
	data->ray_dst *= cos(ray - data->ang);
	t->dst = S_H / (tan(M_PI / 6) * 2);
	t->wall_hght = TILE_SIZE * t->dst / data->ray_dst;
	find_pixel(t->wall_hght, &t->top, &t->bottom);
	data->offsetx = ret_offset_x(data->h_inter,
			data->v_inter, data->ver, txt);
	t->p_clrs = (uint32_t *)txt->pixels;
	t->j = 0;
}

void	render(t_data *data, double ray, int i)
{
	mlx_texture_t	*txt;
	t_textures		*textures;
	t_render_var	t;

	textures = &data->textures;
	txt = return_texture(data, textures, ray);
	func(data, &t, ray, txt);
	while (t.j < S_H)
	{
		if (t.j < t.top)
			mlx_put_pixel(data->mlx.img_r, i, t.j, get_coller(data->ciel.r,
					data->ciel.g, data->ciel.b, 255));
		else if (t.j >= t.bottom && t.j < S_H)
			mlx_put_pixel(data->mlx.img_r, i, t.j,
				get_coller(data->floor.r, data->floor.g, data->floor.b, 255));
		else if (t.j >= t.top && t.j < t.bottom)
		{
			t.txt_y = (t.j - t.top) * (txt->height / t.wall_hght);
			t.color = txt_clr(t.p_clrs[data->offsetx + t.txt_y * txt->width]);
			mlx_put_pixel(data->mlx.img_r, i, t.j, t.color);
		}
		t.j++;
	}
}
