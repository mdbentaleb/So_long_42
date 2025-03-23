/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:06:58 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/12 12:02:04 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_delete_texture(t_data *dt)
{
	if (dt->wall_txtr)
		mlx_delete_texture(dt->wall_txtr);
	if (dt->coin_txtr)
		mlx_delete_texture(dt->coin_txtr);
	if (dt->grnd_txtr)
		mlx_delete_texture(dt->grnd_txtr);
	if (dt->clsdr_txtr)
		mlx_delete_texture(dt->clsdr_txtr);
}

void	ft_load_textures(t_data *dt)
{
	dt->wall_txtr = mlx_load_png("textures/wall.png");
	dt->coin_txtr = mlx_load_png("textures/coin.png");
	dt->grnd_txtr = mlx_load_png("textures/ground.png");
	dt->player_txtr = mlx_load_png("textures/player.png");
	dt->clsdr_txtr = mlx_load_png("textures/closed_door.png");
	if (!dt->wall_txtr || !dt->coin_txtr || !dt->grnd_txtr
		|| !dt->player_txtr || !dt->clsdr_txtr)
	{
		if (dt->player_txtr)
			mlx_delete_texture(dt->player_txtr);
		ft_delete_texture(dt);
		ft_print_exit("❌ Failed to load texture!\n", dt->map, NULL);
	}
}

void	ft_delete_image(t_data *dt)
{
	if (dt->wall)
		mlx_delete_image(dt->mlx, dt->wall);
	if (dt->coin_txtr)
		mlx_delete_image(dt->mlx, dt->coin);
	if (dt->grnd)
		mlx_delete_image(dt->mlx, dt->grnd);
	if (dt->plyr)
		mlx_delete_image(dt->mlx, dt->plyr);
	if (dt->clsdr)
		mlx_delete_image(dt->mlx, dt->clsdr);
}

void	ft_texture_to_image(t_data *dt)
{
	dt->wall = mlx_texture_to_image(dt->mlx, dt->wall_txtr);
	dt->coin = mlx_texture_to_image(dt->mlx, dt->coin_txtr);
	dt->grnd = mlx_texture_to_image(dt->mlx, dt->grnd_txtr);
	dt->plyr = mlx_texture_to_image(dt->mlx, dt->player_txtr);
	dt->clsdr = mlx_texture_to_image(dt->mlx, dt->clsdr_txtr);
	ft_delete_texture(dt);
	if (!dt->wall || !dt->coin || !dt->grnd
		|| !dt->plyr || !dt->clsdr)
	{
		if (dt->player_txtr)
			mlx_delete_texture(dt->player_txtr);
		ft_delete_image(dt);
		ft_print_exit("❌ Failed to convert texture to image!\n", dt->map, NULL);
	}
}

void	ft_img_to_wind(t_data *dt)
{
	dt->i = 0;
	while (dt->i < dt->map_height)
	{
		dt->j = 0;
		while (dt->j < dt->map_width)
		{
			dt->c = dt->map[dt->i][dt->j];
			if (dt->c == 'P' || dt->c == 'C' || dt->c == '0' || dt->c == 'N')
				put_img_to_window(dt, dt->grnd, dt->j * 50, dt->i * 50);
			if (dt->c == '1')
				put_img_to_window(dt, dt->wall, dt->j * 50, dt->i * 50);
			else if (dt->c == 'P')
				put_img_to_window(dt, dt->plyr, dt->j * 50, dt->i * 50);
			else if (dt->c == 'E')
				put_img_to_window(dt, dt->clsdr, dt->j * 50, dt->i * 50);
			else if (dt->c == 'C')
				put_img_to_window(dt, dt->coin, dt->j * 50, dt->i * 50);
			dt->j++;
		}
		dt->i++;
	}
}
