/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:50:47 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/15 19:51:52 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_img5(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 75);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img5, 12, 75);
}

void	print_img6(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 75);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img6, 12, 75);
}

void	print_img4(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 75);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img4, 12, 75);
}

void	print_img3(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 75);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, 12, 75);
}
