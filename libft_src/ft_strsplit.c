/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:47:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:43:43 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		count_words(char *str, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (!(str[i] == c))
		{
			if (str[i] != '\0')
				i++;
			else
				break ;
		}
		while (str[i] == c)
			i++;
		words++;
	}
	return (words);
}

char	*find_words(char *str, char c, int *index)
{
	int		i;
	int		start;
	int		end;
	char	*dest;

	start = *index;
	i = start;
	while (!(str[i] == c) && str[i] != '\0')
		i++;
	end = i;
	dest = (char *)malloc(end - start + 1);
	if (str[i] == c)
		i++;
	*index = i;
	i = 0;
	while (i < end - start)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_strsplit(char *str, char c)
{
	int		i;
	int		index;
	char	**dest;

	i = 0;
	index = 0;
	if (!str || !c)
		return (NULL);
	dest = (char**)malloc(sizeof(char*) * (count_words(str, c) + 1));
	if (!dest)
		return (NULL);
	while (*str == c)
		str++;
	while (str[i] != '\0')
	{
		dest[index] = find_words(str, c, &i);
		index++;
	}
	dest[index] = 0;
	return (dest);
}
