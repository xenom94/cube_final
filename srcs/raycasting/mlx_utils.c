#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx_data, int pixel_x, int pixel_y, int pixel_color)
{
	char	*destination;

	if (pixel_x < 0 || pixel_x >= WIN_WIDTH || pixel_y < 0 || pixel_y >= WIN_HEIGHT)
		return ;
	destination = mlx_data->addr + (pixel_y * mlx_data->line_length + pixel_x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)destination = pixel_color;
}

int	get_texture_color(int texture_x, int texture_y, t_data *game_data, int texture_index)
{
	int	offset;
	int	texture_color;

	if (texture_x < 0 || texture_y < 0 || texture_x > game_data->textures.width || texture_y > game_data->textures.height)
		return (0);
	offset = (texture_y * game_data->textures.height + texture_x) * \
	(game_data->textures.image[texture_index].bits_per_pixel / 8);
	if (offset >= 0 && offset < game_data->textures.width * game_data->textures.height
		* (game_data->textures.image[texture_index].bits_per_pixel / 8))
		texture_color = *(int *)(game_data->textures.image[texture_index].addr + offset);
	else
		texture_color = 0x000000;
	return (texture_color);
}

int	exit_game(t_data *game_data)
{
	mlx_destroy_window(game_data->mlx->mlx_ptr, game_data->mlx->win);
	exit(0);
	return (0);
}

float	angles_normalizer(float angle)
{
	double	result;

	result = fmod((double)angle, 2 * PI);
	if (result < 0)
		result += 2 * PI;
	return ((float)result);
}

int	choose_texture(t_ray *ray, float ra)
{
	if (ray->player_hit_vertical_wall)
	{
		if (ra > 0 && ra < PI)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ra > 0.5 * PI && ra < 1.5 * PI)
			return (2);
		else
			return (3);
	}
}
