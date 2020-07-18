/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 08:32:11 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:36:32 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		*put_zero(int n)
{
	int *path;
	int i;

	if (!(path = (int *)malloc(sizeof(int) * n)))
		exit(0);
	i = 0;
	while (i < n)
	{
		path[i] = 0;
		i++;
	}
	return (path);
}
