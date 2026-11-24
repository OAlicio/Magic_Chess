#include <chess.h>

void window_events(int event, void *param)
{
	if (event == MLX_WINDOW_CLOSE)
		mlx_loop_end((mlx_context)param);
}

void key_events(int key, void *param)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_loop_end((mlx_context)param);
}

void
draw_empty_rect(mlx_context *mlx, mlx_window *win, t_vect2 start, t_size size, mlx_color color, char *text, t_vect2 text_offset)
{
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = 0;
	for (int y = 0; y < size.height; ++y)
	{
		if (y == 0 || y == size.height - 1)
		{
			for (int x = 0; x < size.width; ++x)
			{
				mlx_pixel_put(*mlx, *win, x + start.x, y + start.y, color);
			}
		}
		else
		{
				mlx_pixel_put(*mlx, *win, 0 + start.x, y + start.y, color);
				mlx_pixel_put(*mlx, *win, start.x + size.width - 1, y + start.y, color);
		}
	}
	if (text)
	{
		t_vect2 text_start = {.x = start.x + (size.width/2) - text_offset.x, .y = start.y + (size.height/2) + text_offset.y};
		if (text_start.x < 0)
			text_start.x = 0;
		if (text_start.y < 0)
			text_start.y = 0;
		mlx_string_put(*mlx, *win, text_start.x, text_start.y, (mlx_color){.rgba = 0x000000FF}, text);
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

void
draw_menu_widgets(mlx_context *mlx, mlx_window *win, mlx_color color)
{
	t_size box_size = {.width = 180, .height = 40};
	char text[3][32] = {"PLAY", "OPTIONS", "EXIT"};
	t_vect2 start = {.x = 10, .y = 480/2};
	for (int i = 0; i < 3; ++i)
	{
		start.y += box_size.height + 10;
		draw_empty_rect(mlx, win,
			start, box_size, color, text[i], (t_vect2){.x = 24, .y = 6});
	}
}

void draw_board(mlx_context *mlx, mlx_window *win)
{
}



void update(void *arg)
{
	t_vars *vars = (t_vars *)arg;
	mlx_clear_window(vars->mlx, vars->win, (mlx_color){ .rgba = 0x334D4DFF });

	draw_start(&vars->mlx, &vars->canvas_win);
	draw_menu_widgets(&vars->mlx, &vars->canvas_win, (mlx_color){.rgba = 0x000000FF});
	//mlx_string_put(vars->mlx, vars->canvas_win, 160, 120, (mlx_color){ .rgba = 0xFF2066FF }, "text");
	//mlx_string_put(vars->mlx, vars->canvas_win, 120, 120, (mlx_color){.rgba = 0x000000FF}, "PLAY");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->canvas, 0, 0);
}

int main(void)
{
	t_vars vars;
	vars.mlx = mlx_init();

	mlx_set_fps_goal(vars.mlx, 60);
	mlx_set_font(vars.mlx, "./Roboto-Regular.ttf");
	mlx_set_font_scale(vars.mlx, "./Roboto-Regular.ttf", 24.f);
    mlx_window_create_info info = { 0 };
    info.title = "Magic Chess";
    info.width = 720;
    info.height = 480;
    vars.win = mlx_new_window(vars.mlx, &info);

	vars.canvas = mlx_new_image(vars.mlx, 720, 480);

	//CREATE CANVAS WINDOWS, i cant put strings directly on the image, so this thing is helpfull
    mlx_window_create_info canvas_info = { 0 };
    canvas_info.render_target = vars.canvas;
    canvas_info.title = NULL;
    canvas_info.width = 720;
    canvas_info.height = 480;
    vars.canvas_win = mlx_new_window(vars.mlx, &canvas_info);
	
	mlx_add_loop_hook(vars.mlx, update, &vars);
	//mlx_string_put(vars.mlx, vars.canvas_win, 120, 120,
	//	(mlx_color){.rgba = 0xFFFFFFFF}, "TEST TEXT");

	//mlx_put_transformed_image_to_window(vars.mlx, vars.win, vars.canvas, 0, 0, 1.0f, 1.0f, 0);

	mlx_on_event(vars.mlx, vars.win, MLX_WINDOW_EVENT, window_events, vars.mlx);
	mlx_on_event(vars.mlx, vars.win, MLX_KEYDOWN, key_events, vars.mlx);

    mlx_loop(vars.mlx);
    mlx_destroy_window(vars.mlx, vars.canvas_win);
	mlx_destroy_image(vars.mlx, vars.canvas);
    mlx_destroy_window(vars.mlx, vars.win);
    mlx_destroy_context(vars.mlx);
}
