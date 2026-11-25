#include <chess.h>

void window_events(int event, void *param)
{
	if (event == MLX_WINDOW_CLOSE)
		mlx_loop_end((mlx_context)param);
}

void key_events(int key, void *param)
{
	t_vars *vars = (t_vars *)param;
	if (key == MLX_KEY_ESCAPE)
		mlx_loop_end((mlx_context)vars->mlx);
	if (vars->game_state == 0)
	{
		if (key == MLX_KEY_UP)
		{
			if (vars->menu.selected_box == 0)
				vars->menu.selected_box = 2;
			else
				--vars->menu.selected_box;
		}
		else if (key == MLX_KEY_DOWN)
		{
			++vars->menu.selected_box;
			if (vars->menu.selected_box > 2)
				vars->menu.selected_box = 0;
		}
	}
	printf("selected box %d\n", vars->menu.selected_box);
}
