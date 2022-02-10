#include "so_long.h"

void	check_1(char	*s)
{
	int	a;

	a = 0;
	while (s[a])
	{
		if (s[a] != '1')
		{
			write (2, "first or last line isn't made of only walls", 44);
			exit (0);
		}
		a++;
	}
}

void	check_line(char	*s, int a)
{
	int	i;

	i = 0;
	if (s[0] != '1' || s[a - 1] != '1')
	{
		write (2, "side walls don't exist", 23);
		exit (0);
	}
	while (s[i])
	{
		if (s[i] != 'C' && s[i] != 'E' && s[i] != 'P'
			&& s[i] != '0' && s[i] != '1' && s[i] != 'K')
		{
			write (2, "unkown ellement in the map", 27);
			exit (0);
		}
		i++;
	}
}

int	check_elements(char	*s, int a)
{
	static int	p;
	static int	c;
	static int	e;
	int			i;

	check_line(s, a);
	i = 0;
	while (s[i])
	{
		if (s[i] == 'P')
			p = 3;
		if (s[i] == 'C')
			c = 1;
		if (s[i] == 'E')
			e = 5;
		i++;
	}
	return (1 + p + c + e);
}

static void	loop(t_map *map, int fd)
{
	while (map->s1)
	{
		map->b = strlen(map->s1);
		if (map->a != map->b)
		{
			write (2, "map is not rectangular", 23);
			exit (0);
		}
		map->check = check_elements(map->s1, map->a);
		map->s2 = map->s1;
		map->s1 = get_next_line(fd);
	}
}

int	check_map(int fd)
{
	t_map	map;

	map.s1 = get_next_line(fd);
	map.a = strlen(map.s1);
	check_1(map.s1);
	loop(&map, fd);
	if (map.a != map.b)
	{
		write (2, "map is not rectangular", 23);
		exit (0);
	}
	check_1(map.s2);
	if (map.check != 10)
	{
		write (2, "one or more ellements are missing", 34);
		exit (0);
	}
	return (map.a);
}
