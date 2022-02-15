/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:52:14 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/15 19:57:22 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right_extention(t_vars *vars)
{
	if (vars->tab[vars->s][vars->n + 1] != '1'
			&& vars->tab[vars->s][vars->n + 1] != 'E')
	{
		vars->n++;
		if (vars->tab[vars->s][vars->n] == 'C')
		{
			vars->o = vars->s;
			vars->p = vars->n;
		}
		if (vars->tab[vars->s][vars->n] == 'E')
			exit(1);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->gimg, vars->w, vars->t);
		vars->w += 75;
		move_count(vars);
	}
}

void	move_down_extention(t_vars *vars)
{
	if (vars->tab[vars->s + 1][vars->n] != '1' &&
			vars->tab[vars->s + 1][vars->n] != 'E')
	{
		vars->s++;
		if (vars->tab[vars->s][vars->n] == 'C')
		{
			vars->o = vars->s;
			vars->p = vars->n;
		}
		if (vars->tab[vars->s][vars->n] == 'E')
			exit(1);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->gimg, vars->w, vars->t);
		vars->t += 75;
		move_count(vars);
	}
}

void	move_up_extention(t_vars *vars)
{
	if (vars->tab[vars->s - 1][vars->n] != '1' &&
			vars->tab[vars->s - 1][vars->n] != 'E')
	{
		vars->s--;
		if (vars->tab[vars->s][vars->n] == 'C')
		{
			vars->o = vars->s;
			vars->p = vars->n;
		}
		if (vars->tab[vars->s][vars->n] == 'E')
			exit(1);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->gimg, vars->w, vars->t);
		vars->t -= 75;
		move_count(vars);
	}
}

void	move_left_extention(t_vars *vars)
{
	if (vars->tab[vars->s][vars->n - 1] != '1' &&
			vars->tab[vars->s][vars->n - 1] != 'E')
	{
		vars->n--;
		if (vars->tab[vars->s][vars->n] == 'C')
		{
			vars->o = vars->s;
			vars->p = vars->n;
		}
		if (vars->tab[vars->s][vars->n] == 'E')
			exit(1);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->gimg, vars->w, vars->t);
		vars->w -= 75;
		move_count_left(vars);
	}
}

void	move_count_left(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->limg, vars->w, vars->t);
	ft_putnbr(vars->steps);
	write(1, "\n", 1);
}
