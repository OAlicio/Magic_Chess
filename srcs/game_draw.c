#include <chess.h>

#define BOXS 64

void draw_board(mlx_context *mlx, mlx_window *win)
{
	int counter = 0;
	int row = 0;
	t_vect2 start = {.x = 0, .y = 0};
	t_size box_size = {.width = 75, .height = 75};
	for (; start.y + box_size.height < 480; start.y += box_size.height)
	{
		counter = 0;
		for (start.x = 0; start.x + box_size.width < 720; start.x += box_size.width)
		{
			if (!counter)
			{
				counter = 1;
				draw_rect(mlx, win, start, box_size,
						(mlx_color){.rgba = (row ? WHITES : BLACKS)});
				draw_empty_rect(mlx, win, start, box_size,
						(mlx_color){.rgba = (row ? WHITE : BLACK)}, NULL, start);
			}
			else
			{
				counter = 0;
				draw_rect(mlx, win, start, box_size,
						(mlx_color){.rgba = (!row ? WHITES : BLACKS)});
				draw_empty_rect(mlx, win, start, box_size,
						(mlx_color){.rgba = (!row ? WHITE : BLACK)}, NULL, start);
			}
		}
		row = !row;
	}
}
