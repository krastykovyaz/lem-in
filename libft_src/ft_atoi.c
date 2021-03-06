/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:41:02 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:25:06 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

__int128_t	ft_atoi(const char *s)
{
	__int128_t	nb;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	nb = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' ||\
	s[i] == '\f' || s[i] == '\n')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb * sign);
}
