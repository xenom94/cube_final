

#include "../../includes/cub3d.h"

static void	check_border(t_data *data, char **map, int y)
{
	int	x;

	x = 0;
	while (x < data->map_width)
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
		{
			ft_exit(data, "Invalid Map1.", 1);
		}
		if (y == 0 && map[y][x] == ' ')
		{
			if (map[1][x] != ' ' && map[1][x] != '1')
				ft_exit(data, "Invalid Map2.", 1);
		}
		else if (y == data->map_height - 1 && map[y][x] == ' ')
		{
			if (map[y - 1][x] != ' ' && map[y - 1][x] != '1')
				ft_exit(data, "Invalid Map3.", 1);
		}
		x++;
	}
}

static void	check_arround_middle(t_data *data, int y, int x, char **map)
{
	if (x == 0 && map[y][x] == ' ')
	{
		if ((map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1'))
			ft_exit(data, "Invalid Map4.", 1);
	}
	else if (x == data->map_width - 1 && map[y][x] == ' ')
	{
		if (((map[y][x - 1] != ' ' && map[y][x - 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
			ft_exit (data, "Invalid Map5.", 1);
	}
	else if (map[y][x] == ' ')
	{
		if (((map[y][x - 1] != ' ' && map[y][x - 1] != '1') || \
		(map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
			ft_exit(data, "Invalid Map6.", 1);
	}
}

static void	check_middle(t_data *data, char **map, int y)
{
	int	x;

	x = 0;
	while (x < data->map_width)
	{
		if (x == 0 || x == data->map_width - 1)
		{
			// printf("y = |%s|\n", data->map[y]);
			if (map[y][x] != ' ' && map[y][x] != '1')
				ft_exit(data, "Invalid Map7.", 1);
		}
		check_arround_middle(data, y, x, map);
		x++;
	}
}

static void	check_characters(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < data -> map_height)
	{
		x = 0;
		while (x < data -> map_width)
		{
			if (!ft_strchr("NSEW01 ", map[y][x]))
				ft_exit(data, "Invalid Map8.", 1);
			x++;
		}
		y++;
	}
}

void	check_map(t_data *data)
{
	int	y;

	y = 0;
	check_characters(data, data->map);
	while (data->map[y])
	{
		
		if (y == 0 || y == data->map_height - 1)
		{
			check_border(data, data->map, y);
		}
		else
			check_middle(data, data->map, y);
		y++;
	}
	final_check(data, data->map);
}
