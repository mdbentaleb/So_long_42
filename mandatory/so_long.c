/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:54:17 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/18 15:17:37 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arc, char **arv)
{
	t_data	dt;

	if (arc != 2)
		ft_print_exit("🚧 Usage: ./so_long <map_name.ber>\n", NULL, NULL);
	ft_check_map_name(arv[1]);
	ft_read_map(arv[1], &dt);
	ft_check_map_errors(&dt);
	if ((dt.map_width * 50) > 2300 || (dt.map_height * 50) > 1300)
		ft_print_exit("🚧 Map Error: map is too large!\n", dt.map, NULL);
	ft_game(&dt);
	return (0);
}
