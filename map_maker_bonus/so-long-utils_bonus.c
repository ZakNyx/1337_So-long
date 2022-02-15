/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so-long-utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:18:33 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/14 23:06:32 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	window_width(char *s)
{
	t_vars	vars;

	vars.fd = open(s, O_RDONLY);
	if (vars.fd < 0)
	{
		perror("ERROR ");
		exit(1);
	}
	return (check_map(vars.fd));
}

int	window_height(char *s)
{
	t_vars	vars;

	vars.fd = open(s, O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.y = 0;
	while (vars.str != NULL)
	{
		vars.y = vars.y + 75;
		free(vars.str);
		vars.str = get_next_line(vars.fd);
	}
	return (vars.y);
}

int	number_line(char *s)
{
	t_vars	vars;

	vars.fd = open(s, O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.x = 0;
	vars.y = 0;
	while (vars.str)
	{
		vars.x++;
		free(vars.str);
		vars.str = get_next_line(vars.fd);
	}
	return (vars.x);
}

int	find_position_index(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'P')
				return (i);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	find_position_line(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'P')
				return (j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
