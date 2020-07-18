/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 10:26:27 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:36:00 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		*put_minus(int n)
{
	int *str;
	int i;

	if (!(str = (int *)malloc(sizeof(int) * n)))
		exit(0);
	i = 0;
	while (i < n)
	{
		str[i] = -1;
		i++;
	}
	return (str);
}
