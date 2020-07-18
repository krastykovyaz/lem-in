/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:04:04 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:33:30 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	n;

	if (!s)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	n = 0;
	while (n < len)
	{
		new[n] = s[n + start];
		n++;
	}
	new[n] = '\0';
	return (new);
}
