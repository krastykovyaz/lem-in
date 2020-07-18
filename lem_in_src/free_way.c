/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:59:24 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:18:22 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	free_way(t_lemin *stut, int **way)
{
	int i;

	i = 0;
	while (i < stut->ext)
	{
		free(way[i]);
		i++;
	}
	free(way);
}
