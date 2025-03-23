/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:01:38 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/16 13:19:20 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*------------- print error and exit --------------*/
void	ft_print_exit(char *s, char **map, char *str)
{
	if (map != NULL)
		ft_free_double(map);
	if (str != NULL)
		free(str);
	if (s != NULL)
		ft_printf("%s", s);
	exit(1);
}

void	ft_free_double(char **var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		free(var[i]);
		i++;
	}
	free(var);
}

void	put_img_to_window(t_data *dt, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(dt->mlx, img, x, y) == -1)
	{
		if (dt->player_txtr)
			mlx_delete_texture(dt->player_txtr);
		ft_print_exit("❌ Failed to put image to window!\n", dt->map, NULL);
	}
}
