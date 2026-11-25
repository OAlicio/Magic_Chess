#ifndef CHESS_H
#define CHESS_H

#include <mlx.h>
#include <mlx_keycodes.h>
#include <mlx_extended.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define UNSELECTED 0
#define SELECTED 1

#define MENU 0
#define PLAY 1
#define CURSOR_SOUND 0

extern char sound_path[1][128];
typedef struct s_menu_selector
{
	uint8_t selected_box;
	mlx_color selected[2];
} t_menu_selector;

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
	uint8_t game_state;
	t_menu_selector menu;
	mlx_channel s_channel;
	mlx_sound sounds[2];
	mlx_context mlx;
	mlx_window win;
	mlx_image canvas;
	mlx_window canvas_win;
} t_vars;

void update(void *arg);
void key_events(int key, void *param);
void window_events(int event, void *param);
void draw_start(mlx_context *mlx, mlx_window *win);
void draw_board(mlx_context *mlx, mlx_window *win);
void draw_menu_widgets(mlx_context *mlx, mlx_window *win, t_vars *vars);
void draw_empty_rect(mlx_context *mlx, mlx_window *win, t_vect2 start,
		t_size size, mlx_color color, char *text, t_vect2 text_offset);

#endif
