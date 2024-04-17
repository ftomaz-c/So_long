/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:58:35 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/17 13:06:31 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	oversized_display(t_data *data, void *img, double x, double y)
{
	int	width;
	int	height;

	width = (data->screen_width - (data->map_width * PIXEL_SIZE)) / 2;
	height = (data->screen_height - (data->map_height * PIXEL_SIZE)) / 2;
	if (data->map_width * PIXEL_SIZE > data->screen_width)
	{
		width = (data->hero.x_position * PIXEL_SIZE)
			- (data->screen_width / 2);
		width = fmax(0, fmin(width, data->map_width
					* PIXEL_SIZE - data->screen_width));
		width *= -1;
	}
	if (data->map_height * PIXEL_SIZE > data->screen_height)
	{
		height = (data->hero.y_position * PIXEL_SIZE)
			- (data->screen_height / 2);
		height = fmax(0, fmin(height, data->map_height
					* PIXEL_SIZE - data->screen_height));
		height *= -1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
		(x * PIXEL_SIZE) + width, (y * PIXEL_SIZE) + height);
}

void	ft_put_img_to_window(t_data *data, void *img, double x, double y)
{
	if (data->map_width * PIXEL_SIZE > data->screen_width
		|| data->map_height * PIXEL_SIZE > data->screen_height)
		oversized_display(data, img, x, y);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
			x * PIXEL_SIZE,
			y * PIXEL_SIZE);
}
