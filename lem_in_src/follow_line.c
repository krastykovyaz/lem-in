/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:30:30 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 19:34:45 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	erno(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int		follow_line(char **line)
{
	int		number;
	char	*l;
	int		i;

	i = -1;
	while ((number = get_next_line(0, &l)))
	{
		if (number == -1)
			erno();
		while (l[++i])
			if (l[i] == '#' && l[i + 1] == '#' && ft_strequ("##start", l) == 0 \
	&& ft_strequ("##end", l) == 0)
				erno();
		if ((l[0] != '#' || ft_strequ("##start", l) || ft_strequ("##end", l)))
		{
			*line = l;
			ft_putstr(l);
			ft_putchar('\n');
			break ;
		}
		else
			ft_strdel(&l);
	}
	return (number);
}
