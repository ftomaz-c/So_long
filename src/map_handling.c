/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:58:31 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/18 21:09:23 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	invalid_map(t_data *data, char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (data->map)
		free_map(data->map);
	close (fd);
	ft_putstr_fd("Error: invalid map\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	count_width_height(char *file_name, t_data *data)
{
	int		fd;
	char	*line;

	data->map_height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		invalid_map(data, line, fd);
	data->map_width = ft_strlen_nl(line);
	while (line != 0)
	{
		data->map_height++;
		free(line);
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			invalid_map(data, line, fd);
	}
	free(line);
	close (fd);
	return (1);
}

int	alloc_mem_map(char *file_name, t_data *data)
{
	if (!count_width_height(file_name, data))
		return (0);
	data->map = ft_calloc(sizeof(char *), data->map_height + 1);
	if (!data->map)
	{
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	read_map(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
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
		data->map[y] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	return (1);
}

void	check_map(t_data *data)
{
	data->exit = 1;
	check_map_construct(data);
	check_map_validity(data);
}
