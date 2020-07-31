/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:17:56 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 18:39:39 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	check_xy(t_lemin *stut, char **str)
{
	int	i;
	int k;

	k = 0;
	while (k < 2)
	{
		i = 0;
		while (str[k][i])
		{
			if (ft_isinteger(str[1][i]))
				i++;
			else
			{
				while (str[k])
				{
					free(str[k]);
					k++;
				}
				free(str);
				error(1, stut);
			}
			k++;
		}
	}
}

void	check_repeats(char **str, t_lemin *stut, int a, int b)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = stut->room_list;
	while (tmp && tmp->next)
	{
		if ((!ft_strcmp(tmp->next->content, str[0])) || \
		(tmp->next->x == a && tmp->next->y == b))
		{
			while (str[i])
			{
				free(str[i]);
				i++;
			}
			free(str);
			error(1, stut);
		}
		tmp = tmp->next;
	}
}

void	check_input(t_lemin *stut, char **str)
{
	long int	a;
	long int	b;
	t_list		*list;

	list = ft_lstnew(str[0], ft_strlen(str[0]) + 1);
	ft_lstadd(&(stut->room_list), list);
	check_xy(stut, str);
	a = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if (a > 2147483647 || a < -2147483648 || b > 2147483647 || b < -2147483648)
		error(1, stut);
	stut->room_list->x = (int)a;
	stut->room_list->y = (int)b;
	check_repeats(str, stut, a, b);
}

int		add_room(t_lemin *stut, char *line)
{
	char		**str;
	int			i;
	int			z;

	i = 0;
	z = 0;
	while (line[z] != '\0')
		z++;
	if (*line == ' ' || line[z - 1] == ' ')
		error(1, stut);
	str = ft_strsplit(line, ' ');
	error((str == NULL || str[0] == NULL || str[0][0] == 'L'), stut);
	error((!str[1] || !str[2] || str[3] || str[0][0] == '#'), stut);
	check_input(stut, str);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	stut->i_room++;
	return (stut->i_room - 1);
}
