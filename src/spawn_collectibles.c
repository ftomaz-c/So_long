/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:54:09 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/15 15:54:46 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	collectible_type(t_c_position *c, int x, int y, char type)
{
	if (c->x == x && c->y == y && c->type == type)
		return (1);
	return (0);
}

void	spawn_collectibles(t_data *data, int x, int y)
{
	t_collectibles	*collectibles;
	int				i;

	i = 0;
	collectibles = &(data->collectibles);
	while (i < MAX_COLLECTIBLES)
	{
		if (collectible_type(&(collectibles->c_position[i]), x, y, 'K'))
			ft_put_img_to_window(data, data->collectibles.key.key->img, x, y);
		else if (collectible_type(&(collectibles->c_position[i]), x, y, 'H'))
			ft_put_img_to_window(data, data->collectibles.heart.heart[7]->img,
				x, y);
		else if (collectible_type(&(collectibles->c_position[i]), x, y, 'C'))
			ft_put_img_to_window(data, data->collectibles.coin.coin[9]->img,
				x, y);
		i++;
	}
}
