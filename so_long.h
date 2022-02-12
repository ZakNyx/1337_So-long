/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:02 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/12 18:25:08 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*dimg;
	void	*gimg;
	void	*wimg;
	void	*cimg;
	void	*limg;
	void	*oimg;
	void	*eimg;
	int		x;
	int		y;
	int 	a;
	int		i;
	int		b;
	int		fd;
	char	*str;
	char	**tab;
	int		n;
	int		m;
	int		t;
	int		w;
	int		p;
	int		o;
	int		s;
	int		doorx;
	int		doory;
	int		steps;
	}				t_vars;

typedef struct s_map
{
	int check;
	int a;
	int b;
	char *s1;
	char *s2;
}		t_map;


char    *get_next_line(int  fd);
char	*ft_strjoin(char *s1, char c);
char	*ft_strdup(const char	*s1);
int		check_map(int fd);
size_t	ft_strlen(const char *c);
void    move_right(t_vars *vars);
void    move_down(t_vars *vars);
void    move_up(t_vars *vars);
void    move_left(t_vars *vars);
int 	coin_checker(t_vars *vars);
void    map_maker_macro(char *str, t_vars *vars, int n, int m);
char    *ft_itoa(int n);

#endif