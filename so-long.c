#include "so_long.h"

int x;
int y;
int a,b;


int	window_width(void)
{
	t_vars vars;
	
	vars.fd = open("./maps/map.ber", O_RDONLY);
	return (check_map(vars.fd) * 75);
}

int	window_height(void)
{
	t_vars vars;
	
	vars.fd = open("./maps/map.ber", O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.y = 0;
	while (vars.str != NULL)
	{
		vars.y = vars.y + 75;
		vars.str = get_next_line(vars.fd);
	}
	return (vars.y);
}

int	number_line(void)
{
	t_vars vars; 

	vars.fd = open("./maps/map.ber", O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.x = 0;
	vars.y = 0;
	while(vars.str)
	{
		vars.x++;
		vars.str = get_next_line(vars.fd);
	}
	return vars.x;
}


void	map_maker(t_vars *vars)
{
	int n = 0;
	int m = 0;
	int fd = open("./maps/map.ber", O_RDONLY);
	char *str = get_next_line(fd);
	int i;

	i = 0;
	while (str)
	{
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
				if (x == 0 && y == 0)
				{
					x = n;
					y = m;
				}
				mlx_put_image_to_window(vars->mlx, vars->win , vars->img, n, m);
			}
			else if (str[i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
				mlx_put_image_to_window(vars->mlx, vars->win , vars->dimg, n, m);
			}
			i++;
			n += 75;
		}
		n = 0;
		m += 75;
		i = 0;
		str = get_next_line(fd);
	}
	
}

char **number();

int        find_position_index(char **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[j])
    {
        while (tab[j][i])
        {
            if (tab[j][i] == 'P')
                return i;
            i++;
        }
        i = 0;
        j++;
    }
    return 0;
}

int        find_position_line(char **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[j])
    {
        while (tab[j][i])
        {
            if (tab[j][i] == 'P')
                return j;
            i++;
        }
        i = 0;
        j++;
    }
    return 0;
}

char	**ft_wall(char **tab)
{
	t_vars vars;

	vars.fd = open("./maps/map.ber", O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.x = 0;
	vars.y = 0;
	vars.a = 0;
	while (vars.str)
	{
		while (vars.str[vars.x])
		{
			tab[vars.y][vars.a] = vars.str[vars.x];
			vars.x++;
			vars.a++;
		}
		tab[vars.y][vars.a] = '\0';
		vars.x = 0;
		vars.a = 0;
		vars.y++;
		vars.str = get_next_line(vars.fd);
	}
	tab[vars.y] = NULL;
	return tab;
}

char **number()
{
	t_vars vars; 

	vars.fd = open("./maps/map.ber", O_RDONLY);
	vars.str = get_next_line(vars.fd);
	vars.x = number_line();
	vars.y = 0;
	vars.tab = malloc(sizeof(char *) * (vars.x + 1));
	while(vars.str)
	{
		vars.x = strlen(vars.str);
		vars.tab[vars.y] = malloc(vars.x + 1);
		vars.str = get_next_line(vars.fd);
		vars.y++;
	}	
	ft_wall(vars.tab);
	if (a == 0 && b == 0)
	{
		a = find_position_index(vars.tab);
		b = find_position_line(vars.tab);
	}
	return vars.tab;
}

int coin_checker(t_vars *vars)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while(vars->tab[j])
	{
		while(vars->tab[j][i])
		{
			if(vars->tab[j][i] == 'C')
				return(1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int  i = 0;
	if ( o == 0 )
		vars->tab = number();
	if (o != 0 && p != 0)
		vars->tab[o][p] = '0';
	if (keycode == 124)
	{
		if(vars->tab[b][a + 1] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);
		}		
		if (vars->tab[b][a + 1] != '1' && vars->tab[b][a + 1] != 'E')
		{
			a++;
			if(vars->tab[b][a] == 'C')
			{
				o = b;
				p = a;
			}
			if(vars->tab[b][a] == 'E')
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			x += 75;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
		}
	}
	else if (keycode == 125)
	{
		if(vars->tab[b + 1][a] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);
		}	
		if (vars->tab[b + 1][a] != '1' && vars->tab[b + 1][a] != 'E')
		{
			b++;
			if(vars->tab[b][a] == 'C')
			{				
				o = b;
				p = a;
			}
			if(vars->tab[b][a] == 'E')
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			y += 75;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
		}
	}
	else if(keycode == 126)
	{
		if(vars->tab[b - 1][a] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);
		}	
		if (vars->tab[b - 1][a] != '1' && vars->tab[b - 1][a] != 'E')
		{
			b--;
			if(vars->tab[b][a] == 'C')
			{
				o = b;
				p = a;
			}
			if(vars->tab[b][a] == 'E')
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			y -= 75;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
		}
	}
	else if(keycode == 123)
	{
		if(vars->tab[b][a - 1] == 'E')
		{
			vars->x = coin_checker(vars);
			if(vars->x == 0)
				exit(1);
		}	
		if (vars->tab[b][a - 1] != '1' && vars->tab[b][a - 1] != 'E')
		{
			a--;
			if(vars->tab[b][a] == 'C')
			{
				o = b;
				p = a;
			}
			if(vars->tab[b][a] == 'E' )
				exit(1);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			x -= 75 ;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, x, y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->limg, x, y);
		}
	}
	else if(keycode == 53)
		exit (1);

	return 0;
}

void sprites(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./sprites/player.xpm", &vars->x,  &vars->y);
	vars->limg = mlx_xpm_file_to_image(vars->mlx, "./sprites/playerleft.xpm", &vars->x,  &vars->y);
	vars->gimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/grass.xpm", &vars->x,  &vars->y);
	vars->wimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/wall.xpm", &vars->x,  &vars->y);
	vars->cimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/coin.xpm", &vars->x,  &vars->y);
	vars->dimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/closeddoor.xpm", &vars->x,  &vars->y);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.x = window_width();
	vars.y = window_height();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y , "Have Fun");
	sprites(&vars);
	map_maker(&vars);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}   