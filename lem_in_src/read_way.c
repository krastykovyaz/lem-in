/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:58:22 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 16:09:22 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	read_way(t_lemin *stut, int ant)
{
	char	*line;
	int		checker;

	checker = 0;
	while (follow_line(&line) != 0 && line != NULL)
	{
		if (ft_strchr(line, '-') != NULL)
		{
			tied_room(stut, line, ant);
			ft_strdel(&line);
			break ;
		}
		if (ft_strequ("##start", line))
			checker = 1;
		else if (ft_strequ("##end", line))
			checker = 2;
		else if (line == '\0' && (stut->enter == 0 || stut->ext == 0))
			error(1, stut);
		else
			set(stut, add_room(stut, line), &checker, line);
		ft_strdel(&line);
	}
}
