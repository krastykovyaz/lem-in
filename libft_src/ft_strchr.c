/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:26:46 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:59:43 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	if ((char)c == '\0')
		return ((char*)s + ft_strlen(s));
	i = 0;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
