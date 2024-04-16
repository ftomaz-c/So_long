/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:54:09 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/16 11:33:05 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_validity(t_data *data)
{
	int		y;
	char	**new_map;

	data->nbr_c = data->collectibles.num_c;
	new_map = (char **)ft_calloc(sizeof(char *), data->map_height + 1);
	if (!new_map)
		return ;
	y = 0;
	while (y < data->map_height)
	{
		new_map[y] = ft_strdup(data->map[y]);
		y++;
	}
	new_map[y] = NULL;
	ft_flood_fill(data, data->hero.x_position, data->hero.y_position, new_map);
	if (data->nbr_c != 0 || data->exit != 0)
	{
		ft_putstr_fd("Error: Not a Valid Map\n\n", STDERR_FILENO);
		print_map(data);
		ft_putstr_fd("The map must have a valid path\n", STDERR_FILENO);
		free_map(new_map);
		exit (EXIT_FAILURE);
	}
	free_map(new_map);
}

void	ft_flood_fill(t_data *data, int x, int y, char **map)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'B')
		return ;
	else if (map[y][x] == 'C')
		data->nbr_c--;
	else if (map[y][x] == 'E')
	{
		data->exit = 0;
		return ;
	}
	map[y][x] = 'F';
	ft_flood_fill(data, x + 1, y, map);
	ft_flood_fill(data, x - 1, y, map);
	ft_flood_fill(data, x, y + 1, map);
	ft_flood_fill(data, x, y - 1, map);
}
