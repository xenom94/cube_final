/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:35:26 by sisser            #+#    #+#             */
/*   Updated: 2025/04/22 20:30:26 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../printf/ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include <stdbool.h>

# define WIN_NAME "Cub3d"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define TILE_SIZE 64
# define A_KEY 0
# define D_KEY 2
# define W_KEY 13
# define S_KEY 1
# define KEYDOWN 125
# define KEYUP 126
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 53
# define FOV 1.0471975512
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS WIN_WIDTH
# define PI 3.14159
//# define M_PI_2 3.14159 * 2

typedef struct s_wall_cordinate
{
	float	top;
	float	bottom;
}			t_wall_cordinate;

typedef struct s_ray
{
	float				ray_angle;
	int					offset_x;
	int					offset_y;
	float				wall_hit_x;
	float				wall_hit_y;
	float				distance;
	float				horizontal_step_y;
	float				horizontal_step_x;
	float				y_step_v;
	float				x_step_v;
	float				distance_to_wall;
	float				horizontal_intercept_y;
	float				horizontal_intercept_x;
	float				y_intercept_v;
	float				x_intercept_v;
	float				distance_to_projection_plane;
	float				wall_strip_height;
	bool				player_hit_horizontal_wall;
	bool				player_hit_vertical_wall;
	t_wall_cordinate	wall_cordinate;
}			t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	col_x;
	float	col_y;
	float	dx;
	float	dy;
	float	angle;
	int		walk_direction;
	int		turn_direction;
	int		strafe_direction;
	float	rotationdirection;
	float	move_speed;
	float	rotation_speed;
	int		to_do;
	t_ray	*rays;
}			t_player;

typedef struct s_get_color
{
	size_t	start;
	char	*temp[3];
	size_t	len;
	int		ret;
}			t_get_color;

typedef struct s_color
{
	int	floor_color;
	int	ceiling_color;
}			t_color;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_texture
{
	int		height;
	int		width;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	t_image	image[4];
}			t_texture;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

typedef struct s_data
{
	char		*path;
	char		**map;
	int			map_height;
	int			map_width;
	int			f_counter;
	int			c_counter;
	int			no_counter;
	int			we_counter;
	int			so_counter;
	int			ea_counter;
	int			map_counter;
	t_texture	textures;
	t_color		colors;
	t_player	player;
	t_mlx		*mlx;
}			t_data;

typedef struct s_coordinate
{
	int	x;
	int	y;
}			t_cordinate;

void	init_game(t_data *data, int ac, char **av);
void		check_map(t_data *game_data);
size_t	get_map_height_1(char **map);
size_t	get_map_width_1(char **map);
int		get_player(char **map, t_player *player);
int		skip_spaces(char *line, int i);
int		line_value_size(char *line, int i);
char	*get_line_value(int prefix_len, char *line);
char	*extract_texture(char *line, t_data *game_data);
int		find_chr(char *str, char c);
void	*extract_color(char *line, t_data *game_data);
void	*free_game_data(t_data *game_data);
void	free_rgb(char *rgb_line, char **rgb);
char	*parse_file_map(char *file_path, t_data *game_data);
t_data	*setup_game(char *file_path);
int		extract_map_data(int map_fd, char **line, t_data *game_data);
int		check_map_extension(char *file_path);
char	*parse_file_map(char *file_path, t_data *game_data);
int		get_map_height(char *line);
int		get_map_width(char *line);
char	**alloc_map(char *map_line);
char	**parse_map_line(char *map_line);
char	*decimal_to_hexadecimal(int decimal);
int		check_rgb_string_format(char *rgb_string);
char	**rgb_string_to_array(char *rgb);
char	*rgb_to_hex(char *rgb);
size_t	ft_strlcpy2(char *dst, const char *src, size_t size);
int		ft_is_only(char *line, char c);
char	*ft_strappend(char **dest, char const *str);
int		ft_isempty(char *line);
int		ft_str_contains(char *str, char c);
int		check_map_line(char *line);
int		map_content_valid(char *line);
int		valid_data(t_data *game_data);
char	*get_map_content(int map_fd, char **line, t_data *game_data);
int		check_wall_collision(t_data *game_data, float pos_x, float pos_y);
void	update_player_position(t_data *game_data);
void	draw_wall_segment(t_data *game_data, int column, int row);
void	render_scene(t_data *game_data);
int		render_2d_map(t_data *game_data);
void	cast_all_rays(t_data *game_data);
int		handle_key_pressed(int keycode, t_data *game_data);
int		handle_key_released(int keycode, t_data *game_data);
t_mlx	*mlx_initializer(void);
void	initialize_player(t_data *game_data);
void	put_pixel_to_image(t_mlx *mlx_data, int pixel_x, int pixel_y, int pixel_color);
int		get_texture_color(int texture_x, int texture_y, t_data *game_data, int texture_index);
void	cast_single_ray(t_ray *ray, t_data *game_data);
void	calculate_horizontal_intersection(t_ray *ray, t_data *game_data);
void	check_horizontal_walls(t_ray *ray, t_data *game_data);
void	calculate_vertical_intersection(t_ray *ray, t_data *game_data);
void	check_vertical_walls(t_ray *ray, t_data *game_data);
void	calcule_wall_coordinates(t_data *game_data, int ray_index);
void	compute_ray_parameters(t_data *game_data);
double	distance_between_points(double x1, double y1, double x2, double y2);
void	compute_wall_distance(t_ray *ray, t_data *game_data);
int		exit_game(t_data *game_data);
void	ft_exit(t_data *data, const char *str, int code);
void	final_check(t_data *data, char **map);
void	check_plus(t_data *data);
void	check_nbr(t_get_color *c, int *i);
int		is_only_digits(char *str);
void	free_ptr(char **str);
void	get_data(t_data *data);
int	get_map(t_data *data, char *line);
void	free_mat(char ***mat);
void	get_format(char ***map, size_t height, size_t width);
void	get_player_info(t_data *data);
t_image	init_texture(t_data *data, int flag);
void	my_mlx_pixel_put(t_mlx *mlx_data, int pixel_x, int pixel_y, int pixel_color);
float	angles_normalizer(float angle);
int	choose_texture(t_ray *ray, float ra);

#endif