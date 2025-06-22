/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:27:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/21 12:20:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_map(t_program *prg)
{
		
	// conto righe
	// matrx len
	// 
	return (CORRECT);
}

int	matrix_row(t_program *prg)
{
	int	fd;
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	fd = open(prg->map_name, O_RDONLY);
	while (i < prg->start_map)
	{
		prg->buff = get_next_line_bonus(fd);
		free(prg->buff);
		i++;
	}
	skips_empty_lines(prg, fd);
	while (1)
	{
		prg->buff = get_next_line_bonus(fd);
		counter++;
		free(prg->buff);
	}
	close(fd);
	return (counter);
}

void	skips_empty_lines(t_program *prg, int fd)
{
	int	i;

	while (1)
	{
		prg->buff = get_next_line_bonus(fd);
		i = 0;
		while (prg->buff[i] && (prg->buff[i] == ' ' || prg->buff[i] == '	'))
			i++;
		if (prg->buff[i] != '\0' && prg->buff[i] != '\n')
			break ;
		free(prg->buff);
	}
}
