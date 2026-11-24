#ifndef CHESS_H
#define CHESS_H

#include <mlx.h>
#include <mlx_keycodes.h>
#include <mlx_extended.h>
#include <unistd.h>
#include <string.h>

typedef struct s_vect2
{
	int x;
	int y;
} t_vect2;

typedef struct s_size
{
	int width;
	int height;
} t_size;

typedef struct s_vars
{
	mlx_context mlx;
	mlx_window win;
	mlx_image canvas;
	mlx_window canvas_win;
} t_vars;

#endif
