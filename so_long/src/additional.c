/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:12:50 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/14 10:52:55 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_file_to_image(t_window *window)
{
	window -> player_ptr = mlx_xpm_file_to_image(window -> mlx_ptr, PATH_PLAYER,
			&window -> tile_width, &window -> tile_height);
	window -> collect_ptr = mlx_xpm_file_to_image(window -> mlx_ptr, PATH_ITEM,
			&window -> tile_width, &window -> tile_height);
	window -> exit_ptr = mlx_xpm_file_to_image(window -> mlx_ptr, PATH_EXIT,
			&window -> tile_width, &window -> tile_height);
	window -> wall_ptr = mlx_xpm_file_to_image(window -> mlx_ptr, PATH_WALL,
			&window -> tile_width, &window -> tile_height);
	window -> floor_ptr = mlx_xpm_file_to_image(window -> mlx_ptr, PATH_FLOOR,
			&window -> tile_width, &window -> tile_height);
}

void	open_file_count_lines(char *path, t_window *window)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(ERR_WRONG_FILE, window);
	window -> map_height = count_lines(fd);
	close(fd);
}

void	map_copy_help(int h, int w, int **map_copy, t_window *window)
{
	if (window -> map[h][w] == '1')
		map_copy[h][w] = 1;
	if (window -> map[h][w] == '0')
		map_copy[h][w] = 0;
	if (window -> map[h][w] == 'P')
		map_copy[h][w] = 2;
	if (window -> map[h][w] == 'C')
		map_copy[h][w] = 3;
	if (window -> map[h][w] == 'E')
		map_copy[h][w] = 4;
}

int	substitute_zeros_help(int h, int w, int change, int **map_copy)
{
	if (map_copy[h - 1][w] == 0 || map_copy[h - 1][w] == 3)
	{
		map_copy[h - 1][w] = 2;
		change++;
	}
	if (map_copy[h + 1][w] == 0 || map_copy[h + 1][w] == 3)
	{
		map_copy[h + 1][w] = 2;
		change++;
	}
	if (map_copy[h][w - 1] == 0 || map_copy[h][w - 1] == 3)
	{
		map_copy[h][w - 1] = 2;
		change++;
	}
	if (map_copy[h][w + 1] == 0 || map_copy[h][w + 1] == 3)
	{
		map_copy[h][w + 1] = 2;
		change++;
	}
	return (change);
}

void	draw_window_help(int run_height, int run_width, t_window *window)
{
	if (window -> map[run_height][run_width] == 'P')
		mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr,
			window -> player_ptr, (run_width * window -> tile_width),
			(run_height * window -> tile_height));
	if (window -> map[run_height][run_width] == 'C')
		mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr,
			window -> collect_ptr, (run_width * window -> tile_width),
			(run_height * window -> tile_height));
	if (window -> map[run_height][run_width] == 'E')
		mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr,
			window -> exit_ptr, (run_width * window -> tile_width),
			(run_height * window -> tile_height));
	if (window -> map[run_height][run_width] == '0')
		mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr,
			window -> floor_ptr, (run_width * window -> tile_width),
			(run_height * window -> tile_height));
	if (window -> map[run_height][run_width] == '1')
		mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr,
			window -> wall_ptr, (run_width * window -> tile_width),
			(run_height * window -> tile_height));
}
