/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:41:47 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/10 16:38:53 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_new_line(t_window *window)
{
	int	run_height;
	int	run_width;

	run_height = 0;
	while (run_height < window -> map_height - 1)
	{
		run_width = 0;
		while (window -> map[run_height][run_width] != '\n')
		{
			run_width++;
		}
		window -> map[run_height][run_width] = '\0';
		run_height++;
	}
}

/**
 * @brief check if line full of 1's
 * @return 0 if ok, 1 if not
 */
int	check_border_horizontal(char *line)
{
	int	run;

	run = 0;
	while (line[run])
	{
		if (line[run] != '1')
			return (1);
		run++;
	}
	return (0);
}

/**
 * @brief check if border full of 1's 
 */
void	check_border(t_window *window)
{
	int	run;

	run = 1;
	if (check_border_horizontal(window -> map[0]))
		error (ERR_BORDER, window);
	if (check_border_horizontal(window -> map[window -> map_height - 1]))
		error (ERR_BORDER, window);
	while (run < window -> map_height - 1)
	{
		if (window -> map[run][0] != '1')
			error(ERR_BORDER, window);
		if (window -> map[run][(window -> map_width - 1)] != '1')
			error(ERR_BORDER, window);
		run++;
	}
}

void	check_p_e_c(t_window *window)
{
	int			run_width;
	int			run_height;
	static int	player = 0;
	static int	end = 0;
	static int	collect = 0;

	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (run_width < window -> map_width)
		{
			if (window -> map[run_height][run_width] == 'P')
				player++;
			if (window -> map[run_height][run_width] == 'E')
				end++;
			if (window -> map[run_height][run_width] == 'C')
				collect++;
			run_width++;
		}
		run_height++;
	}
	if (!(collect >= 1 && player == 1 && end == 1))
		error(ERR_P_E_C, window);
	window -> count_c_e = collect + 1;
}

void	check_rectangularity(t_window *window)
{
	int	run_height;
	int	run_width;

	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (window -> map[run_height][run_width])
		{
			run_width++;
		}
		if (run_width != window -> map_width)
			error(ERR_RECTANGULAR, window);
		run_height++;
	}
}
