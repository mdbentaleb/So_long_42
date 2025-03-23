/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:48:23 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/18 14:48:02 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*------------- check correct map name --------------*/
void	ft_check_map_name(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 4)
		ft_print_exit("🚧 Error: Incorrect file name!\n", NULL, NULL);
	if (s[len - 1] != 'r' || s[len - 2] != 'e'
		|| s[len - 3] != 'b' || s[len - 4] != '.')
		ft_print_exit("🚧 Error: Incorrect file name!\n", NULL, NULL);
}

/*------------- read map from file --------------*/
void	ft_read_map(char *map_name, t_data *dt)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*map_joined;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		ft_print_exit("🚧 Error: File missing or empty!\n", NULL, line);
	dt->map_height = 0;
	map_joined = ft_strdup("");
	while (line)
	{
		if (line[0] == '\n')
			ft_print_exit("🚧 Map error: remove new line!\n", NULL, line);
		temp = ft_strjoin(map_joined, line);
		free(line);
		map_joined = temp;
		line = get_next_line(fd);
		dt->map_height++;
	}
	dt->map = ft_split(map_joined, '\n');
	free(map_joined);
	close(fd);
}

/*------------- check map errors --------------*/
void	ft_check_map_errors(t_data *dt)
{
	dt->count_c = 0;
	dt->count_e = 0;
	dt->count_p = 0;
	dt->count_n = 0;
	ft_check_rectangular(dt);
	ft_check_map_bounds(dt);
	ft_check_chars(dt);
	ft_check_valid_path(dt);
}
