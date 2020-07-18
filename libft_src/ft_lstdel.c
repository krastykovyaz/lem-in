/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:44:09 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:27:19 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *tmp;

	if (!*alist)
		return ;
	list = *alist;
	while (list)
	{
		tmp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = tmp;
	}
	*alist = NULL;
}
