/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:54:30 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/15 19:55:54 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_vars {
	int		ot;
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
	void	*odimg;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;	
	char	*str;
	char	**tab;
	int		x;
	int		y;
	int		a;
	int		i;
	int		b;
	int		fd;
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
void	move_right_ondoor(t_vars *vars);
void	sprites_animation(t_vars *vars);
void	ft_animation(t_vars *vars);
int		loop_hook(t_vars *vars);
void	print_img5(t_vars *vars);
void	print_img6(t_vars *vars);
void	print_img4(t_vars *vars);
void	print_img3(t_vars *vars);

#endif
