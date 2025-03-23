/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enmey_animation_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:46:29 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/12 14:02:39 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_delete_enmey_text(t_data *dt)
{
	if (dt->emy1_txtr)
		mlx_delete_texture(dt->emy1_txtr);
	if (dt->emy2_txtr)
		mlx_delete_texture(dt->emy2_txtr);
	if (dt->emy3_txtr)
		mlx_delete_texture(dt->emy3_txtr);
}

void	load_enmey_txtures(t_data *dt)
{
	dt->emy1_txtr = mlx_load_png("textures/emy1.png");
	dt->emy2_txtr = mlx_load_png("textures/emy2.png");
	dt->emy3_txtr = mlx_load_png("textures/emy3.png");
	if (!dt->emy1_txtr || !dt->emy2_txtr || !dt->emy3_txtr)
	{
		if (dt->player_txtr)
			mlx_delete_texture(dt->player_txtr);
		ft_delete_enmey_text(dt);
		ft_print_exit("❌ Failed to load enmey texture!\n", dt->map, NULL);
	}
	dt->arr[0] = mlx_texture_to_image(dt->mlx, dt->emy1_txtr);
	dt->arr[1] = mlx_texture_to_image(dt->mlx, dt->emy2_txtr);
	dt->arr[2] = mlx_texture_to_image(dt->mlx, dt->emy3_txtr);
	if (!dt->arr[0] || !dt->arr[1] || !dt->arr[2])
	{
		if (dt->player_txtr)
			mlx_delete_texture(dt->player_txtr);
		ft_delete_enmey_text(dt);
		ft_print_exit("❌ Failed to convert enemy texture to image!\n",
			dt->map, NULL);
	}
}

void	set_enmy(t_data *dt, int pcn)
{
	if (pcn <= 2)
		put_img_to_window(dt, dt->arr[pcn], dt->n_x * 50, dt->n_y * 50);
	if (pcn == 0)
	{
		mlx_delete_image(dt->mlx, dt->arr[2]);
		dt->arr[2] = mlx_texture_to_image(dt->mlx, dt->emy3_txtr);
	}
	else if (pcn == 1)
	{
		mlx_delete_image(dt->mlx, dt->arr[0]);
		dt->arr[0] = mlx_texture_to_image(dt->mlx, dt->emy1_txtr);
	}
	else if (pcn == 2)
	{
		mlx_delete_image(dt->mlx, dt->arr[1]);
		dt->arr[1] = mlx_texture_to_image(dt->mlx, dt->emy2_txtr);
	}
}

void	srch_enmey(t_data *dt)
{
	dt->j = 0;
	while (dt->j < dt->map_height)
	{
		dt->i = 0;
		while (dt->i < dt->map_width)
		{
			if (dt->map[dt->j][dt->i] == 'N')
			{
				dt->n_x = dt->i;
				dt->n_y = dt->j;
				set_enmy(dt, dt->picnbr);
			}
			dt->i++;
		}
		dt->j++;
	}
}

void	ft_enmey_animation(void *param)
{
	t_data	*dt;

	dt = (t_data *)param;
	if (dt->time == 6)
	{
		dt->time = 0;
		if (dt->picnbr > 3)
			dt->picnbr = 0;
		srch_enmey(dt);
		dt->picnbr++;
	}
	dt->time++;
}
