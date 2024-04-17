/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:25:25 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/17 14:26:01 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "config.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_door
{
	t_img	*door[4];
	int		x_position;
	int		y_position;
}				t_door;

typedef struct s_coin
{
	t_img	*coin[10];
	int		frame;
}				t_coin;

typedef struct s_heart
{
	t_img	*heart[8];
	int		frame;
}				t_heart;

typedef struct s_key
{
	t_img	*key;
	int		x_position;
	int		y_position;
}				t_key;

typedef struct s_c_position
{
	int		x;
	int		y;
	char	type;
}	t_c_position;

typedef struct s_collectibles
{
	t_heart			heart;
	t_key			key;
	t_coin			coin;
	t_c_position	c_position[MAX_COLLECTIBLES];
	int				num_c;
}	t_collectibles;

typedef struct s_hero
{
	t_img	*self;
	t_img	*hero_front;
	t_img	*hero_back;
	t_img	*hero_left[4];
	t_img	*hero_right[4];
	int		x_position;
	int		y_position;
	int		move_frame;
	int		collectibles;
}				t_hero;

typedef struct s_tiles
{
	t_img		*top_left;
	t_img		*top_right;
	t_img		*top;
	t_img		*left;
	t_img		*right;
	t_img		*bottom_left;
	t_img		*bottom_right;
	t_img		*bottom;
	t_img		*center;
	t_img		*middle;
	t_door		door;
}				t_tiles;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
	char			**map;
	int				nbr_c;
	int				nbr_b;
	int				nbr_e;
	int				player;
	int				exit;
	int				is_running;
	t_tiles			tiles;
	t_hero			hero;
	t_collectibles	collectibles;
}	t_data;

#endif