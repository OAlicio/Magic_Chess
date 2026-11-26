#include <chess.h>

#define BOXS 64

void draw_board(mlx_context *mlx, mlx_window *win)
{
	int counter = 0;
	int row = 0;
	t_vect2 start = {.x = 0, .y = 0};
	t_size box_size = {.width = 40, .height =  40};
	for (; start.y < 480; start.y += 40)
	{
		for (start.x = 0; start.x < 720; start.x += 40)
		{
			if (!counter)
			{
				counter = 1;
				draw_rect(mlx, win, start, box_size,
						(mlx_color){.rgba = (row ? WHITES : BLACKS)});
			}
			else
			{
				counter = 0;
				draw_rect(mlx, win, start, box_size,
						(mlx_color){.rgba = (!row ? WHITES : BLACKS)});
			}
		}
		row = !row;
	}
}
