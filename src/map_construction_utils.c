/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:56:45 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/17 14:33:54 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_exit_failure(t_data *data)
{
	print_map(data);
	free_map(data->map);
	exit (EXIT_FAILURE);
}

void	add_hero(t_data *data)
{
	data->player++;
	get_position(data, &(data->hero.x_position), &(data->hero.y_position), 'P');
}

void	add_collectibles(t_data *data, int x, int y)
{
	if (data->collectibles.num_c == 0)
	{
		data->collectibles.c_position[data->collectibles.num_c].type = 'K';
		data->collectibles.c_position[data->collectibles.num_c].x = x;
		data->collectibles.c_position[data->collectibles.num_c].y = y;
	}
	else if (data->collectibles.num_c == 1)
	{
		data->collectibles.c_position[data->collectibles.num_c].type = 'H';
		data->collectibles.c_position[data->collectibles.num_c].x = x;
		data->collectibles.c_position[data->collectibles.num_c].y = y;
	}
	else
	{
		data->collectibles.c_position[data->collectibles.num_c].type = 'C';
		data->collectibles.c_position[data->collectibles.num_c].x = x;
		data->collectibles.c_position[data->collectibles.num_c].y = y;
	}
	data->collectibles.num_c++;
}

int	ft_valid(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		return (0);
	return (1);
}
