/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:08:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/28 11:01:47 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_walls(t_program *prg)
{
	int	i;
	int	j;

	i = 0;
	while (prg->map[i])
	{
		j = 0;
		while (prg->map[i][j])
		{
			if (prg->map[i][j] == ' ')
			{
				if (open_walls(prg, i, j) == TRUE)
				{
					write(2, "Error\nOpen Walls or Invalid Map\n", 32);
					return (ERROR);
				}
			}
			j++;
		}
		i++;
	}
	return (CORRECT);
}

int	open_walls(t_program *prg, int i, int j)
{
	if ((i + 1) < (prg->row + 2) && prg->map[i + 1][j])
	{
		if (prg->map[i + 1][j] != ' ' && prg->map[i + 1][j] \
			!= '\0' && prg->map[i + 1][j] != '1')
			return (TRUE);
	}
	if ((i - 1) > 0 && prg->map[i - 1][j])
	{
		if (prg->map[i - 1][j] != ' ' && prg->map[i - 1][j] \
			!= '\0' && prg->map[i - 1][j] != '1')
			return (TRUE);
	}
	if ((j + 1) < (prg->max_len + 2) && prg->map[i][j + 1])
	{
		if (prg->map[i][j + 1] != ' ' && prg->map[i][j + 1] \
			!= '\0' && prg->map[i][j + 1] != '1')
			return (TRUE);
	}
	if ((j - 1) > 0 && prg->map[i][j - 1])
	{
		if (prg->map[i][j - 1] != ' ' && prg->map[i][j - 1] \
			!= '\0' && prg->map[i][j - 1] != '1')
			return (TRUE);
	}
	return (FALSE);
}

int	valid_map_char(t_program *prg)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (prg->map[i])
	{
		j = 0;
		while (prg->map[i][j])
		{
			if (is_valid_char(prg, i, j) == FALSE)
				return (write(2, "Error\nInvalid map chars\n", 24), ERROR);
			if (is_texture(prg, i, j) == TRUE)
				counter++;
			j++;
		}
		i++;
	}
	if (counter != 1)
	{
		write(2, "Error\nInvalid number of players\n", 32);
		return (ERROR);
	}
	return (CORRECT);
}

int	is_valid_char(t_program *prg, int i, int j)
{
	if (prg->map[i][j] != '1' && \
		prg->map[i][j] != '0' && \
		prg->map[i][j] != ' ' && \
		prg->map[i][j] != 'N' && \
		prg->map[i][j] != 'S' && \
		prg->map[i][j] != 'W' && \
		prg->map[i][j] != 'E' && \
		prg->map[i][j] != 'D' && \
		prg->map[i][j] != '\0')
		return (FALSE);
	return (TRUE);
}

int	is_texture(t_program *prg, int i, int j)
{
	if (prg->map[i][j] == 'N' || \
		prg->map[i][j] == 'S' || \
		prg->map[i][j] == 'W' || \
		prg->map[i][j] == 'E' )
		return (TRUE);
	return (FALSE);
}
