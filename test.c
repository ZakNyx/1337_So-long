#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*gimg;
	void	*wimg;
	void	*path;
	void	*wpath;
	void	*gpath;
	int		x,y;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	int a;
	if (keycode == 124)
	{
		a += 90;
		mlx_put_image_to_window(vars->mlx, vars->win , vars->img, a, 85);
	}
	return 0;
}

int	main(void)
{
	t_vars	vars;
	t_vars  grass;
	int a;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "testaloalo");
	vars.path = "./player.xpm";
	vars.gpath = "./grass.xpm";
	vars.wpath = "./wall.xpm";

	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.path, &vars.x,  &vars.y);
	vars.gimg = mlx_xpm_file_to_image(vars.mlx, vars.gpath, &vars.x,  &vars.y);
	vars.wimg = mlx_xpm_file_to_image(vars.mlx, vars.wpath, &vars.x,  &vars.y);

	while (a <= 1000)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.wimg, a, 0);
		a += 75;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.gimg, 0, 75);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 15, 85);
	

	mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_loop(vars.mlx);
}   