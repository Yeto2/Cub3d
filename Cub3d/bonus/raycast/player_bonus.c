/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:33:17 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/29 15:15:24 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_and_exit(t_data *data, int i)
{
	while (--i >= 0)
		mlx_delete_texture((mlx_texture_t *)data->pl_imgs[i]);
	free(data->pl_imgs);
	exit(EXIT_FAILURE);
}

void	display_pl_images(t_data *data, int i)
{
	static mlx_image_t	*rm_img;

	if (rm_img)
		mlx_delete_image(data->mlx.mlx_p, rm_img);
	data->tmp_img = mlx_texture_to_image(data->mlx.mlx_p, data->pl_imgs[i]);
	if (!data->tmp_img)
		terminate_mlx(data);
	rm_img = data->tmp_img;
	mlx_image_to_window(data->mlx.mlx_p, data->tmp_img,
		(S_W / 2) - (1021 / 2), S_H - 766);
}

void	pl_animation(void *arg)
{
	t_data		*data;
	static int	i = 0;
	static bool	is_pressed = false;

	data = (t_data *)arg;
	if (mlx_is_key_down(data->mlx.mlx_p, MLX_KEY_SPACE))
	{
		mlx_delete_image(data->mlx.mlx_p, data->default_img);
		if (data->pl_txt)
			mlx_delete_texture((mlx_texture_t *)data->pl_txt);
		is_pressed = true;
		data->pl_txt = mlx_load_png("./bonus/images/player/Stechkin01.png");
		if (!data->pl_txt)
		{
			terminate_mlx(data);
			print_err("Error\nfailed to load png");
		}
	}
	if (is_pressed)
		display_pl_images(data, i++);
	if (i == NUM_FRAMES)
	{
		i = 0;
		is_pressed = false;
	}
}

void	init_player(t_data *data)
{
	char	path[100];
	char	index[10];
	int		i;

	i = 0;
	data->pl_imgs = g_malloc(sizeof(void *) * (NUM_FRAMES + 1), MALLOC);
	if (!data->pl_imgs)
		(print_err("Error\nMalloc failed"));
	while (i < NUM_FRAMES)
	{
		ft_strcpy(path, "./bonus/images/player/StechkinEx");
		ft_strcpy(index, ft_itoa(i + 1));
		ft_strcut(path, index);
		ft_strcut(path, ".png");
		data->txt = mlx_load_png(path);
		if (!data->txt)
		{
			write(2, "Error\nfaild to load png\n", 25);
			free_and_exit(data, i);
		}
		data->pl_imgs[i] = data->txt;
		i++;
	}
	data->pl_imgs[i] = NULL;
}
