#include <chess.h>

void clear_windows(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->canvas_win, (mlx_color){ .rgba = 0x000000FF });
	mlx_clear_window(vars->mlx, vars->win, (mlx_color){ .rgba = 0x000000FF });
}

void update(void *arg)
{
	t_vars *vars = (t_vars *)arg;

	clear_windows(vars);
	if (vars->game_state == MENU)
	{
		draw_start(&vars->mlx, &vars->canvas_win);
		draw_menu_widgets(&vars->mlx, &vars->canvas_win, vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->canvas, 0, 0);
}
