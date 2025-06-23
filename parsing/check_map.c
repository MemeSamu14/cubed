/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:27:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/23 16:12:15 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_map(t_program *prg)
{
	if (alloc_map(prg) == ERROR)
		return (ERROR);
	init_map(prg);
	if (valid_map_char(prg) == ERROR)
		return (ERROR);
	if (check_walls(prg) == ERROR)
		return (ERROR);
	return (CORRECT);
}

void	init_map(t_program *prg)
{
	int	fd;
	int	i;

	fd = open(prg->map_name, O_RDONLY);
	skippers(prg, fd);
	add_space_line(prg, 0);
	add_line(prg, 1);
	i = 2;
	while (1)
	{
		prg->buff = get_next_line_bonus(fd);
		if (prg->buff == NULL)
			break ;
		add_line(prg, i);
		i++;
	}
	add_space_line(prg, i);
	prg->map[i + 1] = NULL;
	close(fd);
}

void	add_line(t_program *prg, int i)
{
	int	j;

	j = 0;
	prg->map[i][j] = ' ';
	j++;
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
