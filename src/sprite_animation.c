/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:38:33 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/17 12:08:56 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	heart_eng(t_data *data)
{
	static unsigned int	i = 0;

	if (i == 0)
		i = timer();
	if (timer() - i < 100)
		return (0);
	i = timer();
	if (data->collectibles.heart.frame == 7)
		data->collectibles.heart.frame = 0;
	else
		data->collectibles.heart.frame++;
	data->collectibles.heart.heart[7]->img
		= data->collectibles.heart.heart[data->collectibles.heart.frame]->img;
	spawn_map(data);
	return (0);
}

int	coin_eng(t_data *data)
{
	static unsigned int	i = 0;

	if (i == 0)
		i = timer();
	if (timer() - i < 90)
		return (0);
	i = timer();
	if (data->collectibles.coin.frame == 8)
		data->collectibles.coin.frame = 0;
	else
		data->collectibles.coin.frame++;
	data->collectibles.coin.coin[9]->img
		= data->collectibles.coin.coin[data->collectibles.coin.frame]->img;
	spawn_map(data);
	return (0);
}

int	hero_eng(t_data *data)
{
	static unsigned int	i = 0;
	t_hero				*hero;

	hero = &(data->hero);
	if (i == 0)
		i = timer();
	if (timer() - i < 200)
		return (0);
	i = timer();
	if (hero->move_frame == 3)
		hero->move_frame = 0;
	else
		hero->move_frame++;
	check_hero_addr(data, hero);
	spawn_map(data);
	return (0);
}

void	open_door(t_data *data)
{
	int		i;
	t_door	*door;

	door = &(data->tiles.door);
	i = 0;
	while (i < 4)
	{
		ft_put_img_to_window(data, door->door[i]->img, door->x_position,
			door->y_position);
		mlx_do_sync(data->mlx_ptr);
		usleep(300000);
		i++;
	}
	close_program(data);
}

int	sprites_animation(t_data *data)
{
	heart_eng(data);
	coin_eng(data);
	hero_eng(data);
	return (0);
}
