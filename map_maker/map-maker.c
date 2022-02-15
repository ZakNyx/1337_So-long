/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:25 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/14 22:11:16 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_elem(char c, int n, int m, t_vars *vars)
{
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, n, m);
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
	if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->cimg, n, m);
	}
	if (c == 'P')
	{
		if (vars->w == 0 && vars->t == 0)
		{
			vars->w = n;
			vars->t = m;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, n, m);
	}
}

void	map_maker(t_vars *vars, char *s)
{
	int		n;
	int		m;
	int		fd;
	char	*str;
	int		i;

	n = 0;
	m = 0;
	fd = open(s, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		map_maker_macro(str, vars, n, m);
		n = 0;
		m += 75;
		free(str);
		str = get_next_line(fd);
	}
}

void	map_maker_macro(char *str, t_vars *vars, int n, int m)
{
	int	i;

	i = 0;
	while (str[i])
	{
		print_elem(str[i], n, m, vars);
		if (str[i] == 'E')
		{
			vars->drx = n;
			vars->dry = m;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->dimg, n, m);
		}
		i++;
		n += 75;
	}
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}

void	sprites(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/player.xpm", &vars->x, &vars->y);
	vars->limg = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/playerleft.xpm", &vars->x, &vars->y);
	vars->gimg = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/grass.xpm", &vars->x, &vars->y);
	vars->wimg = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/wall.xpm", &vars->x, &vars->y);
	vars->cimg = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin.xpm", &vars->x, &vars->y);
	vars->dimg = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/closeddoor.xpm", &vars->x, &vars->y);
	vars->oimg = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/opendoor.xpm", &vars->x, &vars->y);
}
