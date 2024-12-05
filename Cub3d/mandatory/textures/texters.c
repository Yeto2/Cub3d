/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:59:59 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/05 18:00:30 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_texture_t	*set_png_texture(t_data *data, char *path)
{
	mlx_texture_t	*texture;
	(void)data; // to destroy images later
	
	texture = mlx_load_png(path);

	if (texture == NULL)
	{
		write(2, "Error\nfaild to load png", 24);
	}
	return (texture);
}

int	ret_offset_x(double wall_hit_x, double wall_hit_y,
		bool is_vr, mlx_texture_t *texture)
{
	int	offset_x;

	if (!is_vr)
		// offset_x = (int)wall_hit_y % texture->width;
		offset_x = ((int)(wall_hit_y * texture->width) / TILE_SIZE) % texture->width;
	else
		// offset_x = (int)wall_hit_x % texture->width;
		offset_x = ((int)(wall_hit_x * texture->width) / TILE_SIZE) % texture->width;
	return (offset_x);
}

mlx_texture_t *return_texture(t_data *data, t_textures *textures)
{
    if (!data->ver) // Vertical intersection
    {
        if (data->direct == -1) // West
            return (textures->we);
        else if (data->direct == 1) // East
            return (textures->ea);
    }
    else // Horizontal intersection
    {
        if (data->direct == -1) // North
            return (textures->no);
        else if (data->direct == 1) // South
            return (textures->so);
    }
    return (NULL);
}

void render(t_data *data, double ray, int i)
{
    double wall_hght;
    double dst;
    int top;
    int bottom;
    t_textures *textures;
    uint32_t *p_clrs;
	mlx_texture_t *texture;

    textures = &data->textures;
    data->ray_dst *= cos(ray - data->ang);
    dst = S_H / (tan(M_PI / 6) * 2);
    wall_hght = TILE_SIZE * dst / data->ray_dst;
    find_pixel(wall_hght, &top, &bottom);
	texture = return_texture(data, textures);
    data->offsetx = ret_offset_x(data->h_inter, data->v_inter, data->ver, texture);
    int j = 0;
	p_clrs = (uint32_t *)texture->pixels;
    while (j < S_H)
    {
        if (j < top)
            mlx_put_pixel(data->mlx.img_r, i, j, get_coller(data->ciel.red, data->ciel.green, data->ciel.blue, 255));
        else if (j >= bottom && j < S_H)
            mlx_put_pixel(data->mlx.img_r, i, j, get_coller(data->floor.red, data->floor.green, data->floor.blue, 255));
        else if (j >= top && j < bottom)
        {
            int texture_y = (j - top) * (texture->height / wall_hght); // Adjust for height
            int color =  ft_texture_color(p_clrs[data->offsetx + texture_y * texture->width]);// Get color from texture
            mlx_put_pixel(data->mlx.img_r, i, j, color);
        }
        j++;
    }
}
