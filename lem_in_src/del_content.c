/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:52:54 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 18:54:09 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	del_content(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}
