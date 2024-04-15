/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:43:50 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/15 15:53:27 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
