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
draw_empty_rect(mlx_context *mlx, mlx_image *canvas, t_vect2 start, t_size size)
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
				mlx_set_image_pixel(*mlx, *canvas, x + start.x, y + start.y, (mlx_color){ .rgba = 0x000000FF });
			}
		}
		else
		{
				mlx_set_image_pixel(*mlx, *canvas, 0 + start.x, y + start.y, (mlx_color){ .rgba = 0x000000FF });
				mlx_set_image_pixel(*mlx, *canvas, start.x + size.width - 1, y + start.y, (mlx_color){ .rgba = 0x000000FF });
		}
	}
}

void draw_start(mlx_context *mlx, mlx_image *canvas)
{
	for(int y = 0; y < 480; y++)
    {
		for(int x = 0; x < 720; x++)
			mlx_set_image_pixel(*mlx, *canvas, x, y, (mlx_color){ .rgba = 0x868e96FF });
    }
}

void draw_board(mlx_context *mlx, mlx_window *win)
{
	/*
	for ()
	{}
	*/
}

int main(void)
{
	mlx_context mlx = mlx_init();

    mlx_window_create_info info = { 0 };
    info.title = "Hello World!";
    info.width = 720;
    info.height = 480;
    mlx_window win = mlx_new_window(mlx, &info);

	mlx_image canvas = mlx_new_image(mlx, 720, 480);

	draw_start(&mlx, &canvas);
	draw_empty_rect(&mlx, &canvas,
			(t_vect2){.x = 10, .y = 10}, (t_size){.width = 40, .height = 40});
	//mlx_set_image_rectangle(mlx, canvas, 10, 20, 80, 70, (mlx_color){.rgba = 0x000000FF});
    /*mlx_window_create_info target_info = { 0 };
    target_info.render_target = target;
    mlx_window target_win = mlx_new_window(mlx, &target_info);
	*/
    /*for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
            mlx_pixel_put(mlx, win, i, j, (mlx_color){ .rgba = 0xFF0000FF });
    }
	*/
	mlx_put_image_to_window(mlx, win, canvas, 0, 0);

	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_events, mlx);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_events, mlx);

    mlx_loop(mlx);
	mlx_destroy_image(mlx, canvas);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
}
