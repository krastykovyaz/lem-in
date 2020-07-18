/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:03:20 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 23:03:50 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	er(char *line)
{
	write(2, "ERROR\n", 6);
	ft_strdel(&line);
	exit(0);
}

int		read_ant(void)
{
	char		*line;
	int			i;
	__int128_t	nb_ant;

	nb_ant = get_next_line(0, &line);
	if (nb_ant <= 0 || line[0] == '\0')
		er(line);
	i = 0;
	while (line[i])
	{
		if (!(ft_isinteger(line[i])))
			er(line);
		i++;
	}
	nb_ant = ft_atoi(line);
	if (nb_ant > 2147483647)
		er(line);
	ft_putnbr((int)nb_ant);
	write(1, "\n", 1);
	ft_memdel((void **)&line);
	return (nb_ant);
}

int		main(void)
{
	int		ant;
	t_lemin	*flat;

	ant = read_ant();
	flat = create_lemin();
	read_way(flat, ant);
	if (!flat->path)
		error(1, flat);
	solution(flat);
	calc_ant(flat, ant);
	set_way(flat, ant);
	free_lemin(flat, 0);
	return (1);
}
