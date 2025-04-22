#include "../../includes/cub3d.h"

void	calcule_wall_coordinates(t_data *game_data, int ray_index)
{
	double	corrected_wall_distance;

	corrected_wall_distance = game_data->player.rays[ray_index].distance * \
	cos(game_data->player.rays[ray_index].ray_angle - game_data->player.angle);
	game_data->player.rays[ray_index].distance = game_data->player.rays[ray_index].distance * \
	cos(FOV / 2);
	game_data->player.rays[ray_index].distance_to_projection_plane = (WIN_WIDTH / 2) / \
		tan(FOV / 2);
	game_data->player.rays[ray_index].wall_strip_height = (TILE_SIZE / corrected_wall_distance \
	* game_data->player.rays[ray_index].distance_to_projection_plane);
	game_data->player.rays[ray_index].wall_cordinate.top = (WIN_HEIGHT / 2) - \
	(game_data->player.rays[ray_index].wall_strip_height / 2);
	if (game_data->player.rays[ray_index].wall_cordinate.top < 0)
		game_data->player.rays[ray_index].wall_cordinate.top = 0;
	game_data->player.rays[ray_index].wall_cordinate.bottom = \
	game_data->player.rays[ray_index].wall_cordinate.top + \
	game_data->player.rays[ray_index].wall_strip_height;
	if (game_data->player.rays[ray_index].wall_cordinate.bottom > WIN_HEIGHT)
		game_data->player.rays[ray_index].wall_cordinate.bottom = WIN_HEIGHT;
}