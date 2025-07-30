/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:45:23 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/30 12:28:41 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "utils/utils.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1920
# define HEIGHT 1080
# define BLOCK 256
# define PI 3.1415926535
# define SPEED 0.05
# define ANGLE_SPEED 0.025
# define MOUSE_SENSIBILITY 0.05

enum	e_controls
{
	FALSE = 0,
	TRUE = 1,
	CORRECT = 2,
	WRONG = 3,
	ERROR = 4
};

enum	e_orient
{
	NORD = 0,
	SUD = 1,
	EST = 2,
	OVEST = 3,
};

typedef struct s_variables
{
	int		k;
	int		z;
	int		i;
	int		j;
}	t_variables;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
	int		pos_x_mouse;
}	t_player;

typedef struct s_texture
{
	void	*img_n;
	char	*xpm_n;
	void	*img_s;
	char	*xpm_s;
	void	*img_e;
	char	*xpm_e;
	void	*img_o;
	void	*img_o1;
	void	*img_o2;
	char	*xpm_o;
	char	*xpm_o1;
	char	*xpm_o2;
	void	*img_d;
	char	*xpm_d;
	void	*img_shotgun;
	char	*xpm_shotgun;
	void	*img_shoot;
	char	*xpm_shoot;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_exec
{
	char		**map;		// matrice mappa
	void		*mlx;
	void		*win;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	float		view_x;
	float		view_y;
	int			orientation;
	int			color_c;
	int			color_f;
	int			map_len;
	int			button;
	t_texture	t;
	t_player	p;
}	t_exec;

typedef struct s_program
{
	char		**map;		// matrice mappa
	int			max_len;	// lunghezza massima delle righe della mappa
	int			start_map;	// indice per l'inizio della mappa
	int			row;		// numero di righe
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
	char		orientation;
	t_exec		exec;
}	t_program;

// main.c
void	init(t_program *prg, char *map_name);
void	init_color(t_program *prg);
void	init_texture(t_program *prg);
void	create_images(t_program *prg, int *width, int *height);
void	set_texture_path(t_program *prg);
void	create_dataset(t_program *prg);
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
int		check_colors(t_program *prg);
int		color_code_limits(t_program *prg);
int		check_code(t_program *prg);
int		check_numbers(t_program *prg);
int		check_char(t_program *prg);
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
int		init_map(t_program *prg);
int		add_line(t_program *prg, int i);
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
	//	exec
		// 3d_calculations.c
void	correct_color(t_exec *exec, char **img_data, \
	float *ofset_x, int status);
int		get_color(t_exec *exec, int ofset_y, float ofset_x, int status);
void	draw_vertical_line(t_exec *exec, int x, float distance, int status);
float	module(t_exec *exec);
float	calculate_distance(t_exec *exec, float angle);
void	tred_word(t_exec *exec, int status);
		// close.c
void	free_exec(t_exec *exec);
		// draw.c
int		draw_player(t_exec *exec, int v);
void	draw_bg(t_exec *exec, int color_f, int color_c);
void	draw_animation(t_exec *exec);
int		draw_map(t_exec *exec);
void	draw_shotgun(t_exec *exec);
		// draw_loop
void	if_animation(t_exec *exec, int *j);
int		draw_loop(t_exec *exec);
		// draw_utils
void	put_pixel(int x, int y, int color, t_exec *exec);
void	draw_square(float x, float y, int color, t_exec *exec);
int		touch_orient(t_exec *exec, int x_prev, int y_prev);
int		touch(float x, float y, char **map);
void	draw_line(t_exec *exec, float x, float y, float angle);
		// exec.c
int		exec(t_program *prg);
void	init_exec(t_program *prg);
void	init_texture(t_program *prg);
void	init_player(t_program *prg);
void	find_player(char **map, float *x, float *y);
		// hooks.c
int		mouse_controls(t_program *prg);
int		key_controls(int keysim, t_program *prg);
int		key_release(int keycode, t_exec *exec);
		// movements
void	rotation(t_player *p);
void	movement(t_player *p, char **map);
void	rotation_mouse(t_player *p);

#endif