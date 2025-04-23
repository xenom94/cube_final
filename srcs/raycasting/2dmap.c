#include "../../includes/cub3d.h"

int	check_wall_collision(t_data *game_data, float pos_x, float pos_y)
{
	int	grid_x;
	int	grid_y;

	if (pos_x < 0 || pos_x > game_data->map_width * TILE_SIZE
		|| pos_y < 0 || pos_y > game_data->map_height * TILE_SIZE)
		return (1);
	grid_x = pos_x / TILE_SIZE;
	grid_y = pos_y / TILE_SIZE;
	if (game_data->map[grid_y] && game_data->map[grid_y] + grid_x)
		if (ft_strncmp(game_data->map[grid_y] + grid_x, "1", 1))
			return (0);
	return (1);
}

void	update_player_position(t_data *game_data)
{
	float	move_step;
	float	next_x;
	float	next_y;
	float	side_step;

	move_step = game_data->player.walk_direction * game_data->player.move_speed;
	game_data->player.angle += game_data->player.turn_direction * game_data->player.rotation_speed;
	game_data->player.angle = angles_normalizer(game_data->player.angle);
	side_step = game_data->player.strafe_direction * game_data->player.move_speed;
	next_x = game_data->player.x + cos(game_data->player.angle) * move_step;
	next_y = game_data->player.y + sin(game_data->player.angle) * move_step;
	next_x += cos(game_data->player.angle + PI_2) * side_step;
	next_y += sin(game_data->player.angle + PI_2) * side_step;
	if (!check_wall_collision(game_data, next_x, next_y)
		&& !check_wall_collision(game_data, next_x + 2, next_y + 2)
		&& !check_wall_collision(game_data, next_x - 2, next_y - 2)
		&& !check_wall_collision(game_data, next_x - 2, next_y + 2)
		&& !check_wall_collision(game_data, next_x + 2, next_y - 2))
	{
		game_data->player.x = next_x;
		game_data->player.y = next_y;
	}
}

void	draw_wall_segment(t_data *game_data, int column, int row)
{
	int	wall_color;
	int	top_offset;
	int	texture_choice;

	top_offset = row + (game_data->player.rays[column].wall_strip_height / 2) \
	- (WIN_HEIGHT / 2);
	game_data->player.rays[column].offset_y = top_offset * \
	((double)game_data->textures.height / game_data->player.rays[column].wall_strip_height);
	texture_choice = choose_texture(&game_data->player.rays[column], \
	game_data->player.rays[column].ray_angle);
	wall_color = get_texture_color(game_data->player.rays[column].offset_x \
	, game_data->player.rays[column].offset_y, game_data, texture_choice);
	my_mlx_pixel_put(game_data->mlx, column, row, wall_color);
}

void	render_scene(t_data *game_data)
{
	int	column;
	int	row;

	column = 0;
	while (column < WIN_WIDTH)
	{
		row = 0;
		while (row < WIN_HEIGHT)
		{
			if (row >= game_data->player.rays[column].wall_cordinate.top && row <= \
			game_data->player.rays[column].wall_cordinate.bottom)
				draw_wall_segment(game_data, column, row);
			else if (row < game_data->player.rays[column].wall_cordinate.bottom)
				my_mlx_pixel_put(game_data->mlx, column, row, game_data->colors.ceiling_color);
			else
				my_mlx_pixel_put(game_data->mlx, column, row, game_data->colors.floor_color);
			row++;
		}
		column++;
	}
	free(game_data->player.rays);
}

int	render_2d_map(t_data *game_data)
{
	game_data->mlx->img = mlx_new_image(game_data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game_data->mlx->addr = mlx_get_data_addr(game_data->mlx->img, \
	&game_data->mlx->bits_per_pixel, &game_data->mlx->line_length, &game_data->mlx->endian);
	update_player_position(game_data);
	cast_all_rays(game_data);
	rays_parameters(game_data);
	render_scene(game_data);
	mlx_put_image_to_window(game_data->mlx->mlx_ptr, game_data->mlx->win, \
	game_data->mlx->img, 0, 0);
	mlx_destroy_image(game_data->mlx->mlx_ptr, game_data->mlx->img);
	return (1);
}