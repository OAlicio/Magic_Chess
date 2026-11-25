#include <chess.h>

void
draw_menu_widgets(mlx_context *mlx, mlx_window *win, t_vars *vars)
{
	t_size box_size = {.width = 180, .height = 40};
	char text[3][32] = {"PLAY", "OPTIONS", "EXIT"};
	t_vect2 start = {.x = 10, .y = 480/2};
	for (int i = 0; i < 3; ++i)
	{
		start.y += box_size.height + 10;
		draw_empty_rect(mlx, win,
			start, box_size, vars->menu.selected[(vars->menu.selected_box == i)], text[i], (t_vect2){.x = (strlen(text[i]) / 2) * 12, .y = 6});
	}
}

void draw_start(mlx_context *mlx, mlx_window *win)
{
	for(int y = 0; y < 480; y++)
    {
		for(int x = 0; x < 720; x++)
			mlx_pixel_put(*mlx, *win, x, y, (mlx_color){ .rgba = 0x868e96FF });
    }
}


