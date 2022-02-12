/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:01 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/12 19:38:42 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_right(t_vars *vars)
{
		vars->steps++;
		vars->x = coin_checker(vars);
        if (vars->x == 0)
            	mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg, vars->doorx, vars->doory);
		if(vars->tab[vars->s][vars->n + 1] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);	
		}		
		if (vars->tab[vars->s][vars->n + 1] != '1' && vars->tab[vars->s][vars->n + 1] != 'E')
		{
			vars->n++;
			if(vars->tab[vars->s][vars->n] == 'C')
			{
				vars->o = vars->s;
				vars->p = vars->n;
			}
			if(vars->tab[vars->s][vars->n] == 'E')
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
			vars->w += 75;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 0);
			mlx_string_put ( vars->mlx, vars->win, 0, 30, 0xFFFFFF, ft_itoa(vars->steps));
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->w, vars->t);
			if(vars->tab[vars->s][vars->n] == 'N')
			{
				write(1, "GAME OVER !", 12);
				exit(1);
			}
		}
}

void    move_down(t_vars *vars)
{
		vars->steps++;
		vars->x = coin_checker(vars);
        if (vars->x == 0)
            	mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg, vars->doorx, vars->doory);
    	if(vars->tab[vars->s + 1][vars->n] == 'E')
            {
                vars->x = coin_checker(vars);
                if(vars->x == 0)
                    exit(1);
            }	
            if (vars->tab[vars->s + 1][vars->n] != '1' && vars->tab[vars->s + 1][vars->n] != 'E')
            {
                vars->s++;
                if(vars->tab[vars->s][vars->n] == 'C')
                {				
                    vars->o = vars->s;
                    vars->p = vars->n;
                }
                if(vars->tab[vars->s][vars->n] == 'E')
                    exit(1);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
                vars->t += 75;
                mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->w, vars->t);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 0);
				mlx_string_put ( vars->mlx, vars->win, 0, 30, 0xFFFFFF, ft_itoa(vars->steps));
            }
			if(vars->tab[vars->s][vars->n] == 'N')
			{
				write(1, "GAME OVER !", 12);
				exit(1);
			}
}

void    move_up(t_vars *vars)
{
		vars->steps++;
		vars->x = coin_checker(vars);
        if (vars->x == 0)
            	mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg, vars->doorx, vars->doory);
    		if(vars->tab[vars->s - 1][vars->n] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);
		}	
		if (vars->tab[vars->s - 1][vars->n] != '1' && vars->tab[vars->s - 1][vars->n] != 'E')
		{
			vars->s--;
			if(vars->tab[vars->s][vars->n] == 'C')
			{
				vars->o = vars->s;
				vars->p = vars->n;
			}
			if(vars->tab[vars->s][vars->n] == 'E')
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
			vars->t -= 75;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->w, vars->t);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 0);
			mlx_string_put ( vars->mlx, vars->win, 0, 30, 0xFFFFFF, ft_itoa(vars->steps));
			if(vars->tab[vars->s][vars->n] == 'N')
			{
				write(1, "GAME OVER !", 12);
				exit(1);
			}
		}
}

void    move_left(t_vars *vars)
{
		vars->steps++;
		vars->x = coin_checker(vars);
        if (vars->x == 0)
            	mlx_put_image_to_window(vars->mlx, vars->win, vars->oimg, vars->doorx, vars->doory);	
    	if(vars->tab[vars->s][vars->n - 1] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);
		}	
		if (vars->tab[vars->s][vars->n - 1] != '1' && vars->tab[vars->s][vars->n - 1] != 'E')
		{
			vars->n--;
			if(vars->tab[vars->s][vars->n] == 'C')
			{
				vars->o = vars->s;
				vars->p = vars->n;
			}
			if(vars->tab[vars->s][vars->n] == 'E' )
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
			vars->w -= 75 ;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, vars->w, vars->t);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->limg, vars->w, vars->t);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, 0, 0);
			mlx_string_put ( vars->mlx, vars->win, 0, 30, 0xFFFFFF, ft_itoa(vars->steps));
		}
			if(vars->tab[vars->s][vars->n] == 'N')
			{
				write(1, "GAME OVER !", 12);
				exit(1);
			}
}