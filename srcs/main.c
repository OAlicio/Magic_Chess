#include <chess.h>

char sound_path[1][128] = {"./res/sounds/cursor.wav"};

int main(void)
{
	t_vars vars = { 0 };
	vars.menu.selected[UNSELECTED] = (mlx_color){.rgba = 0x000000FF};
	vars.menu.selected[SELECTED] = (mlx_color){.rgba = 0x00B300FF};
	vars.mlx = mlx_init();

	mlx_set_fps_goal(vars.mlx, 60);
	mlx_set_font(vars.mlx, "./Roboto-Regular.ttf");
	mlx_set_font_scale(vars.mlx, "./Roboto-Regular.ttf", 24.f);
    mlx_window_create_info info = { 0 };
    info.title = "Magic Chess";
    info.width = WIDTH;
    info.height = HEIGHT;
    vars.win = mlx_new_window(vars.mlx, &info);

	vars.canvas = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.s_channel = mlx_new_audio_channel(vars.mlx);
	float sound_duration;
	vars.sounds[CURSOR_SOUND] = mlx_new_sound_from_wav(vars.mlx, sound_path[0], &sound_duration);

	//CREATE CANVAS WINDOWS, i cant put strings directly on the image, so this thing is helpfull
    mlx_window_create_info canvas_info = { 0 };
    canvas_info.render_target = vars.canvas;
    canvas_info.title = NULL;
    canvas_info.width = WIDTH;
    canvas_info.height = HEIGHT;

    vars.canvas_win = mlx_new_window(vars.mlx, &canvas_info);
	
	mlx_add_loop_hook(vars.mlx, update, &vars);

	mlx_on_event(vars.mlx, vars.win, MLX_WINDOW_EVENT, window_events, vars.mlx);
	mlx_on_event(vars.mlx, vars.win, MLX_KEYDOWN, key_events, &vars);

    mlx_loop(vars.mlx);
	mlx_destroy_sound(vars.mlx, vars.sounds[CURSOR_SOUND]);
	mlx_destroy_audio_channel(vars.mlx, vars.s_channel);
    mlx_destroy_window(vars.mlx, vars.canvas_win);
	mlx_destroy_image(vars.mlx, vars.canvas);
    mlx_destroy_window(vars.mlx, vars.win);
    mlx_destroy_context(vars.mlx);
}
