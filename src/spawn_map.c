/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:46:41 by marvin            #+#    #+#             */
/*   Updated: 2024/01/15 18:46:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_top_outline(t_data *data, int x, int y)
{
	if (x == 0)
		ft_put_img_to_window(data, data->tiles.top_left->img, x, y);
	else if (x == data->map_width - 1)
		ft_put_img_to_window(data, data->tiles.top_right->img, x, y);
	else
		ft_put_img_to_window(data, data->tiles.top->img, x, y);
}

void	draw_bottom_outline(t_data *data, int x, int y)
{
	if (x == 0)
		ft_put_img_to_window(data, data->tiles.bottom_left->img, x, y);
	else if (x == data->map_width - 1)
		ft_put_img_to_window(data, data->tiles.bottom_right->img, x, y);
	else
		ft_put_img_to_window(data, data->tiles.bottom->img, x, y);
}

void	draw_outline(t_data *data, int x, int y)
{
	if (y == 0)
		draw_top_outline(data, x, y);
	else if (y == data->map_height - 1)
		draw_bottom_outline(data, x, y);
	else
	{
		if (x == 0)
			ft_put_img_to_window(data, data->tiles.left->img, x, y);
		else if (x == data->map_width - 1)
			ft_put_img_to_window(data, data->tiles.right->img, x, y);
		else
			ft_put_img_to_window(data, data->tiles.middle->img, x, y);
	}
}

void	put_img(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		draw_outline(data, x, y);
	else if (data->map[y][x] == 'C')
		spawn_collectibles(data, x, y);
	else if (data->map[y][x] == 'E')
		ft_put_img_to_window(data, data->tiles.door.door[0]->img, x, y);
	else if (data->map[y][x] == '0')
		ft_put_img_to_window(data, data->tiles.center->img, x, y);
	ft_put_img_to_window(data, data->hero.self->img, data->hero.x_position
		+ data->hero.x_frame, data->hero.y_position + data->hero.y_frame);
}

void	spawn_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->nbr_c = 0;
	while (y < data->map_height && data->is_running)
	{
		x = 0;
		while (x < data->map_width && data->is_running)
		{
			put_img(data, x, y);
			x++;
		}
		y++;
	}
}
