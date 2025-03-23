/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:00:33 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/18 16:14:46 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	vld_mv(t_data *dt, int x, int y)
{
	if (dt->map[y][x] != '1')
		return (1);
	return (0);
}

void	ft_move_player(t_data *dt, int x, int y)
{
	dt->player_x = x;
	dt->player_y = y;
	dt->move_count++;
	mlx_delete_image(dt->mlx, dt->plyr);
	if (dt->map[y][x] == 'C')
	{
		dt->count_c--;
		dt->map[y][x] = '0';
		mlx_image_to_window(dt->mlx, dt->grnd, x * 50, y * 50);
	}
	ft_printf("moves = %d\n", dt->move_count);
	dt->plyr = mlx_texture_to_image(dt->mlx, dt->player_txtr);
	mlx_image_to_window(dt->mlx, dt->plyr, x * 50, y * 50);
}

void	ft_handle_keys(mlx_key_data_t ky, void *prm)
{
	t_data	*dt;
	int		new_x;
	int		new_y;

	dt = (t_data *)prm;
	new_x = dt->player_x;
	new_y = dt->player_y;
	if (dt->map[dt->player_y][dt->player_x] == 'E' && dt->count_c == 0)
	{
		ft_printf("✅ You Won.\n");
		return (mlx_close_window(dt->mlx));
	}
	if (ky.action == MLX_PRESS || ky.action == MLX_REPEAT)
	{
		if (ky.key == MLX_KEY_UP && (vld_mv(dt, new_x, new_y - 1) == 1))
			ft_move_player(dt, new_x, new_y - 1);
		else if (ky.key == MLX_KEY_DOWN && (vld_mv(dt, new_x, new_y + 1) == 1))
			ft_move_player(dt, new_x, new_y + 1);
		else if (ky.key == MLX_KEY_LEFT && (vld_mv(dt, new_x - 1, new_y) == 1))
			ft_move_player(dt, new_x - 1, new_y);
		else if (ky.key == MLX_KEY_RIGHT && (vld_mv(dt, new_x + 1, new_y) == 1))
			ft_move_player(dt, new_x + 1, new_y);
		else if (ky.key == MLX_KEY_ESCAPE)
			mlx_close_window(dt->mlx);
	}
}

void	ft_game(t_data *dt)
{
	dt->move_count = 0;
	dt->win_width = dt->map_width * 50;
	dt->win_height = dt->map_height * 50;
	dt->mlx = mlx_init(dt->win_width, dt->win_height, "SO LONG", false);
	if (!dt->mlx)
	{
		ft_free_double(dt->map);
		exit(1);
	}
	ft_load_textures(dt);
	ft_texture_to_image(dt);
	ft_img_to_wind(dt);
	mlx_key_hook(dt->mlx, ft_handle_keys, dt);
	mlx_loop(dt->mlx);
	mlx_delete_texture(dt->player_txtr);
	ft_free_double(dt->map);
	mlx_terminate(dt->mlx);
}
