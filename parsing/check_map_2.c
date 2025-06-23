/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:11:20 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/23 16:36:13 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	alloc_map(t_program *prg)
{
	int	i;

	prg->max_len = 0;
	i = 0;
	prg->row = matrix_row(prg);
	if (prg->row == 0)
	{
		write(2, "Error\nInexistent map\n", 21);
		return (ERROR);
	}
	prg->map = (char **)malloc(sizeof(char *) * (prg->row + 3));
	if (prg->map == NULL)
		return (ERROR);
	while (i < (prg->row + 2))
	{
		prg->map[i] = (char *)malloc(sizeof(char) * (prg->max_len + 3));
		if (prg->map[i] == NULL)
			return (ERROR);
		i++;
	}
	return (CORRECT);
}

//conta il numero di righe
int	matrix_row(t_program *prg)
{
	int	fd;
	int	counter;

	fd = open(prg->map_name, O_RDONLY);
	skippers(prg, fd);
	free(prg->buff);
	counter = 1;
	while (1)
	{
		prg->buff = get_next_line_bonus(fd);
		if (prg->buff == NULL)
			break ;
		counter++;
		if ((int)ft_strlen(prg->buff) > prg->max_len)
			prg->max_len = ft_strlen(prg->buff);
		free(prg->buff);
	}
	close(fd);
	return (counter);
}

void	skippers(t_program *prg, int fd)
{
	int	i;

	i = 0;
	while (i < prg->start_map)
	{
		prg->buff = get_next_line_bonus(fd);
		free(prg->buff);
		i++;
	}
	skips_empty_lines(prg, fd);
}

void	skips_empty_lines(t_program *prg, int fd)
{
	int	i;

	prg->buff = get_next_line_bonus(fd);
	if (prg->buff == NULL)
		return ;
	free(prg->buff);
	while (1)
	{
		prg->buff = get_next_line_bonus(fd);
		if (prg->buff == NULL)
			break ;
		i = 0;
		while (prg->buff[i] && (prg->buff[i] == ' ' || prg->buff[i] == '	'))
			i++;
		if (prg->buff[i] != '\0' && prg->buff[i] != '\n')
			break ;
		free(prg->buff);
	}
}
