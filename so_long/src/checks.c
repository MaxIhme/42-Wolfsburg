/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:35:55 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/14 16:30:38 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	char	*line;
	int		lines;

	line = (char *) 0x10000005;
	lines = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
		lines ++;
	}
	lines--;
	return (lines);
}

/**
 * @brief 
 * 
 * @param argv 
 * @return char** (is allocated memory, don't forget to free)
 */
void	init_map(char *path, t_window *window)
{
	int		fd;
	char	*line;
	int		run_line;
	char	*rtn;
	int		cmp;

	run_line = 0;
	if (ft_strlen(path) < 5)
		error(ERR_NOT_BER_FILE, window);
	rtn = ft_substr(path, ft_strlen(path) - 4, 4);
	cmp = ft_strncmp(rtn, ".ber", 4);
	free(rtn);
	if (cmp != 0)
		error(ERR_NOT_BER_FILE, window);
	open_file_count_lines(path, window);
	window -> map = malloc((sizeof(char *)) * window -> map_height);
	if (!window -> map)
		error(ERR_ALLOC, window);
	fd = open(path, O_RDONLY);
	while (run_line < window -> map_height)
	{
		line = get_next_line(fd);
		window -> map[run_line] = line;
		run_line++;
	}
}

void	check_char(t_window *window)
{
	int	run_height;
	int	run_width;

	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (window -> map[run_height][run_width])
		{
			if (!(window -> map[run_height][run_width] == '1'
				|| window -> map[run_height][run_width] == '0'
				|| window -> map[run_height][run_width] == 'C'
				|| window -> map[run_height][run_width] == 'E'
				|| window -> map[run_height][run_width] == 'P'))
				error(ERR_WRONG_CHAR, window);
			if (window -> map[run_height][run_width] == 'P')
			{
				window -> player_pos_x = run_width;
				window -> player_pos_y = run_height;
			}
			run_width++;
		}
		run_height++;
	}
}

void	count_width(t_window *window)
{
	int	i;

	i = 0;
	while (window -> map[0][i])
	{
		i++;
	}
	window -> map_width = i;
}

int	check_map(t_window *window)
{
	count_width(window);
	check_char(window);
	check_border(window);
	check_p_e_c(window);
	check_rectangularity(window);
	check_path(window);
	return (1);
}
