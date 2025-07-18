/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:45:23 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/16 17:36:38 by sfiorini         ###   ########.fr       */
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

#define WIDTH 1920
#define HEIGHT 1080
#define BLOCK 32
#define PI 3.1415926535
#define SPEED 0.5
#define ANGLE_SPEED 0.1

enum	e_controls {
	FALSE = 0,
	TRUE = 1,
	CORRECT = 2,
	WRONG = 3,
	ERROR = 4
};

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
	
}	t_player;


typedef struct s_exec
{
	char		**map;		// matrice mappa
	// s_graphic
	void	*mlx;
	void	*win;
	void	*img;

	char *data;
	int bpp;
	int size_line;
	int endian;
	t_player p;
}	t_exec;


int		mouse_controls(t_exec *prg);
void	free_exec(t_exec *exec);
int		key_controls(int keysim, t_exec *exec);
int		key_release(int keycode, t_exec *exec);
void	free_exec(t_exec *exec);


int		draw_loop(t_exec *exec);


void	print_matrix(char **matrix);
int		matrix_len(char **matrix);
void	free_matrix(char **matrix);
void	free_matrix_len(char **matrix, int len);
char	**matrix_dup(char **old_mtx);
void	movement(t_player *movement);
void	rotation(t_player *movement);
float	calculate_distance(t_exec *exec, float angle);
int		touch(float x, float y, char **map);
void	draw_vertical_line(t_exec *exec, int x, float distance);
void	put_pixel(int x, int y, int color, t_exec *exec);
void	tred_word(t_exec *exec);

#endif