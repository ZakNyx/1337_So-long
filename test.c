#include "so_long.h"

int x;
int y;

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
		puts("im here");
		while(str[i])
		{
			if (str[i] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wimg, n, m);
			}
			else if (str[i] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->gimg, n, m);
			}
			else if (str[i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cimg, n, m);
			}
			else if (str[i] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win , vars->img, n, m);
			}
			else if (str[i] == 'E')
			{
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

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 124)
	{
		x += 75;
		mlx_clear_window(vars->mlx, vars->win);
		map_maker(vars);
		mlx_put_image_to_window(vars->mlx, vars->win , vars->img, x, y);
	}
	if(keycode == 125)
	{
		y += 75;
		mlx_clear_window(vars->mlx, vars->win);
		map_maker(vars);
		mlx_put_image_to_window(vars->mlx, vars->win , vars->img, x, y);
	}
	if(keycode == 126)
	{
		y -= 75;
		mlx_clear_window(vars->mlx, vars->win);
		map_maker(vars);
		mlx_put_image_to_window(vars->mlx, vars->win , vars->img, x, y);
	}
	if(keycode == 123)
	{
		x -= 75 ;
		mlx_clear_window(vars->mlx, vars->win);
		map_maker(vars);
		mlx_put_image_to_window(vars->mlx, vars->win , vars->img, x, y);
	}
	if(keycode == 53)
	{
		exit (1);	
	}

	return 0;
}

int	main(void)
{
	int a;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1500, 1000 , "Have Fun");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./sprites/player.xpm", &vars.x,  &vars.y);
	vars.gimg = mlx_xpm_file_to_image(vars.mlx, "./sprites/grass.xpm", &vars.x,  &vars.y);
	vars.wimg = mlx_xpm_file_to_image(vars.mlx, "./sprites/wall.xpm", &vars.x,  &vars.y);
	vars.cimg = mlx_xpm_file_to_image(vars.mlx, "./sprites/coin.xpm", &vars.x,  &vars.y);
	vars.dimg = mlx_xpm_file_to_image(vars.mlx, "./sprites/closeddoor.xpm", &vars.x,  &vars.y);
	map_maker(&vars);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}   