/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:01 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/15 19:57:49 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_count(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->w, vars->t);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 0, 30, 0xFFFFFF, ft_itoa(vars->steps));
}

void	move_right(t_vars *vars)
{
	vars->x = coin_checker(vars);
	if (vars->x == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg,
			vars->drx, vars->dry);
	if (vars->tab[vars->s][vars->n + 1] == 'E')
	{
		vars->x = coin_checker(vars);
		if (vars->x == 0)
			exit(1);
	}
	move_right_extention(vars);
}

void	move_down(t_vars *vars)
{
	vars->x = coin_checker(vars);
	if (vars->x == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg,
			vars->drx, vars->dry);
	if (vars->tab[vars->s + 1][vars->n] == 'E')
	{
		vars->x = coin_checker(vars);
		if (vars->x == 0)
			exit(1);
	}
	move_down_extention(vars);
}

void	move_up(t_vars *vars)
{
	vars->x = coin_checker(vars);
	if (vars->x == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg,
			vars->drx, vars->dry);
	if (vars->tab[vars->s - 1][vars->n] == 'E')
	{
		vars->x = coin_checker(vars);
		if (vars->x == 0)
			exit(1);
	}
	move_up_extention(vars);
}

void	move_left(t_vars *vars)
{
	vars->x = coin_checker(vars);
	if (vars->x == 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->oimg, vars->drx, vars->dry);
	if (vars->tab[vars->s][vars->n - 1] == 'E')
	{
		vars->x = coin_checker(vars);
		if (vars->x == 0)
			exit(1);
	}
	move_left_extention(vars);
}
