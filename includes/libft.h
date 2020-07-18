/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:10:42 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 22:57:10 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	int				x;
	int				y;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strdub(const char *s);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t len);
void				*ft_memset(void *s, int c, size_t len);
char				*ft_strcpy(char *s, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **s);
int					ft_isinteger(int c);
__int128_t			ft_atoi(const char *s);
void				ft_memdel(void **s);
void				ft_putnbr(int nb);
void				ft_putstr(const char *s);
void				ft_putchar(char c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_lstdel(t_list **alist, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				**ft_strsplit(char *str, char c);
char				*ft_strdup(const char *s);

#endif
