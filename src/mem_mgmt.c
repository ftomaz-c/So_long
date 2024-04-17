/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:01:00 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/17 11:50:14 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_image(t_data *data, t_img **image)
{
	if (*image)
	{
		if ((*image)->img)
			mlx_destroy_image(data->mlx_ptr, (*image)->img);
		free(*image);
		*image = NULL;
	}
}

void	free_tiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
		free_image(data, &data->tiles.door.door[i++]);
	free_image(data, &data->tiles.bottom);
	free_image(data, &data->tiles.bottom_left);
	free_image(data, &data->tiles.bottom_right);
	free_image(data, &data->tiles.center);
	free_image(data, &data->tiles.left);
	free_image(data, &data->tiles.middle);
	free_image(data, &data->tiles.right);
	free_image(data, &data->tiles.top);
	free_image(data, &data->tiles.top_left);
	free_image(data, &data->tiles.top_right);
}

void	free_collectibles(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
		free_image(data, &data->collectibles.heart.heart[i++]);
	i = 0;
	while (i < 9)
		free_image(data, &data->collectibles.coin.coin[i++]);
	free_image(data, &data->collectibles.key.key);
}

void	free_hero(t_data *data)
{
	int	i;
	
	free_image(data, &data->hero.hero_back);
	free_image(data, &data->hero.hero_front);
	i = 0;
	while (i < 4)
	{
		free_image(data, &data->hero.hero_left[i]);
		free_image(data, &data->hero.hero_right[i]);
		i++;
	}
}

void	free_assets(t_data *data)
{
	free_collectibles(data);
	free_hero(data);
	free_tiles(data);
}
