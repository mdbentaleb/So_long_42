/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:54:19 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/23 13:18:38 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	char			**map;
	char			**map_cpy;
	char			c;

	int				map_height;
	int				map_width;
	int				i;
	int				j;
	int				count_c;
	int				count_e;
	int				count_p;
	int				count_n;
	int				move_count;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				win_width;
	int				win_height;

	mlx_t			*mlx;

	mlx_texture_t	*player_txtr;
	mlx_texture_t	*clsdr_txtr;
	mlx_texture_t	*grnd_txtr;
	mlx_texture_t	*coin_txtr;
	mlx_texture_t	*wall_txtr;

	mlx_texture_t	*emy1_txtr;
	mlx_texture_t	*emy2_txtr;
	mlx_texture_t	*emy3_txtr;

	mlx_image_t		*plyr;
	mlx_image_t		*clsdr;
	mlx_image_t		*grnd;
	mlx_image_t		*coin;
	mlx_image_t		*wall;

	mlx_image_t		*arr[3];
	int				time;
	int				picnbr;
	int				n_x;
	int				n_y;

	mlx_image_t		*str_n_wind;
}	t_data;

void	ft_print_exit(char *s, char **map, char *str);
void	ft_free_double(char **var);
void	ft_check_map_name(char *s);
void	ft_read_map(char *map_name, t_data *dt);
void	ft_check_map_errors(t_data *dt);
void	ft_check_rectangular(t_data *dt);
void	ft_check_map_bounds(t_data *dt);
void	ft_check_chars(t_data *dt);
void	ft_check_valid_path(t_data *dt);
void	ft_get_player_exit_position(t_data *dt);
void	ft_copy_map(t_data *dt);
void	ft_flood_fill_func(char **map_cpy, int x, int y);
void	ft_check_flood_fill(t_data *dt);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int nb);
void	ft_game(t_data *dt);
void	ft_load_textures(t_data *dt);
void	ft_delete_texture(t_data *dt);
void	ft_texture_to_image(t_data *dt);
void	ft_img_to_wind(t_data *dt);
void	ft_delete_image(t_data *dt);
void	ft_enmey_animation(void *param);
void	load_enmey_txtures(t_data *dt);
void	ft_delete_enmey_text(t_data *dt);
void	ft_delete_enmey_images(t_data *dt);
void	put_img_to_window(t_data *dt, mlx_image_t *img, int x, int y);

#endif