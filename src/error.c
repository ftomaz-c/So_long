/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:00:03 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/10 17:28:34 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_errors(int argc, char **argv, t_data *data)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: no map detected\n", STDERR_FILENO);
		ft_putstr_fd("Usage: ./so_long 'map'.ber\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (!extension_check(argv[1], ".ber"))
	{
		ft_putstr_fd("File '", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd("' must be '.ber' format\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	else if (!read_map(argv[1], data))
	{
		ft_putstr_fd("Error: File does not exist\n", STDERR_FILENO);
		ft_putstr_fd("Usage: ./so_long 'map'.ber\n", STDERR_FILENO);
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
}
