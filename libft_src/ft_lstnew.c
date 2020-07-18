/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:44:55 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:27:42 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lnew;

	if (!(lnew = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lnew->content = NULL;
		lnew->content_size = 0;
	}
	else
	{
		lnew->content_size = content_size;
		if (!(lnew->content = malloc(content_size)))
		{
			free(lnew);
			return (NULL);
		}
		ft_memcpy(lnew->content, content, content_size);
	}
	lnew->next = NULL;
	return (lnew);
}
