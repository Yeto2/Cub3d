/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:33:41 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/02 19:57:37 by yessemna         ###   ########.fr       */
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


int	hitt_wall(double i, double j, t_data *data)
{
	int	x;
	int	y;
	
	x = i / TILE_SIZE;
	y = j / TILE_SIZE;
	if (x < 0 || y < 0)
		return (0);
	if (x >= data->map.map_w || y >= data->map.map_h)
		return (0);
	if (data->map.map[y][x] =='1')
		return (0);
	return (1);
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

void	siting_up_steps(double	*x, double *y, double ang)
{
	if (ray_datiction_dwn(ang))
		*y = fabs(*y);
	else
		*y = -fabs(*y);
	if (ray_dariction_right(ang))
		*x = fabs(*x);
	else
		*x = -fabs(*x);
}

t_pos	get_first_intesaction(t_player pl, double ang)
{
	t_pos	inter;

	inter.y = floor(pl.y / TILE_SIZE) * TILE_SIZE;
	if (ang > 0 && ang < M_PI)
		inter.y += TILE_SIZE;
	inter.x = pl.x + (inter.y - pl.y) / tan(ang);
	return (inter);
}

double	find_horiznatal_inter(t_player pl, double ang, t_data *data)
{
	t_pos	inter;
	double	x_step;
	double	y_step;
	int		pixl;

	pixl = 1;
	if (ray_datiction_dwn(ang))
		pixl = -1;
	inter = get_first_intesaction(pl, ang);
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(ang);
	siting_up_steps(&x_step, &y_step, ang);
	while (hitt_wall(inter.x, inter.y - pixl, data))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	data->h_inter = inter.x;
	return (sqrt(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
}

t_pos	get_first_intesaction1(t_player pl, double ang)
{
	t_pos	inter;

	inter.x = floor(pl.x / TILE_SIZE) * TILE_SIZE ;
	if ((ang >= 0 && ang < M_PI / 2)
			|| (ang > 3 * M_PI / 2 && ang < 2 * M_PI))
		inter.x += TILE_SIZE;
	inter.y = pl.y + (inter.x - pl.x) * tan(ang);
	return (inter);
}

float	find_vertical_inter(t_player pl, double ang, t_data *data)
{
	t_pos	inter;
	double		x_step;
	double		y_step;
	int			pixl;

	pixl = 1;
	if (ray_dariction_right(ang))
		pixl = -1;
	inter = get_first_intesaction1(pl, ang);
	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(ang);
	siting_up_steps(&x_step, &y_step, ang);
	while (hitt_wall(inter.x - pixl, inter.y, data))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	data->v_inter = inter.y;
	return (sqrt(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
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

mlx_texture_t	*set_png_texture(t_data *data, char *path) //<-----------------------
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

// int	ret_offset_x(double wall_hit_x, double wall_hit_y,
// 		bool is_vr, mlx_texture_t *texture)
// {
// 	int	offset_x;

// 	if (is_vr)
// 		offset_x = (int)wall_hit_y % texture->width;
// 	else
// 		offset_x = (int)wall_hit_x % texture->width;
// 	return (offset_x);

// }

// void render_texture(t_data *data, double wall_bottom_px, mlx_texture_t *texture)
// {
	

// /*

// 	index = 0;
// 	p_clrs = (uint32_t *)texture->pixels;
// 	y_ver = wall_top_pixle(wall_height);
// 	while (y_ver <= wall_bottom_pixel
// 		&& index < texture->width * texture->height)
// 	{
// 		dist_top_wall_height = y_ver - (WINDOW_HEIGHT / 2) + (wall_height / 2);
// 		offsety = dist_top_wall_height * texture->height / wall_height;
// 		index = (texture->width * offsety) + (data->offsetx % texture->width);
// 		if (index < texture->height * texture->width)
// 			ft_put_pixel(data->window_img, data->x_ray, y_ver, p_clrs[index]);
// 		y_ver++;
// 	}

// */
// }
int    ft_color(int r, int g, int b, int a)
{
    return ((((r * 256 + g) * 256) + b) * 256 + a);
}

int    ft_texture_color(unsigned int c)
{
    int    r;
    int    g;
    int    b;
    int    a;

    a = c % 256;
    c /= 256;
    b = c % 256;
    c /= 256;
    g = c % 256;
    c /= 256;
    r = c;
    return (ft_color(a, b, g, r));
}

void paint_wall(t_data *data, mlx_texture_t *texture)
{

	unsigned long	index;
	uint32_t		*p_clrs;
	int offsety;
	int top_px_wall;

	p_clrs = (uint32_t *)texture->pixels;
	index = 0;
	
	int top_px = (S_H / 2) - (data->wall_hght / 2);
	if (top_px < 0)
		top_px = 0;
	while (top_px <= data->bottom_pixel)
	{
		top_px_wall = top_px - (S_H / 2) + (data->wall_hght / 2);
		offsety = top_px_wall * texture->height / data->wall_hght;
		index = (texture->width * offsety) + (data->offsetx % texture->width);
		if (index < texture->height * texture->width)
			mlx_put_pixel(data->mlx.img_r, data->ray_x, top_px, ft_texture_color(p_clrs[index]));
		top_px++;
	}

// */
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

void render(t_data *data, double ray, int i)
{
    double wall_hght;
    double dst;
    int top;
    int bottom;
    t_textures *textures;

    textures = &data->textures;
    data->ray_dst *= cos(ray - data->ang);
    dst = S_H / (tan(M_PI / 6) * 2);
    wall_hght = TILE_SIZE * dst / data->ray_dst;
    find_pixel(wall_hght, &top, &bottom);

    uint32_t *p_clrs;
	mlx_texture_t *texture;
    // Determine the texture based on the direction
    if (data->ver) {
        texture = textures->we; // West
    } else {
        texture = textures->ea; // East
    }
    if (data->h_inter) {
        if (data->ver) {
            texture = textures->no; // North
        } else {
            texture = textures->so; // South
        }
    }
    data->offsetx = ret_offset_x(data->h_inter, data->v_inter, data->ver, texture);
    data->wall_hght = wall_hght;
    data->top_pixel = top;
    data->bottom_pixel = bottom;
    data->ray_x = i;

    int j = 0;
	p_clrs = (uint32_t *)texture->pixels;
    while (j < S_H)
    {
        if (j < top)
        {
            mlx_put_pixel(data->mlx.img_r, i, j, get_coller(data->ciel.red, data->ciel.green, data->ciel.blue, 255));
        }
        else if (j >= bottom && j < S_H)
        {
            mlx_put_pixel(data->mlx.img_r, i, j, get_coller(data->floor.red, data->floor.green, data->floor.blue, 255));
        }
        else if (j >= top && j < bottom)
        {
            // Use the wall texture color
            int texture_y = (j - top) * (texture->height / wall_hght); // Adjust for height
            int color =  ft_texture_color(p_clrs[data->offsetx + texture_y * texture->width]);// Get color from texture
			//p_clrs[data->offsetx + texture_y * textures->we->width];
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


