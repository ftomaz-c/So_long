/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:25:26 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/19 12:04:07 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_hero_to_right(t_data *data)
{
	char	*next;
	t_hero	*hero;

	next = &(data->map[data->hero.y_position][data->hero.x_position + 1]);
	hero = &(data->hero);
	data->map[hero->y_position][hero->x_position] = '0';
	data->hero.self = data->hero.hero_right[0];
	spawn_map(data);
	if (*next != '1')
	{
		if (*next == 'E')
		{
			if (hero->collectibles == data->collectibles.num_c)
				open_door(data);
		}
		else
		{
			if (*next == 'C')
				hero->collectibles++;
			hero->x_position++;
			hero->move_num++;
			data->map[hero->y_position][hero->x_position] = 'P';
		}
		spawn_map(data);
	}
}

void	move_hero_to_left(t_data *data)
{
	char	*next;
	t_hero	*hero;

	hero = &(data->hero);
	data->map[hero->y_position][hero->x_position] = '0';
	next = &(data->map[data->hero.y_position][data->hero.x_position - 1]);
	data->hero.self = data->hero.hero_left[0];
	spawn_map(data);
	if (*next != '1')
	{
		if (*next == 'E')
		{
			if (hero->collectibles == data->collectibles.num_c)
				open_door(data);
		}
		else
		{
			if (*next == 'C')
				hero->collectibles++;
			hero->x_position--;
			hero->move_num++;
			data->map[hero->y_position][hero->x_position] = 'P';
		}
		spawn_map(data);
	}
}

void	move_hero_up(t_data *data)
{
	char	*next;
	t_hero	*hero;

	hero = &(data->hero);
	data->map[hero->y_position][hero->x_position] = '0';
	next = &(data->map[data->hero.y_position - 1][data->hero.x_position]);
	hero->self = hero->hero_back;
	spawn_map(data);
	if (*next != '1')
	{
		if (*next == 'E')
		{
			if (hero->collectibles == data->collectibles.num_c)
				open_door(data);
		}
		else
		{
			if (*next == 'C')
				hero->collectibles++;
			hero->y_position--;
			hero->move_num++;
			data->map[hero->y_position][hero->x_position] = 'P';
		}
		spawn_map(data);
	}
}

void	move_hero_down(t_data *data)
{
	char	*next;
	t_hero	*hero;

	hero = &(data->hero);
	data->map[hero->y_position][hero->x_position] = '0';
	next = &(data->map[data->hero.y_position + 1][data->hero.x_position]);
	data->hero.self = data->hero.hero_front;
	spawn_map(data);
	if (*next != '1')
	{
		if (*next == 'E')
		{
			if (hero->collectibles == data->collectibles.num_c)
				open_door(data);
		}
		else
		{
			if (*next == 'C')
				hero->collectibles++;
			hero->y_position++;
			hero->move_num++;
			data->map[hero->y_position][hero->x_position] = 'P';
		}
		spawn_map(data);
	}
}
