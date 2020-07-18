/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:44:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 23:05:44 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdub(const char *s)
{
	size_t	i;
	size_t	n;
	char	*tmp;

	i = 0;
	n = ft_strlen(s);
	if (!(tmp = malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
