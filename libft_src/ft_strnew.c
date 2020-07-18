/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:14:22 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:43:30 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t len)
{
	char *s;

	s = (char*)malloc(sizeof(*s) * (len + 1));
	if (!s)
		return (NULL);
	ft_memset(s, '\0', len + 1);
	return (s);
}
