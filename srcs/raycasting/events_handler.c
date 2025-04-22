#include "../../includes/cub3d.h"

int	handle_key_pressed(int keycode, t_data *game_data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game_data->mlx->mlx_ptr, game_data->mlx->win);
		exit(1);
	}
	else if (keycode == W_KEY)
		game_data->player.walk_direction = 1;
	else if (keycode == S_KEY)
		game_data->player.walk_direction = -1;
	else if (keycode == D_KEY)
		game_data->player.strafe_direction = 1;
	else if (keycode == A_KEY)
		game_data->player.strafe_direction = -1;
	else if (keycode == RIGHT_ARROW)
		game_data->player.turn_direction = 1;
	else if (keycode == LEFT_ARROW)
		game_data->player.turn_direction = -1;
	return (0);
}

int	handle_key_released(int keycode, t_data *game_data)
{
	if (keycode == W_KEY)
		game_data->player.walk_direction = 0;
	else if (keycode == S_KEY)
		game_data->player.walk_direction = 0;
	else if (keycode == RIGHT_ARROW)
		game_data->player.turn_direction = 0;
	else if (keycode == LEFT_ARROW)
		game_data->player.turn_direction = 0;
	else if (keycode == D_KEY || keycode == A_KEY)
		game_data->player.strafe_direction = 0;
	return (0);
}