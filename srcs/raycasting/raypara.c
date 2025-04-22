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
void	rays_parameters(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		calcule_wall_coordinates(data, i);
		if (!data->player.rays[i].player_hit_vertical_wall)
			data->player.rays[i].offset_x = \
			(int)data->player.rays[i].wall_hit_y % TILE_SIZE;
		else
			data->player.rays[i].offset_x = \
			(int)data->player.rays[i].wall_hit_x % TILE_SIZE;
		i++;
	}
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	distance_to_wall(t_ray *ray, t_data *data)
{
	double	horz_distance;
	double	vert_distance;

	horz_distance = distance_between_points(data->player.x, data->player.y, \
	ray->horizontal_intercept_x, ray->horizontal_intercept_y);
	vert_distance = distance_between_points(data->player.x, data->player.y, \
	ray->x_intercept_v, ray->y_intercept_v);
	if (horz_distance > vert_distance)
	{
		ray->player_hit_vertical_wall = 0;
		ray->wall_hit_x = ray->x_intercept_v ;
		ray->wall_hit_y = ray->y_intercept_v;
		ray->distance = vert_distance;
	}
	else
	{
		ray->player_hit_vertical_wall = 1;
		ray->wall_hit_x = ray->horizontal_intercept_x;
		ray->wall_hit_y = ray->horizontal_intercept_y;
		ray->distance = horz_distance;
	}
}