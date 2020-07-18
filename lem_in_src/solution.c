/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:34:51 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:41:43 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	prepair_path(t_lemin *stut)
{
	t_lemin	*prep_stut;

	prep_stut = stut;
	if (stut->enter < stut->ext)
		stut->ext = stut->enter;
	else
		stut->enter = stut->ext;
	if (!(prep_stut->previous = (int **)malloc(sizeof(int *) \
	* prep_stut->enter)))
		exit(0);
	if (!(prep_stut->visit = (int **)malloc(sizeof(int *) \
	* prep_stut->enter)))
		exit(0);
	if (!(prep_stut->next = (int **)malloc(sizeof(int *) \
	* prep_stut->enter)))
		exit(0);
}

void	solution(t_lemin *stut)
{
	int *tmp;
	int i;

	i = 0;
	prepair_path(stut);
	while (stut->ext > stut->ext_count)
	{
		fill_path(stut, i);
		tmp = path_tmp(stut, i);
		tmp = find_p1(stut, tmp, i);
		ft_memdel((void **)&tmp);
		i++;
	}
	set_next(stut, stut->ext_count);
	while (i < stut->enter)
	{
		stut->previous[i] = put_minus(1);
		stut->visit[i] = put_minus(1);
		stut->next[i] = put_minus(1);
		i++;
	}
}
