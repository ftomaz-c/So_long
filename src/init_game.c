/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:31:27 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/18 21:10:40 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_hero(t_data *data)
{
	t_hero	*hero;

	hero = &(data->hero);
	hero->collectibles = 0;
	hero->hero_back = ft_make_img(HERO_BACK, data);
	hero->hero_front = ft_make_img(HERO_FRONT, data);
	hero->hero_left[0] = ft_make_img(HERO_LEFT_1, data);
	hero->hero_left[1] = ft_make_img(HERO_LEFT_2, data);
	hero->hero_left[2] = ft_make_img(HERO_LEFT_3, data);
	hero->hero_left[3] = ft_make_img(HERO_LEFT_4, data);
	hero->hero_right[0] = ft_make_img(HERO_RIGHT_1, data);
	hero->hero_right[1] = ft_make_img(HERO_RIGHT_2, data);
	hero->hero_right[2] = ft_make_img(HERO_RIGHT_3, data);
	hero->hero_right[3] = ft_make_img(HERO_RIGHT_4, data);
	hero->move_frame = 0;
	hero->move_num = 0;
	hero->self = hero->hero_front;
}

void	init_door(t_data *data)
{
	t_door	*door;

	door = &(data->tiles.door);
	door->door[0] = ft_make_img(DOOR_1, data);
	door->door[1] = ft_make_img(DOOR_2, data);
	door->door[2] = ft_make_img(DOOR_3, data);
	door->door[3] = ft_make_img(DOOR_4, data);
	get_position(data, &(door->x_position), &(door->y_position), 'E');
}

void	init_map(t_data *data)
{
	data->tiles.top_left = ft_make_img(TOP_LEFT, data);
	data->tiles.top_right = ft_make_img (TOP_RIGHT, data);
	data->tiles.top = ft_make_img(TOP, data);
	data->tiles.left = ft_make_img(LEFT, data);
	data->tiles.right = ft_make_img(RIGHT, data);
	data->tiles.bottom_left = ft_make_img(BOTTOM_LEFT, data);
	data->tiles.bottom_right = ft_make_img(BOTTOM_RIGHT, data);
	data->tiles.bottom = ft_make_img(BOTTOM, data);
	data->tiles.center = ft_make_img(CENTER, data);
	data->tiles.middle = ft_make_img(MIDDLE, data);
}

void	loading_imgs(t_data *data)
{
	init_hero(data);
	init_door(data);
	init_map(data);
	init_collectibles(data);
}

void	game_init(t_data *data)
{
	display_size(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_width,
			data->screen_height, "so_long");
	if (!data->win_ptr)
		return ;
	loading_imgs(data);
	spawn_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &deal_hero_key, data);
	mlx_hook(data->win_ptr, 17, 0, &close_program, data);
	mlx_loop(data->mlx_ptr);
}
//mlx_loop_hook(data->mlx_ptr, &sprites_animation, data);
