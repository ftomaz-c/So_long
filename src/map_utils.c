/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:44:43 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/18 21:00:13 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	map = NULL;
}

void	print_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y])
	{
		ft_printf("%s", data->map[y]);
		y++;
	}
	ft_printf("\n");
}

void	print_info(t_data *data)
{
	ft_printf("prev_x_position: %c\n",
		data->map[data->hero.y_position][data->hero.x_position - 1]);
	ft_printf("prev_y_position: %c\n",
		data->map[data->hero.y_position - 1][data->hero.x_position]);
	ft_printf("next_x_position: %c\n",
		data->map[data->hero.y_position][data->hero.x_position + 1]);
	ft_printf("next_y_position: %c\n",
		data->map[data->hero.y_position + 1][data->hero.x_position]);
	print_map(data);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	get_position(t_data *data, int *x_pos, int *y_pos, char map_char)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == map_char)
			{
				*x_pos = x;
				*y_pos = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
