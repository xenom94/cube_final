#include "../../includes/cub3d.h"

void	cast_single_ray(t_ray *ray, t_data *game_data)
{
	calculate_horizontal_intersection(ray, game_data);
	calculate_vertical_intersection(ray, game_data);
	check_horizontal_walls(ray, game_data);
	check_vertical_walls(ray, game_data);
	compute_wall_distance(ray, game_data);
}

void	calculate_horizontal_intersection(t_ray *ray, t_data *game_data)
{
	double	inverse_tangent;

	inverse_tangent = -1 / tan(ray->ray_angle);
	if (ray->ray_angle > M_PI)
	{
		ray->horizontal_intercept_y = (int)(game_data->player.y / TILE_SIZE) * \
		TILE_SIZE - 0.001;
		ray->horizontal_intercept_x = (game_data->player.y - ray->horizontal_intercept_y) * \
		inverse_tangent + game_data->player.x;
		ray->horizontal_step_y = -TILE_SIZE;
	}
	else if (ray->ray_angle < M_PI)
	{
		ray->horizontal_intercept_y = (int)(game_data->player.y / TILE_SIZE) * \
		TILE_SIZE + TILE_SIZE;
		ray->horizontal_intercept_x = (game_data->player.y - ray->horizontal_intercept_y) * \
		inverse_tangent + game_data->player.x;
		ray->horizontal_step_y = TILE_SIZE;
	}
	else if (ray->ray_angle == 0 || ray->ray_angle == M_PI)
	{
		ray->horizontal_intercept_y = game_data->player.y;
		ray->horizontal_intercept_x = game_data->player.x;
	}
	ray->horizontal_step_x = -ray->horizontal_step_y * inverse_tangent;
}