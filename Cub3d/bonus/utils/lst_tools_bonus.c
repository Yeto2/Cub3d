/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:54 by yessemna          #+#    #+#             */
/*   Updated: 2024/12/21 03:39:38 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = ft_lstlast(*alst);
	last->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)g_malloc(sizeof(t_list), MALLOC);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
