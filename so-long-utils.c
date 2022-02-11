/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so-long-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:25 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/10 19:19:25 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    map_maker_macro(char *str, t_vars *vars, int n, int m)
{
    int i;
    
    i = 0;
    while(str[i])
		{
			if (str[i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, n, m);
			else if (str[i] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
			else if (str[i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cimg, n, m);
			}
			else if (str[i] == 'P')
			{
				if (vars->w == 0 && vars->t == 0)
				{
					vars->w = n;
					vars->t = m;
				}
				mlx_put_image_to_window(vars->mlx, vars->win , vars->img, n, m);
			}
			else if (str[i] == 'E')
			{
				vars->doorx = n;
				vars->doory = m;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
				mlx_put_image_to_window(vars->mlx, vars->win , vars->dimg, n, m);
			}
			i++;
			n += 75;
		}
}
