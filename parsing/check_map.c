/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:27:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/31 15:48:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_map(t_program *prg)
{
	if (alloc_map(prg) == ERROR)
		return (ERROR);
	if (init_map(prg) == ERROR)
		return (ERROR);
	if (valid_map_char(prg) == ERROR)
		return (ERROR);
	if (check_walls(prg) == ERROR)
		return (ERROR);
	return (CORRECT);
}

int	init_map(t_program *prg)
{
	int	fd;
	int	i;

	fd = open(prg->map_name, O_RDONLY);
	skippers(prg, fd);
	add_space_line(prg, 0);
	if (add_line(prg, 1) == ERROR)
		return (ERROR);
	i = 2;
	while (1)
	{
		prg->buff = get_next_line_bonus(fd);
		if (prg->buff == NULL)
			break ;
		if (add_line(prg, i) == ERROR)
			return (ERROR);
		i++;
	}
	add_space_line(prg, i);
	prg->map[i + 1] = NULL;
	close(fd);
	return (CORRECT);
}

int	add_line(t_program *prg, int i)
{
	int	j;

	j = 0;
	prg->map[i][j] = ' ';
	j++;
	if (prg->buff == NULL)
		return (ERROR);
	while (prg->buff[j - 1] && prg->buff[j - 1] != '\n')
	{
		prg->map[i][j] = prg->buff[j - 1];
		j++;
	}
	while (j < (prg->max_len + 1))
	{
		prg->map[i][j] = ' ';
		j++;
	}
	prg->map[i][j] = '\0';
	free(prg->buff);
	return (CORRECT);
}

void	add_space_line(t_program *prg, int i)
{
	int	j;

	j = 0;
	while (j < (prg->max_len + 1))
	{
		prg->map[i][j] = ' ';
		j++;
	}
	prg->map[i][j] = '\0';
}
