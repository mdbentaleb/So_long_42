/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:48:23 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/18 14:57:34 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* ---------- get player and exit position --------- */
void	ft_get_player_exit_position(t_data *dt)
{
	dt->j = 1;
	while (dt->j < dt->map_height - 1)
	{
		dt->i = 0;
		while (dt->i < dt->map_width)
		{
			dt->c = dt->map[dt->j][dt->i];
			if (dt->c == 'P')
			{
				dt->player_x = dt->i;
				dt->player_y = dt->j;
			}
			if (dt->c == 'E')
			{
				dt->exit_x = dt->i;
				dt->exit_y = dt->j;
			}
			dt->i++;
		}
		dt->j++;
	}
}

/* --------------- map duplicating ------------ */
void	ft_copy_map(t_data *dt)
{
	dt->map_cpy = malloc((dt->map_height + 1) * sizeof(char *));
	if (!dt->map_cpy)
		ft_print_exit("❌ Allocation Failed", dt->map, NULL);
	dt->i = 0;
	while (dt->i < dt->map_height)
	{
		dt->j = 0;
		dt->map_cpy[dt->i] = malloc((dt->map_width + 1) * sizeof(char));
		if (!dt->map_cpy[dt->i])
		{
			ft_free_double(dt->map_cpy);
			ft_print_exit("🚧 Error: Malloc failed!\n", dt->map, NULL);
		}
		while (dt->j < dt->map_width)
		{
			dt->map_cpy[dt->i][dt->j] = dt->map[dt->i][dt->j];
			dt->j++;
		}
		dt->map_cpy[dt->i][dt->j] = '\0';
		dt->i++;
	}
	dt->map_cpy[dt->i] = NULL;
}

void	ft_flood_fill_func(char **map_cpy, int x, int y)
{
	if (map_cpy[y][x] == '1')
		return ;
	map_cpy[y][x] = '1';
	ft_flood_fill_func(map_cpy, x - 1, y);
	ft_flood_fill_func(map_cpy, x + 1, y);
	ft_flood_fill_func(map_cpy, x, y + 1);
	ft_flood_fill_func(map_cpy, x, y - 1);
}

void	ft_check_flood_fill(t_data *dt)
{
	dt->i = 0;
	while (dt->i < dt->map_height)
	{
		dt->j = 0;
		while (dt->j < dt->map_width)
		{
			if (dt->map_cpy[dt->i][dt->j] != '1'
				&& dt->map_cpy[dt->i][dt->j] != '0')
			{
				ft_free_double(dt->map_cpy);
				ft_print_exit("🚧 Map error\n", dt->map, NULL);
			}
			dt->j++;
		}
		dt->i++;
	}
	ft_free_double(dt->map_cpy);
}
