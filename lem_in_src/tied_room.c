/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tied_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:14:11 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 23:04:34 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_ant(t_lemin *stut, int ant)
{
	int j;

	j = 1;
	write(1, "\n", 1);
	while (j <= ant)
	{
		write(1, "L", 1);
		ft_putnbr(j);
		write(1, "-", 1);
		ft_putstr(stut->name_room[stut->end]);
		write(1, " ", 1);
		stut->steps++;
		j++;
		write(1, "\n", 1);
	}
	free_lemin(stut, 0);
	exit(0);
}

void	ent_ext(t_lemin *stut)
{
	int i;

	i = 0;
	while (i < stut->i_room)
	{
		if (stut->path[stut->start][i] && i != stut->start)
			stut->enter++;
		if (stut->path[stut->end][i] && i != stut->end)
			stut->ext++;
		i++;
	}
	error((stut->enter == 0 || stut->ext == 0), stut);
}

int		get_i(char *name, t_lemin *stut)
{
	int		i;
	char	**str;

	i = 0;
	str = stut->name_room;
	while (str[i])
	{
		if (ft_strequ(str[i], name))
			return (i);
		i++;
	}
	error(1, stut);
	return (-1);
}

void	fill_way(t_lemin *stut, char *line, int ant, int flag)
{
	char	**str;
	int		f;
	int		s;
	int		i;

	i = 0;
	str = ft_strsplit(line, '-');
	error((!str[1] || str[2]), stut);
	f = get_i(str[0], stut);
	s = get_i(str[1], stut);
	stut->path[f][s] = 1;
	stut->path[s][f] = 1;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if ((f == stut->start || f == stut->end) && (s == stut->start || \
	s == stut->end) && flag == 1)
		print_ant(stut, ant);
}

void	tied_room(t_lemin *stut, char *line, int ant)
{
	char	*l;
	int		nb;
	int		flag;

	nb = 1;
	flag = 0;
	error((stut->start == -1 || stut->end == -1), stut);
	convert(stut);
	fill_way(stut, line, ant, flag);
	flag = 1;
	while (nb)
	{
		follow_line(&l);
		(!l) ? nb = 0 : fill_way(stut, l, ant, flag);
		ft_strdel(&l);
	}
	ent_ext(stut);
}
