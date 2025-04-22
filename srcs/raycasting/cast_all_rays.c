#include "../../includes/cub3d.h"

void	cast_all_rays(t_data *game_data)
{
	float	current_ray_angle;
	int		ray_index;

	ray_index = 0;
	game_data->player.rays = (t_ray *) malloc(NUM_RAYS * sizeof(t_ray));
	current_ray_angle = angles_normalizer(game_data->player.angle - (FOV / 2));
	while (ray_index < NUM_RAYS)
	{
		game_data->player.rays[ray_index].ray_angle = angles_normalizer(current_ray_angle);
		cast_single_ray(&game_data->player.rays[ray_index], game_data);
		current_ray_angle += FOV / NUM_RAYS;
		ray_index++;
	}
}