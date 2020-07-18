/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:27:13 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 21:10:55 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	set(t_lemin *stut, int room, int *checker, char *line)
{
	if (*checker == 1 && stut->start == -1)
		stut->start = room;
	else if (*checker == 2 && stut->end == -1)
		stut->end = room;
	else if (*checker != 0)
	{
		ft_strdel(&line);
		error(1, stut);
	}
	*checker = 0;
}
