/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_errors_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:11:41 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/18 14:51:58 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*----------- Check if the map is rectangular --------- */
void	ft_check_rectangular(t_data *dt)
{
	int	line_len;

	dt->map_width = ft_strlen(dt->map[0]);
	dt->i = 1;
	while (dt->i < dt->map_height)
	{
		line_len = ft_strlen(dt->map[dt->i]);
		if (dt->map_width < 3 || line_len != dt->map_width)
			ft_print_exit("🚧 Map error: Not rectangular!\n", dt->map, NULL);
		dt->i++;
	}
}

/*------ Check the map boundaries with 1 ----- */
void	ft_check_map_bounds(t_data *dt)
{
	dt->i = 0;
	while (dt->map[0][dt->i] != '\0')
	{
		if (dt->map[0][dt->i] != '1')
			ft_print_exit("🚧 Map error!\n", dt->map, NULL);
		dt->i++;
	}
	dt->i = 0;
	while (dt->map[dt->map_height - 1][dt->i] != '\0')
	{
		if (dt->map[dt->map_height - 1][dt->i] != '1')
			ft_print_exit("🚧 Map error!\n", dt->map, NULL);
		dt->i++;
	}
	dt->i = 1;
	while (dt->i < dt->map_height - 1)
	{
		if (dt->map[dt->i][0] != '1'
			|| dt->map[dt->i][dt->map_width - 1] != '1')
			ft_print_exit("🚧 Map error!\n", dt->map, NULL);
		dt->i++;
	}
}

void	not_valid_char(char c, t_data *dt)
{
	if (c != '1' && c != 'P' && c != 'E'
		&& c != 'C' && c != '0' && c != 'N')
		ft_print_exit("🚧 Map error!\n", dt->map, NULL);
}

/*--------- check if there's E P C 0 ----------*/
void	ft_check_chars(t_data *dt)
{
	dt->i = 1;
	while (dt->i < dt->map_height - 1)
	{
		dt->j = 1;
		while (dt->map[dt->i][dt->j] != '\0')
		{
			not_valid_char(dt->map[dt->i][dt->j], dt);
			if (dt->map[dt->i][dt->j] == 'C')
				dt->count_c++;
			if (dt->map[dt->i][dt->j] == 'E')
				dt->count_e++;
			if (dt->map[dt->i][dt->j] == 'P')
				dt->count_p++;
			if (dt->map[dt->i][dt->j] == 'N')
				dt->count_n++;
			dt->j++;
		}
		dt->i++;
	}
	if (dt->count_p != 1 || dt->count_e != 1 || dt->count_c == 0
		|| dt->count_n == 0)
		ft_print_exit("🚧 Map error: Check map characters!\n", dt->map, NULL);
}

/*--------- check valid path ----------*/
void	ft_check_valid_path(t_data *dt)
{
	ft_get_player_exit_position(dt);
	ft_copy_map(dt);
	ft_flood_fill_func(dt->map_cpy, dt->player_x, dt->player_y);
	ft_check_flood_fill(dt);
}
