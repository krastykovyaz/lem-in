/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:22:37 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:28:54 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[len] = (unsigned char)c;
		i++;
	}
	return (s);
}
