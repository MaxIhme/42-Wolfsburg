/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:31:13 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/14 11:40:22 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include "../minilibx_opengl_20191021/mlx.h"

# define PATH_PLAYER "img/Player64x64.xpm"
# define PATH_ITEM "img/Collect64x64.xpm"
# define PATH_EXIT "img/Exit64x64.xpm"
# define PATH_WALL "img/Wall64x64.xpm"
# define PATH_FLOOR "img/Floor64x64.xpm"
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define EXIT_BUTTON 17
# define ERR_WRONG_CHAR 1
# define ERR_BORDER 2
# define ERR_P_E_C 3
# define ERR_RECTANGULAR 4
# define ERR_NO_SOLUTION 5
# define ERR_WRONG_ARGUMENT 6
# define ERR_NOT_BER_FILE 7
# define ERR_ALLOC 8
# define ERR_ALLOC_FREE_MEM 9
# define ERR_WRONG_FILE 10

typedef struct s_window
{
	int		map_width;
	int		map_height;
	char	**map;
	int		tile_width;
	int		tile_height;
	int		player_pos_x;
	int		player_pos_y;
	int		count_c_e;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_ptr;
	void	*collect_ptr;
	void	*wall_ptr;
	void	*exit_ptr;
	void	*floor_ptr;
}	t_window;

//-------------------------------- so_long.c

void	error(int err_code, t_window *window);
void	error2(int err_code, t_window *window);
void	free_mem(t_window *window);
int		close_game(t_window *window);
int		main(int argc, char **argv);

//-------------------------------- checks.c

int		count_lines(int fd);
void	init_map(char *path, t_window *window);
void	check_char(t_window *window);
void	count_width(t_window *window);
int		check_map(t_window *window);

//-------------------------------- checks_2.c

void	remove_new_line(t_window *window);
int		check_border_horizontal(char *line);
void	check_border(t_window *window);
void	check_p_e_c(t_window *window);
void	check_rectangularity(t_window *window);

//-------------------------------- checks_path.c

int		**copy_map(t_window *window, int **map_copy);
void	show_copy_map(t_window *window, int **map_copy);
int		substitute_zeros(int **map_copy, int run_height,
			int run_width, t_window *window);
int		scan_map_for_twos(t_window *window, int **map_copy);
void	check_path(t_window *window);

//-------------------------------- draw_window.c

void	draw_window(t_window *window);
int		is_c_in_map(t_window *window);

//-------------------------------- move_player.c

int		key_event(int key, t_window *window);
void	move_down(t_window *window);
void	move_up(t_window *window);
void	move_right(t_window *window);
void	move_left(t_window *window);

//-------------------------------- additional.c

void	xpm_file_to_image(t_window *window);
void	open_file_count_lines(char *path, t_window *window);
void	map_copy_help(int h, int w, int **map_copy, t_window *window);
int		substitute_zeros_help(int h, int w, int change, int **map_copy);
void	draw_window_help(int run_height, int run_width, t_window *window);

#endif
