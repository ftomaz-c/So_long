/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:44:43 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/16 11:30:14 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_printf("%c", data->map[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("\n");
}

void	print_info(t_data *data)
{
	printf("prev_x_position: %c\n",
		data->map[data->hero.y_position][data->hero.x_position - 1]);
	printf("prev_y_position: %c\n",
		data->map[data->hero.y_position - 1][data->hero.x_position]);
	printf("next_x_position: %c\n",
		data->map[data->hero.y_position][data->hero.x_position + 1]);
	printf("next_y_position: %c\n",
		data->map[data->hero.y_position + 1][data->hero.x_position]);
	print_map(data);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
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
