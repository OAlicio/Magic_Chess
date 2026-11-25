#include <chess.h>

void update(void *arg)
{
	t_vars *vars = (t_vars *)arg;
	mlx_clear_window(vars->mlx, vars->canvas_win, (mlx_color){ .rgba = 0x000000FF });
	mlx_clear_window(vars->mlx, vars->win, (mlx_color){ .rgba = 0x000000FF });

	if (vars->game_state == 0)
	{
		draw_start(&vars->mlx, &vars->canvas_win);
		draw_menu_widgets(&vars->mlx, &vars->canvas_win, vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->canvas, 0, 0);
}
