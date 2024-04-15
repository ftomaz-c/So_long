/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:58:31 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/15 13:00:25 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_width_height(char *file_name, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	data->map_width = ft_strlen(line);
	free(line);
	data->map_height = 1;
	line = get_next_line(fd);
	while (line != 0)
	{
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (1);
}

int	alloc_mem_map(char *file_name, t_data *data)
{
	int		i;

	if (!count_width_height(file_name, data))
		return (0);
	data->map = ft_calloc(sizeof(char *), data->map_height + 1);
	if (!data->map)
	{
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < data->map_height)
	{
		data->map[i] = ft_calloc(sizeof(char), data->map_width + 1);
		if (!data->map[i])
		{
			free_map(data->map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

int	read_map(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	if (!alloc_mem_map(file_name, data))
		return (0);
	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line != 0)
	{
		x = -1;
		while (line[++x])
			data->map[y][x] = line[x];
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	return (1);
}

void	check_map(t_data *data)
{
	check_map_construct(data);
	check_map_validity(data);
}
