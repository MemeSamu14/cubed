/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:45:23 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/21 12:19:51 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

#include "utils/utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

enum	controls {
	FALSE = 0,
	TRUE = 1,
	CORRECT = 2,
	WRONG = 3,
	ERROR = 4
};

typedef struct s_program
{
	char	**map;		// matrice mappa
	int		max_len;	// lunghezza massima delle righe della mappa
	int		start_map;	// indice per l'inizio della mappa
	char	*map_name;	// nome della mappa
	char	*buff;		// buffer next line
	char	*no;		// north texture
	char	*so;		// south texture
	char	*we;		// west texture
	char	*ea;		// east texture
	char	*f;			// floor color
	char	*c;			// celing color
	char	**code_f;	// codice di f splittato sulle virgole
	char	**code_c;	// codice di c splittato sulle virgole
}	t_program;

// main.c
void	init(t_program *prg, char *map_name);

// exec
	// exec.c

// parsing
	//parsing.c
	int		parsing(t_program *prg);
	int		check_exetension(t_program *prg);
	int		existing_check(t_program *prg);
	int		check_info_valid(t_program *prg);
	
	//	check_textures.c
	int		check_textures(t_program *prg);
	int		open_file(char *file);

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
	int		matrix_row(t_program *prg);
	void	skips_empty_lines(t_program *prg, int fd);
	

#endif