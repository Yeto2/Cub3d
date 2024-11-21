/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:00:10 by lamhal            #+#    #+#             */
/*   Updated: 2024/11/21 14:39:10 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player   pos_in_map(t_player pl)
{
	pl.x = pl.x * TILE_SIZE + (TILE_SIZE / 2);
	pl.y = pl.y * TILE_SIZE + (TILE_SIZE / 2);
	return (pl);
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
	return (ang);
}

double	ft_normalize(double ang)
{
	if (ang < 0)
		ang += 2 * M_PI;
	if (ang >= 2 * M_PI)
		ang -= 2 * M_PI;
	return (ang);
}


int	hitt_wall(t_cor inter, t_data *data)
{
	inter.x /= TILE_SIZE;
	inter.y /= TILE_SIZE;
	if (inter.x < 0 || inter.y < 0)
		return (0);
	if (inter.x >= data->map.map_w || inter.y >= data->map.map_h)
		return (0);
	// printf("x = %d y = %d \n", inter.x, inter.y);
	if (data->map.map[inter.y][inter.x] =='1')
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

void	siting_up_steps(int	*x, int *y, double ang)
{
	if (ray_datiction_dwn(ang))
		*y = abs(*y);
	else
		*y = -abs(*y);
	if (ray_dariction_right(ang))
		*x = abs(*x);
	else
		*x = -abs(*x);
}

t_cor	get_first_intesaction(t_player pl, double ang)
{
	t_cor	inter;

	inter.y = floor(pl.y / TILE_SIZE) * TILE_SIZE;
	if (ang > 0 && ang < M_PI)
		inter.y += TILE_SIZE;
	inter.x = pl.x + (inter.y - pl.y) / tan(ang);
	return (inter);
}

double	find_horiznatal_inter(t_player pl, double ang, t_data *data)
{
	t_cor	inter;
	int		x_step;
	int		y_step;

	inter = get_first_intesaction(pl, ang);
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(ang);
	siting_up_steps(&x_step, &y_step, ang);
	while (hitt_wall(inter, data))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	return (sqrt(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
}


t_cor	get_first_intesaction1(t_player pl, double ang)
{
	t_cor	inter;

	inter.x = floor(pl.x / TILE_SIZE) * TILE_SIZE ;
	if ((ang >= 0 && ang < M_PI / 2)
			|| (ang > 3 * M_PI / 2 && ang < 2 * M_PI))
		inter.x += TILE_SIZE;
	inter.y = pl.y + (inter.x - pl.x) * tan(ang);
	return (inter);
}

float	find_vertical_inter(t_player pl, double ang, t_data *data)
{
	t_cor	inter;
	int		x_step;
	int		y_step;

	inter = get_first_intesaction1(pl, ang);
	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(ang);
	siting_up_steps(&x_step, &y_step, ang);
	while (hitt_wall(inter, data))
	{
		inter.x += x_step;
		inter.y += y_step;
	}
	return (sqrt(pow(inter.x - pl.x, 2) + pow(inter.y - pl.y, 2)));
}

t_cor	find_pixel(int hght)
{
	t_cor	pxl;
	
	if (hght > S_H)
	{
		pxl.x = 0;
		pxl.y = S_H;
	}
	else
	{
		pxl.x = S_H / 2 - hght / 2;
		pxl.y = S_H / 2 + hght / 2;
	}
	return (pxl);	
}

void	render(t_data *data, double ray, int i)
{
	int	wall_hght;
	int	dst;
	t_cor	pxl;
	int	j;

	// (void)ray;
	// printf("top %d bottom %d\n", pxl.x , pxl.y);
	data->ray_dst *= cos(ray - data->ang);
	// printf("ray_dst1 ===>%d\n", data->ray_dst);
	// printf("%d %d\n",  S_W, S_H);
	//exit (0);
	dst = S_H / (tan(M_PI / 6) * 2);
	// printf("dst %d\n", dst);
	wall_hght = TILE_SIZE * dst / data->ray_dst;
	// printf("wall_hgt %d\n", wall_hght);
	pxl = find_pixel(wall_hght);
	j = -1;
	while (++j < S_H)
	{
		if (j < pxl.x)
			mlx_put_pixel(data->mlx.img_r, i, j, 0x0000FFFF);
		else if (j <= pxl.y && data->ver)
			mlx_put_pixel(data->mlx.img_r, i, j, 0xFFFF00FF);
		else if (j <= pxl.y)
			mlx_put_pixel(data->mlx.img_r, i, j, 0x00FF00FF);
		// else
			// mlx_put_pixel(data->mlx.img_r, i, j, 0x00FF00FF);
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
	i = -1;
	first_ray = data->ang - fov / 2;
	while (++i < S_W)
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
		render(data, first_ray, i);
		first_ray += fov / S_W;
	}
}

void	start_game(t_data *data)
{
	data->mlx.mlx_p = mlx_init(S_W, S_H, "Cub3d", 0);
	data->mlx.img_r = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
	data->ang = set_angle(data->player);
	data->ang += 0.5;
	data->ang = ft_normalize(data->ang);
	data->player = pos_in_map(data->player);
	// printf("c ==>  %c\n", data->map.map[3][1]);
	// exit(0);
	ray_cast(data);
	// int i = 15;
	// int j = 15;
	// while (j++ < 100)
	// 	mlx_put_pixel(data->mlx.img_r, i, j, get_rgba(data->ciel.red,
	// 			data->ciel.green, data->ciel.blue, 0));
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img_r, 0,0);
	mlx_loop(data->mlx.mlx_p);
}
