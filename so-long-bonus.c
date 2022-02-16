/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so-long-bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:59 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/16 19:28:42 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_wall(char **tab, char *s)
{
	t_vars	vars;

	vars.fd = open(s, O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.x = 0;
	vars.y = 0;
	vars.a = 0;
	while (vars.str)
	{
		while (vars.str[vars.x])
		{
			tab[vars.y][vars.a] = vars.str[vars.x];
			vars.x++;
			vars.a++;
		}
		tab[vars.y][vars.a] = '\0';
		vars.x = 0;
		vars.a = 0;
		vars.y++;
		free(vars.str);
		vars.str = get_next_line(vars.fd);
	}
	tab[vars.y] = NULL;
	return (tab);
}

char	**number(t_vars *vars, char *s)
{
	vars->fd = open(s, O_RDONLY);
	vars->str = get_next_line(vars->fd);
	vars->x = number_line(s);
	vars->y = 0;
	vars->tab = malloc(sizeof(char *) * (vars->x + 1));
	while (vars->str)
	{
		vars->x = ft_strlen(vars->str);
		vars->tab[vars->y] = malloc(vars->x + 1);
		free(vars->str);
		vars->str = get_next_line(vars->fd);
		vars->y++;
	}
	ft_wall(vars->tab, s);
	if (vars->n == 0 && vars->s == 0)
	{
		vars->n = find_position_index(vars->tab);
		vars->s = find_position_line(vars->tab);
	}
	return (vars->tab);
}

int	coin_checker(t_vars *vars)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (vars->tab[j])
	{
		while (vars->tab[j][i])
		{
			if (vars->tab[j][i] == 'C')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->o != 0 && vars->p != 0)
		vars->tab[vars->o][vars->p] = '0';
	if (keycode == 2)
		move_right(vars);
	else if (keycode == 1)
		move_down(vars);
	else if (keycode == 13)
		move_up(vars);
	else if (keycode == 0)
		move_left(vars);
	else if (keycode == 53)
		exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		vars.mlx = mlx_init();
		vars.x = window_width(av[1]) * 75;
		vars.y = window_height(av[1]);
		vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Have Fun");
		sprites(&vars);
		sprites_animation(&vars);
		map_maker(&vars, av[1]);
		vars.tab = number(&vars, av[1]);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop_hook(vars.mlx, loop_hook, &vars);
		mlx_hook(vars.win, 17, 0, destroy, &vars);
		mlx_loop(vars.mlx);
	}
	else
	{
		write(1, "ERROR\nENTER A VALID MAP! \n", 27);
		exit(1);
	}
}
