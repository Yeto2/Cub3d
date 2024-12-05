/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:33:41 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/04 22:56:21 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player   pos_in_map(t_player pl)
{
	t_player	tmp;
	tmp.x = pl.x * TILE_SIZE + (TILE_SIZE / 2);
	tmp.y = pl.y * TILE_SIZE + (TILE_SIZE / 2);
	return (tmp);
}

double	ft_normalize(double ang)
{
	if (ang < 0)
		ang += 2 * M_PI;
	if (ang >= 2 * M_PI)
		ang -= 2 * M_PI;
	return (ang);
}

double	set_angle(t_player pl)
{
	double	ang;

	ang = 0;
	if (pl.dir == 'N')
		ang = 3 * M_PI / 2;
	else if (pl.dir == 'E')
		ang = 0;
	else if (pl.dir == 's')
		ang = M_PI / 2;
	else if (pl.dir == 'w')
		ang = M_PI;
	ang = ft_normalize(ang);
	return (ang);
}

int	ray_datiction_dwn(double ang)
{
	if (ang > 0 && ang < M_PI)
		return (1);
	return (0);
}

int	ray_dariction_right(double ang)
{
	if (ang >= 0 && ang < M_PI / 2)
		return (1);
	if (ang > 3 * M_PI / 2 && ang < 2 * M_PI)
		return (1);
	return (0);
}

void    render_rays(t_data *data, double ang)
{
    t_pos ray;
    t_pos step;
    int pixl;

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
	// if (hght > S_H)
	// {
	// 	*top = 0;
	// 	*bottum = S_H;
	// }
	// else
	// {
	// 	*top = S_H / 2 - hght / 2;
	// 	*bottum = S_H / 2 + hght / 2;
	// }	
}

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
		data->ver = 0;
		first_ray = ft_normalize(first_ray);
		v_inter = find_vertical_inter(data->player, first_ray, data);
		h_inter = find_horiznatal_inter(data->player, first_ray, data);
		if (v_inter <= h_inter)
			data->ray_dst = v_inter;
		else
		{
			data->ray_dst = h_inter;
			data->ver = 1;
		}
		// render_rays(data, first_ray);
		render(data, first_ray, i);
		first_ray += fov / S_W;
		i++;
	}
    mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_r, 0, 0);
}


