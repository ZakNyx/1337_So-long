/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_extention_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:52:14 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/16 18:25:16 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_right_extention(t_vars *vars)
{
	if (vars->tab[vars->s][vars->n + 1] != '1'
			&& vars->tab[vars->s][vars->n + 1] != 'E')
	{
		vars->steps++;
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
		if (vars->tab[vars->s][vars->n] == 'N')
		{
			write(1, "GAME OVER !", 12);
			exit(1);
		}
	}
}

void	move_down_extention(t_vars *vars)
{
	if (vars->tab[vars->s + 1][vars->n] != '1' &&
			vars->tab[vars->s + 1][vars->n] != 'E')
	{
		vars->steps++;
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
		if (vars->tab[vars->s][vars->n] == 'N')
		{
			write(1, "GAME OVER !", 12);
			exit(1);
		}
	}
}

void	move_up_extention(t_vars *vars)
{
	if (vars->tab[vars->s - 1][vars->n] != '1' &&
			vars->tab[vars->s - 1][vars->n] != 'E')
	{
		vars->steps++;
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
		if (vars->tab[vars->s][vars->n] == 'N')
		{
			write(1, "GAME OVER !", 12);
			exit(1);
		}
	}
}

void	move_left_extention(t_vars *vars)
{
	if (vars->tab[vars->s][vars->n - 1] != '1' &&
			vars->tab[vars->s][vars->n - 1] != 'E')
	{
		vars->steps++;
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
		if (vars->tab[vars->s][vars->n] == 'N')
		{
			write(1, "GAME OVER !", 12);
			exit(1);
		}
	}
}

void	move_count_left(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->limg, vars->w, vars->t);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 0, 30, 0xFFFFFF, ft_itoa(vars->steps));
}
