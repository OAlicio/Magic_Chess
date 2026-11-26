#include <chess.h>

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
	if (text && text[0]) //MacroLibX warns when try to pass empty string to mlx_string_put
	{
		t_vect2 text_start = {.x = start.x + (size.width/2) - text_offset.x, .y = start.y + (size.height/2) + text_offset.y};
		if (text_start.x < 0)
			text_start.x = 0;
		if (text_start.y < 0)
			text_start.y = 0;
		mlx_string_put(*mlx, *win, text_start.x, text_start.y, (mlx_color){.rgba = 0x000000FF}, text);
	}
}

void
draw_rect(mlx_context *mlx, mlx_window *win, t_vect2 start, t_size size, mlx_color color)
{
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = 0;
	for (int y = 0; y < size.height; ++y)
	{
		for (int x = 0; x < size.width; ++x)
		{
			mlx_pixel_put(*mlx, *win, x + start.x, y + start.y, color);
		}
	}
}
