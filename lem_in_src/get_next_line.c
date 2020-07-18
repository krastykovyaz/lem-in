/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:26:15 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:19:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	last_line(char **buffer, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\n')
	{
		*line = ft_strsub(*buffer, 0, i);
		tmp = ft_strdub(&((*buffer)[i + 1]));
		free(*buffer);
		*buffer = tmp;
		if ((*buffer)[0] == '\0')
			ft_strdel(buffer);
	}
	return (1);
}

static int	read_line(char **buffer, int fd)
{
	int		content;
	char	carrige[BUFF_SIZE + 1];
	char	*tmp;

	while ((content = read(fd, carrige, BUFF_SIZE)) > 0)
	{
		carrige[content] = '\0';
		if (buffer[fd] == NULL)
			buffer[fd] = ft_strdub(carrige);
		else
		{
			tmp = ft_strjoin(buffer[fd], carrige);
			free(buffer[fd]);
			buffer[fd] = tmp;
		}
		if (ft_strchr(carrige, '\n'))
			break ;
	}
	return (content);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffer[FD_SIZE];
	int			content;

	if (line == NULL || fd < 0)
		return (-1);
	content = read_line(buffer, fd);
	if (content < 0)
		return (-1);
	else if (content == 0 && (buffer[fd] == NULL || buffer[fd][0] == '\0'))
		return (0);
	else
		last_line(&buffer[fd], line);
	return (1);
}
