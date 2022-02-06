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
	int		x,y;
	int		fd;
	char	*str;
}				t_vars;

char    *get_next_line(int  fd);
static size_t	ft_strlen(const char *c);
static void	ft_strcat(char	*s1, char	*s2);
char	*ft_strjoin(char *s1, char c);
static void	ft_strcpy(char	*s1, const char	*s2);
char	*ft_strdup(const char	*s1);

#endif