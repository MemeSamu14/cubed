/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:45:23 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/26 12:44:04 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

#include "utils/utils.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

enum	e_controls {
	FALSE = 0,
	TRUE = 1,
	CORRECT = 2,
	WRONG = 3,
	ERROR = 4
};


typedef struct	s_variables {
	int		k;
	int		z;
	int		i;
	int		j;
}	t_variables;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_program
{
	char		**map;		// matrice mappa
	int			max_len;	// lunghezza massima delle righe della mappa
	int			start_map;	// indice per l'inizio della mappa
	int			row;	// numero di righe
	char		*map_name;	// nome della mappa
	char		*buff;		// buffer next line
	char		*no;		// north texture
	char		*so;		// south texture
	char		*we;		// west texture
	char		*ea;		// east texture
	char		*f;			// floor color
	char		*c;			// celing color
	char		**code_f;	// codice di f splittato sulle virgole
	char		**code_c;	// codice di c splittato sulle virgole

	// s_graphic
	void	*mlx;
	void	*win;

	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*empty_img;
	int		height;
	int		width;
	char	orientation;

	t_data	img_bg;

}	t_program;

// exec
	// exec.c
	int		exec(t_program *prg);
	int	moves(void *arg);

// main.c
void	init(t_program *prg, char *map_name);


// parsing
	//parsing.c
	int		parsing(t_program *prg);
	int		check_exetension(t_program *prg);
	int		existing_check(t_program *prg);
	int		check_info_valid(t_program *prg);
	void	change_player_id(t_program *prg);
	//	check_textures.c
	int		check_textures(t_program *prg);
	int		open_file(char *file);
	int		check_textures_1(t_program *prg);
	int		check_textures_2(t_program *prg);

	//	check_colors.c
	int	check_colors(t_program *prg);
	int	color_code_limits(t_program *prg);
	int	check_code(t_program *prg);
	int	check_numbers(t_program *prg);
	int	check_char(t_program *prg);

	//	check_info.c
	int		check_info(t_program *prg);
	int		find_id(t_program *prg);
	int		check_id(t_program *prg, char *buff);
	int		set_id(t_program *prg, char *id, char *buff);
	void	set_id_num(t_program *prg, char *id, char *buff);
	
	//	matrix_utils.c
	void	print_matrix(char **matrix);
	int		matrix_len(char **matrix);
	void	free_matrix(char **matrix);
	void	free_matrix_len(char **matrix, int len);
	char	**matrix_dup(char **old_mtx);

	//	check_map
	int		check_map(t_program *prg);
	void	init_map(t_program *prg);
	void	add_line(t_program *prg, int i);
	void	add_space_line(t_program *prg, int i);
	//	check_map_2
	int		alloc_map(t_program *prg);
	int		matrix_row(t_program *prg);
	void	skippers(t_program *prg, int fd);
	void	skips_empty_lines(t_program *prg, int fd);
	//	check_map_3
	int		check_walls(t_program *prg);
	int		open_walls(t_program *prg, int i, int j);
	int		valid_map_char(t_program *prg);
	int		is_valid_char(t_program *prg, int i, int j);
	int		is_texture(t_program *prg, int i, int j);

	//	close.c
	void	free_all(t_program *prg);
	void	free_parsing(t_program *prg);

//	graphic
	//	color_bg.c
	void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
	int	color_bg(t_program *prg);	
	//	graphic.c
	int	graphic(t_program *prg);
	//	minimap.c
	void	mini_map(t_program *prg);
	void	print_images(t_program *prg);
	void	find_player(t_program *prg, int *x, int *y);
	void	full_fill_black(t_program *prg);
	//create_images.c
	int	create_images(t_program *prg);


//	hooks.c
int	mouse_controls(t_program *prg);
int	key_controls(int keysim, t_program *prg);




#endif