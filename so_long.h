/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:19:02 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/13 18:58:22 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_vars {
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
	int		a;
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
	int		drx;
	int		dry;
	int		steps;
}		t_vars;

typedef struct s_map
{
	int		check;
	int		a;
	int		b;
	char	*s1;
	char	*s2;
}		t_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char c);
char	*ft_strdup(const char	*s1);
int		check_map(int fd);
size_t	ft_strlen(const char *c);
void	move_right(t_vars *vars);
void	move_down(t_vars *vars);
void	move_up(t_vars *vars);
void	move_left(t_vars *vars);
int		coin_checker(t_vars *vars);
void	map_maker_macro(char *str, t_vars *vars, int n, int m);
char	*ft_itoa(int n);
void	sprites(t_vars *vars);
int		destroy(t_vars *vars);
int		window_width(char *s);
int		window_height(char *s);
int		number_line(char *s);
void	map_maker(t_vars *vars, char *s);
int		find_position_index(char **tab);
int		find_position_line(char **tab);
void	move_right_extention(t_vars *vars);
void	move_down_extention(t_vars *vars);
void	move_up_extention(t_vars *vars);
void	move_left_extention(t_vars *vars);
void	move_count_left(t_vars *vars);
void	move_count(t_vars *vars);

#endif