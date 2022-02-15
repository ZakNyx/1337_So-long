/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:42:52 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/15 19:50:42 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sprites_animation(t_vars *vars)
{
	vars->img1 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin1.xpm", &vars->x, &vars->y);
	vars->img2 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin2.xpm", &vars->x, &vars->y);
	vars->img3 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin3.xpm", &vars->x, &vars->y);
	vars->img4 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin4.xpm", &vars->x, &vars->y);
	vars->img5 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin5.xpm", &vars->x, &vars->y);
	vars->img6 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/coin6.xpm", &vars->x, &vars->y);
}

void	ft_animation(t_vars *vars)
{
	if (vars->ot >= 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 75);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 12, 75);
	}
	if (vars->ot >= 10)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 75);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, 12, 75);
	}
	if (vars->ot >= 15)
		print_img3(vars);
	if (vars->ot >= 20)
		print_img4(vars);
	if (vars->ot >= 25)
		print_img5(vars);
	if (vars->ot >= 30)
		print_img6(vars);
	vars->ot++;
	if (vars->ot == 32)
		vars->ot = 0;
}

int	loop_hook(t_vars *vars)
{
	ft_animation(vars);
	return (0);
}
