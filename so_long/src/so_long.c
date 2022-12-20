/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:29:31 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/14 16:26:55 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int err_code, t_window *window)
{
	write(2, "Error\n", 6);
	if (err_code == ERR_WRONG_CHAR)
	{
		ft_printf("Wrong character in map\n");
		free_mem(window);
	}
	if (err_code == ERR_BORDER)
	{
		ft_printf("Wrong border\n");
		free_mem(window);
	}
	if (err_code == ERR_P_E_C)
	{
		ft_printf("Only one P, one E and at least one C allowed\n");
		free_mem(window);
	}
	if (err_code == ERR_RECTANGULAR)
	{
		ft_printf("Map not rectangular\n");
		free_mem(window);
	}
	error2(err_code, window);
	exit(1);
}

void	error2(int err_code, t_window *window)
{
	if (err_code == ERR_NO_SOLUTION)
	{
		ft_printf("no solution found\n");
		free_mem(window);
	}
	if (err_code == ERR_WRONG_ARGUMENT)
		ft_printf("Please give me a map as an argument\n");
	if (err_code == ERR_NOT_BER_FILE)
		ft_printf("Please give me a .ber File as an argument\n");
	if (err_code == ERR_ALLOC)
		ft_printf("Problem with memory allocation\n");
	if (err_code == ERR_ALLOC_FREE_MEM)
	{
		ft_printf("Problem with memory allocation\n");
		free_mem(window);
	}
	if (err_code == ERR_WRONG_FILE)
		ft_printf("Can't open File\n");
}

void	free_mem(t_window *window)
{
	int	i;

	i = 0;
	while (i < window -> map_height)
	{
		free(window -> map[i]);
		i++;
	}
	free(window -> map);
}

int	close_game(t_window *window)
{
	free_mem(window);
	mlx_clear_window(window -> mlx_ptr, window -> win_ptr);
	mlx_destroy_image(window -> mlx_ptr, window -> player_ptr);
	mlx_destroy_image(window -> mlx_ptr, window -> collect_ptr);
	mlx_destroy_image(window -> mlx_ptr, window -> exit_ptr);
	mlx_destroy_image(window -> mlx_ptr, window -> wall_ptr);
	mlx_destroy_image(window -> mlx_ptr, window -> floor_ptr);
	mlx_destroy_window(window -> mlx_ptr, window -> win_ptr);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*path;
	t_window	window;

	path = argv[1];
	if (argc == 2)
	{
		init_map(path, &window);
		remove_new_line(&window);
		check_map(&window);
		window.mlx_ptr = mlx_init();
		xpm_file_to_image(&window);
		draw_window(&window);
		mlx_key_hook(window.win_ptr, key_event, &window);
		mlx_hook(window.win_ptr, EXIT_BUTTON, (int)0, close_game, &window);
		mlx_loop(window.mlx_ptr);
	}
	else
		error(ERR_WRONG_ARGUMENT, &window);
	return (0);
}
