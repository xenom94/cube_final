

#include "../../includes/cub3d.h"

int	is_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_plus(t_data *data)
{

	if (data->c_counter != 1 || data->f_counter != 1 || data->ea_counter != 1
		|| data->so_counter != 1 || data->no_counter != 1 || data->we_counter != 1)
		ft_exit(data, "Something missing", 1);
}

void	check_nbr(t_get_color *c, int *i)
{
	if (!c->temp[0] || !c->temp[1] || !c->temp[2])
		*i = -1;
	if (ft_isempty(c->temp[0]) == 1 || ft_isempty(c->temp[1]) == 1
		|| ft_isempty(c->temp[2]) == 1)
		*i = -1;
	if (is_only_digits(c->temp[0]) == 1 || is_only_digits(c->temp[1]) == 1
		|| is_only_digits(c->temp[2]) == 1)
		*i = -1;
	if (ft_strlen(c->temp[0]) >= 4 || ft_strlen(c->temp[1]) >= 4
		|| ft_strlen(c->temp[2]) >= 4)
		*i = -1;
	if (!(ft_atoi(c->temp[0]) >= 0 && ft_atoi(c->temp[0]) <= 255)
		|| !(ft_atoi(c->temp[1]) >= 0 && ft_atoi(c->temp[1]) <= 255)
		|| !(ft_atoi(c->temp[2]) >= 0 && ft_atoi(c->temp[2]) <= 255))
			*i = -1;
}
