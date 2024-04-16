/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:01:00 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/15 17:15:55 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_image(t_data *data, t_img **image)
{
	if (*image != NULL)
	{
		if ((*image)->img != NULL)
		{
			mlx_destroy_image(data->mlx_ptr, (*image)->img);
			(*image)->img = NULL;
		}
		free(*image);
		*image = NULL;
	}
}

void	free_images(t_data *data)
{
	int	i;

	i = 0;
	printf("heart_frames: %i\n", data->collectibles.heart.frame);
	printf("coin_frames: %i\n", data->collectibles.coin.frame);
	while (data->collectibles.heart.heart[i])
	{
		free_image(data, &data->collectibles.heart.heart[i]);
		i++;
	}
	i = 0;
	while (data->collectibles.coin.coin[i])
	{
		free_image(data, &data->collectibles.coin.coin[i]);
		i++;
	}
}

int	close_program(t_data *data)
{
	free_images(data);
	free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
