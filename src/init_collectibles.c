/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:31:27 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/19 11:45:29 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	data->collectibles.heart.heart[1] = ft_make_img(HEART_2, data);
	data->collectibles.heart.heart[2] = ft_make_img(HEART_3, data);
	data->collectibles.heart.heart[3] = ft_make_img(HEART_4, data);
	data->collectibles.heart.heart[4] = ft_make_img(HEART_5, data);
	data->collectibles.heart.heart[5] = ft_make_img(HEART_6, data);
	data->collectibles.heart.heart[6] = ft_make_img(HEART_7, data);
	data->collectibles.heart.heart[7] = data->collectibles.heart.heart[0];*/

void	init_heart(t_data *data)
{
	data->collectibles.heart.heart[0] = ft_make_img(HEART_1, data);
	data->collectibles.heart.frame = 0;
}

/*	data->collectibles.coin.coin[1] = ft_make_img(COIN_2, data);
	data->collectibles.coin.coin[2] = ft_make_img(COIN_3, data);
	data->collectibles.coin.coin[3] = ft_make_img(COIN_4, data);
	data->collectibles.coin.coin[4] = ft_make_img(COIN_5, data);
	data->collectibles.coin.coin[5] = ft_make_img(COIN_6, data);
	data->collectibles.coin.coin[6] = ft_make_img(COIN_7, data);
	data->collectibles.coin.coin[7] = ft_make_img(COIN_8, data);
	data->collectibles.coin.coin[8] = ft_make_img(COIN_9, data);
	data->collectibles.coin.coin[9] = data->collectibles.coin.coin[0];*/

void	init_coin(t_data *data)
{
	data->collectibles.coin.coin[0] = ft_make_img(COIN_1, data);
	data->collectibles.coin.frame = 0;
}

void	init_key(t_data *data)
{
	t_key	*key;

	key = &(data->collectibles.key);
	key->key = ft_make_img(KEY, data);
}

void	init_collectibles(t_data *data)
{
	init_heart(data);
	init_coin(data);
	init_key(data);
}
