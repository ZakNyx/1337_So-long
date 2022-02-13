/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:18 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/13 17:39:53 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	buff;
	int		r;

	r = read(fd, &buff, 1);
	str = ft_strdup("");
	while (r > 0)
	{
		str = ft_strjoin(str, buff);
		if (buff == '\n')
			break ;
		r = read(fd, &buff, 1);
	}
	if (r < 0)
	{
		free(str);
		return (NULL);
	}
	if (r == 0 && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
