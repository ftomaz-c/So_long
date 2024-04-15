/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:47:47 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/15 15:55:33 by ftomazc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libs/libft/includes/libft.h"
# include "../../libs/mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <sys/time.h>
# include <math.h>
# include <pthread.h>

# define PIXEL_SIZE 64
# define WIDTH 1280
# define HEIGHT 960
# define TIME 
# define TOP_LEFT "src/assets/tiles/top_left.xpm"
# define TOP_RIGHT "src/assets/tiles/top_right.xpm"
# define TOP "src/assets/tiles/top.xpm"
# define LEFT "src/assets/tiles/left.xpm"
# define RIGHT "src/assets/tiles/right.xpm"
# define BOTTOM_LEFT "src/assets/tiles/bottom_left.xpm"
# define BOTTOM_RIGHT "src/assets/tiles/bottom_right.xpm"
# define BOTTOM "src/assets/tiles/bottom.xpm"
# define CENTER "src/assets/tiles/center.xpm"
# define MIDDLE "src/assets/tiles/middle.xpm"

# define HERO_FRONT "src/assets/hero/hero_front.xpm"
# define HERO_BACK "src/assets/hero/hero_back.xpm"
# define HERO_LEFT_1 "src/assets/hero/hero_left.xpm"
# define HERO_LEFT_2 "src/assets/hero/hero_left2.xpm"
# define HERO_LEFT_3 "src/assets/hero/hero_left3.xpm"
# define HERO_LEFT_4 "src/assets/hero/hero_left4.xpm"
# define HERO_RIGHT_1 "src/assets/hero/hero_right.xpm"
# define HERO_RIGHT_2 "src/assets/hero/hero_right2.xpm"
# define HERO_RIGHT_3 "src/assets/hero/hero_right3.xpm"
# define HERO_RIGHT_4 "src/assets/hero/hero_right4.xpm"

# define HEART_1 "src/assets/collectibles/heart/heart_1.xpm"
# define HEART_2 "src/assets/collectibles/heart/heart_2.xpm"
# define HEART_3 "src/assets/collectibles/heart/heart_3.xpm"
# define HEART_4 "src/assets/collectibles/heart/heart_4.xpm"
# define HEART_5 "src/assets/collectibles/heart/heart_5.xpm"
# define HEART_6 "src/assets/collectibles/heart/heart_6.xpm"
# define HEART_7 "src/assets/collectibles/heart/heart_7.xpm"

# define KEY "src/assets/collectibles/key.xpm"

# define COIN_1 "src/assets/collectibles/coin/coin_1.xpm"
# define COIN_2 "src/assets/collectibles/coin/coin_2.xpm"
# define COIN_3 "src/assets/collectibles/coin/coin_3.xpm"
# define COIN_4 "src/assets/collectibles/coin/coin_4.xpm"
# define COIN_5 "src/assets/collectibles/coin/coin_5.xpm"
# define COIN_6 "src/assets/collectibles/coin/coin_6.xpm"
# define COIN_7 "src/assets/collectibles/coin/coin_7.xpm"
# define COIN_8 "src/assets/collectibles/coin/coin_8.xpm"
# define COIN_9 "src/assets/collectibles/coin/coin_9.xpm"

# define DOOR_1 "src/assets/tiles/door/small_door1.xpm"
# define DOOR_2 "src/assets/tiles/door/small_door2.xpm"
# define DOOR_3 "src/assets/tiles/door/small_door3.xpm"
# define DOOR_4 "src/assets/tiles/door/small_door4.xpm"

# define STAIRS "src/assets/tiles/stairs.xpm"
# define MAX_COLLECTIBLES 100

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

typedef struct s_gem
{
	t_img	*gem[14];
	int		frame;
}				t_gem;

typedef struct s_chest
{
	t_img	*chest[6];
	int		opened;
	int		x_position;
	int		y_position;
}				t_chest;

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
	t_chest			chest;
	t_key			key;
	t_gem			gem;
	t_coin			coin;
	t_c_position	c_position[MAX_COLLECTIBLES];
	int				num_c;
}	t_collectibles;

typedef struct s_stairs
{
	t_img	*stairs;
	int		platforms;
}	t_stairs;

typedef struct s_hero
{
	t_img	*self;
	t_img	*hero_front;
	t_img	*hero_back;
	t_img	*hero_left[4];
	t_img	*hero_right[4];
	int		move_frame;
	double	jump_frame;
	int		x_position;
	int		y_position;
	double	x_frame;
	double	y_frame;
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
	t_stairs	stairs;
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
	t_tiles			tiles;
	t_hero			hero;
	t_collectibles	collectibles;
}	t_data;

int					read_map(char *file_name, t_data *data);
int					deal_hero_key(int key, t_data *data);
int					close_program(t_data *data);
int					sprites_animation(t_data *data);
void				game_init(t_data *data);
void				open_door(t_data *data);
void				move_hero_to_right(t_data *data);
void				move_hero_to_left(t_data *data);
void				move_hero_up(t_data *data);
void				move_hero_down(t_data *data);
void				spawn_collectibles(t_data *data, int x, int y);
void				check_hero_addr(t_data *data, t_hero *hero);

/*error.c*/
void				check_errors(int argc, char **argv, t_data *data);
void				free_map(char **map);

/*check_map.c*/
void				check_map(t_data *data);
void				check_map_construct(t_data *data);
void				check_map_validity(t_data *data);

/*loading_imgs.c && loading_imgs2.c*/
void				loading_imgs(t_data *data);
void				init_hero(t_data *data);
void				init_door(t_data *data);
void				init_map(t_data *data);
void				init_collectibles(t_data *data);
void				init_heart(t_data *data);
void				init_coin(t_data *data);
void				init_chest(t_data *data);
void				init_gem(t_data *data);
void				init_key(t_data *data);

/*spawn_map.c*/
void				spawn_map(t_data *data);

/*so_long_utils.c*/
t_img				*ft_make_img(char *path, t_data *data);
void				ft_put_img_to_window(t_data *data, void *img, double x,
						double y);
void				get_position(t_data *data, int *x_pos, int *y_pos,
						char map_char);
void				animate(t_data *data, void *img, int x_position,
						int y_position);

unsigned int		timer(void);
void				print_map(t_data *data);
int					ft_strlen_nl(char *str);
void				check_map_construct(t_data *data);
int					find_walls(t_data *data);
int					check_if_retangular(t_data *data);
int					check_pec(t_data *data);
void				add_hero(t_data *data);
void				add_collectibles(t_data *data, int x, int y);
int					ft_valid(char c);
void				ft_flood_fill(t_data *data, int x, int y, char **map);

#endif