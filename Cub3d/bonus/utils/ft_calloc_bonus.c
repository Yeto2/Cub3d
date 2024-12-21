/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:55:53 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/21 03:40:12 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	long	cnt;
	long	sz;

	cnt = (long)count;
	sz = (long)size;
	if (cnt < 0 || sz < 0)
		return (0);
	ptr = g_malloc(cnt * size, MALLOC);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, cnt * size);
	return (ptr);
}
