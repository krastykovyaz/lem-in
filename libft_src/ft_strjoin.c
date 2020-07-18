/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:05:33 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:31:45 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	tmp = ft_strcpy(tmp, s1);
	tmp = ft_strcat(tmp, s2);
	return (tmp);
}
