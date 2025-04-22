#include "../../includes/cub3d.h"

t_mlx	*mlx_initializer(void)
{
	t_mlx	*mlx_instance;

	mlx_instance = (t_mlx *) malloc(sizeof(t_mlx));
	mlx_instance->mlx_ptr = mlx_init();
	mlx_instance->win = mlx_new_window(mlx_instance->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	return (mlx_instance);
}

void	initialize_player(t_data *game_data)
{
	game_data->player.x *= TILE_SIZE;
	game_data->player.y *= TILE_SIZE;
	game_data->player.turn_direction = 0;
	game_data->player.walk_direction = 0;
	game_data->player.strafe_direction = 0;
	game_data->player.move_speed = 4.5;
	game_data->player.rotation_speed = 3.5 * (PI / 180);
}