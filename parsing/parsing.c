/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:34 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/23 16:33:14 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	parsing(t_program *prg)
{
	if (check_exetension(prg) == ERROR)
		return (ERROR);
	if (existing_check(prg) == ERROR)
		return (ERROR);
	if (check_info(prg) == ERROR)
		return (ERROR);
	if (check_info_valid(prg) == ERROR)
	{
		free_parsing(prg);
		return (ERROR);
	}
	if (check_map(prg) == ERROR)
	{
		free_parsing(prg);
		return (ERROR);
	}
	print_matrix(prg->map);
	return (0);
}

int	check_exetension(t_program *prg)
{
	int	index;

	index = ft_strlen(prg->map_name) - 1;
	if (prg->map_name[index] == 'b' && \
		prg->map_name[index - 1] && \
		prg->map_name[index - 1] == 'u' && \
		prg->map_name[index - 2] && \
		prg->map_name[index - 2] == 'c' && \
		prg->map_name[index - 3] && \
		prg->map_name[index - 3] == '.')
		return (CORRECT);
	else
		write(2, "Error\nWrong extension file\n", 27);
	return (ERROR);
}

int	existing_check(t_program *prg)
{
	int	fd;

	fd = open(prg->map_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFile doesn't exist\n", 25);
		return (ERROR);
	}
	close(fd);
	return (CORRECT);
}

int	check_info_valid(t_program *prg)
{
	if (check_textures(prg) == ERROR)
		return (ERROR);
	if (check_colors(prg) == ERROR)
		return (ERROR);
	return (0);
}
