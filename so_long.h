#ifndef SO_LONG
# define SO_LONG

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
#include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*dimg;
	void	*gimg;
	void	*wimg;
	void	*cimg;
	void	*limg;
	int		x;
	int		y;
	int 	a;
	int		i;
	int		b;
	int		fd;
	char	*str;
	char	**tab;
	char	**tab2;
	int		n;
	int		m;
	int		t; //y
	int		w; //x
	int		p;
	int		o;
	int		s;
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
static void	ft_strcat(char	*s1, char	*s2);
char	*ft_strjoin(char *s1, char c);
static void	ft_strcpy(char	*s1, const char	*s2);
char	*ft_strdup(const char	*s1);
int		check_map(int fd);
size_t	ft_strlen(const char *c);

#endif