/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomazc < ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:47:47 by ftomazc           #+#    #+#             */
/*   Updated: 2024/04/17 14:43:57 by ftomazc          ###   ########.fr       */
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
# include "config.h"
# include "structs.h"

/*error.c*/
void				check_errors(int argc, char **argv, t_data *data);

/*event_handling.c*/
int					close_program(t_data *data);
int					deal_hero_key(int key, t_data *data);

/*init_collectibles.c*/
void				init_heart(t_data *data);
void				init_coin(t_data *data);
void				init_key(t_data *data);
void				init_collectibles(t_data *data);

/*init_game.c*/
void				game_init(t_data *data);
void				loading_imgs(t_data *data);
void				init_map(t_data *data);
void				init_door(t_data *data);
void				init_hero(t_data *data);

/*map_construction_utils.c*/
int					ft_valid(char c);
void				add_collectibles(t_data *data, int x, int y);
void				add_hero(t_data *data);
void				map_exit_failure(t_data *data);

/*map_construction.c*/
int					check_pec(t_data *data);
int					check_if_retangular(t_data *data);
int					find_walls(t_data *data);
void				check_map_construct(t_data *data);

/*map_handling.c*/
void				check_map(t_data *data);
int					read_map(char *file_name, t_data *data);
int					alloc_mem_map(char *file_name, t_data *data);
int					count_width_height(char *file_name, t_data *data);

/*map_utils.c*/
void				get_position(t_data *data, int *x_pos, int *y_pos,
						char map_char);
int					ft_strlen_nl(char *str);
void				print_info(t_data *data);
void				print_map(t_data *data);
void				free_map(char **map);

/*map_validation.c*/
void				ft_flood_fill(t_data *data, int x, int y, char **map);
void				check_map_validity(t_data *data);

/*mem_mgmt.c*/
void				free_assets(t_data *data);
void				free_hero(t_data *data);
void				free_collectibles(t_data *data);
void				free_tiles(t_data *data);
void				free_image(t_data *data, t_img **image);

/*move_hero.c*/
void				move_hero_down(t_data *data);
void				move_hero_up(t_data *data);
void				move_hero_to_left(t_data *data);
void				move_hero_to_right(t_data *data);

/*so_long_utils.c*/
void				check_hero_addr(t_data *data, t_hero *hero);
unsigned int		timer(void);
t_img				*ft_make_img(char *path, t_data *data);
void				display_size(t_data *data);

/*so_long_utils2.c*/
void				ft_put_img_to_window(t_data *data, void *img, double x,
						double y);
void				oversized_display(t_data *data, void *img, double x,
						double y);

/*spawn_collectibles.c*/
void				spawn_collectibles(t_data *data, int x, int y);
int					collectible_type(t_c_position *c, int x, int y, char type);

/*spawn_map.c*/
void				spawn_map(t_data *data);
void				put_img(t_data *data, int x, int y);
void				draw_outline(t_data *data, int x, int y);
void				draw_bottom_outline(t_data *data, int x, int y);
void				draw_top_outline(t_data *data, int x, int y);

/*sprite_animation.c*/
int					sprites_animation(t_data *data);
void				open_door(t_data *data);
int					hero_eng(t_data *data);
int					coin_eng(t_data *data);
int					heart_eng(t_data *data);

#endif