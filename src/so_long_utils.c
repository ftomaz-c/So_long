/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:58:35 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/19 13:03:23 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_size(t_data *data)
{
	Display	*display;
	Screen	*screen;

	display = XOpenDisplay(NULL);
	screen = DefaultScreenOfDisplay(display);
	data->screen_width = screen->width - 100;
	data->screen_height = screen->height - 100;
	XCloseDisplay(display);
	if (data->map_width * PIXEL_SIZE < data->screen_width)
		data->screen_width = data->map_width * PIXEL_SIZE;
	if (data->map_height * PIXEL_SIZE < data->screen_height)
		data->screen_height = data->map_height * PIXEL_SIZE;
}

t_img	*ft_make_img(char *path, t_data *data)
{
	t_img	*image;
	int		width;
	int		height;

	image = ft_calloc(sizeof(t_img), 1);
	if (!image)
		return (0);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (!image->img)
	{
		ft_putstr_fd("Error: Texture not found\n", STDERR_FILENO);
		free(image);
		close_program(data);
	}
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel), \
				&(image->line_lenght), &(image->endian));
	return (image);
}

/*unsigned int	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}*/

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

void	print_movements(t_data *data)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(data->hero.move_num);
	phrase = ft_strjoin("Movements: ", movements);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 22, 0x00FF0000, phrase);
	free(movements);
	free(phrase);
}
