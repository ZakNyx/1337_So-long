#include "so_long.h"

int	window_width(void)
{
	t_vars vars;
	
	vars.fd = open("./maps/map.ber", O_RDONLY);
	return (check_map(vars.fd));
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
		map_maker_macro(str, vars,  n,  m);
		n = 0;
		m += 75;
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

char **number(t_vars *vars)
{

	vars->fd = open("./maps/map.ber", O_RDONLY);
	vars->str = get_next_line(vars->fd);
	vars->x = number_line();
	vars->y = 0;
	vars->tab = malloc(sizeof(char *) * (vars->x + 1));
	while(vars->str)
	{
		vars->x = ft_strlen(vars->str);
		vars->tab[vars->y] = malloc(vars->x + 1);
		vars->str = get_next_line(vars->fd);
		vars->y++;
	}	
	ft_wall(vars->tab);
	if (vars->n == 0 && vars->s == 0)
	{
		vars->n = find_position_index(vars->tab);
		vars->s = find_position_line(vars->tab);
	}
	return vars->tab;
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
	if (vars->o == 0)
		vars->tab = number(vars);
	if (vars->o != 0 && vars->p != 0)
		vars->tab[vars->o][vars->p] = '0';
	if (keycode == 124)
		move_right(vars);
	else if (keycode == 125)
		move_down(vars);
	else if(keycode == 126)
		move_up(vars);
	else if(keycode == 123)
		move_left(vars);
	else if(keycode == 53)
		exit (1);
	return (0);
}

void sprites(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./sprites/player.xpm", &vars->x,  &vars->y);
	vars->limg = mlx_xpm_file_to_image(vars->mlx, "./sprites/playerleft.xpm", &vars->x,  &vars->y);
	vars->gimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/grass.xpm", &vars->x,  &vars->y);
	vars->wimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/wall.xpm", &vars->x,  &vars->y);
	vars->cimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/coin.xpm", &vars->x,  &vars->y);
	vars->dimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/closeddoor.xpm", &vars->x,  &vars->y);
	vars->oimg = mlx_xpm_file_to_image(vars->mlx, "./sprites/opendoor.xpm", &vars->x,  &vars->y);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.x = window_width() * 75;
	vars.y = window_height();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y , "Have Fun");
	sprites(&vars);
	map_maker(&vars);


	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}   