/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:52:39 by lamhal            #+#    #+#             */
/*   Updated: 2024/12/05 17:53:14 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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