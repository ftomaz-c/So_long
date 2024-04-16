/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:48:38 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/16 11:21:56 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_construct(t_data *data)
{
	if (!check_if_retangular(data))
	{
		ft_putstr_fd("Error: Not a Valid Map\n\n", STDERR_FILENO);
		ft_putstr_fd("The map must be rectangular\n", STDERR_FILENO);
		print_map(data);
		free_map(data->map);
		exit (EXIT_FAILURE);
	}
	else if (!find_walls(data))
	{
		ft_putstr_fd("Error: Not a Valid Map\n\n", STDERR_FILENO);
		ft_putstr_fd("The map must be closed/surrounded by walls: '1'\n",
			STDERR_FILENO);
		print_map(data);
		free_map(data->map);
		exit (EXIT_FAILURE);
	}
	else if (!check_pec(data))
	{
		ft_putstr_fd("Error: Not a Valid Map\n\n", STDERR_FILENO);
		ft_putstr_fd("The map must contain 1 exit 'E'\n", STDERR_FILENO);
		ft_putstr_fd("At least 1 collectible 'C'\n", STDERR_FILENO);
		ft_putstr_fd("And 1 starting position 'P' to be valid\n",
			STDERR_FILENO);
		print_map(data);
		free_map(data->map);
		exit (EXIT_FAILURE);
	}
}

int	find_walls(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	x = 0;
	while (x < data->map_width)
	{
		if (map[0][x] != '1' || map[data->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < (data->map_height - 1))
	{
		if (map[y][0] != '1' || map[y][data->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_if_retangular(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y])
	{
		if (data->map_width != ft_strlen_nl(data->map[y]))
			return (0);
		y++;
	}
	return (1);
}

int	check_pec(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->collectibles.num_c = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (!ft_valid(data->map[y][x]))
				return (0);
			if (data->map[y][x] == 'P')
				add_hero(data);
			if (data->map[y][x] == 'E')
				data->nbr_e++;
			if (data->map[y][x] == 'C')
				add_collectibles(data, x, y);
			x++;
		}
		y++;
	}
	if (data->player != 1 || data->nbr_e != 1 || data->collectibles.num_c == 0)
		return (0);
	return (1);
}
