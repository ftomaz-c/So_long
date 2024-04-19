/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:43:50 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/19 13:00:31 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_program(t_data *data)
{
	free_assets(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map);
	exit(EXIT_SUCCESS);
}

int	deal_hero_key(int key, t_data *data)
{
	if (key == XK_d || key == XK_D || key == XK_Right)
		move_hero_to_right(data);
	else if (key == XK_a || key == XK_A || key == XK_Left)
		move_hero_to_left(data);
	else if (key == XK_w || key == XK_W || key == XK_Up)
		move_hero_up(data);
	else if (key == XK_s || key == XK_S || key == XK_Down)
		move_hero_down(data);
	if (key == XK_Escape)
		close_program(data);
	return (key);
}
