/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:58:35 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/15 15:52:56 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*ft_make_img(char *path, t_data *data)
{
	t_img	*image;
	int		width;
	int		height;

	image = malloc(sizeof(t_img));
	if (!image)
		return (0);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel), \
				&(image->line_lenght), &(image->endian));
	return (image);
}

void	ft_put_img_to_window(t_data *data, void *img, double x, double y)
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

unsigned int	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	check_hero_addr(t_data *data, t_hero *hero)
{
	if (hero->self->addr == hero->hero_right[0]->addr
		|| hero->self->addr == hero->hero_right[1]->addr
		|| hero->self->addr == hero->hero_right[2]->addr
		|| hero->self->addr == hero->hero_right[3]->addr)
		data->hero.self->img
			= data->hero.hero_right[data->hero.move_frame]->img;
	if (hero->self->addr == hero->hero_left[0]->addr
		|| hero->self->addr == hero->hero_left[1]->addr
		|| hero->self->addr == hero->hero_left[2]->addr
		|| hero->self->addr == hero->hero_left[3]->addr)
		data->hero.self->img = data->hero.hero_left[data->hero.move_frame]->img;
}
