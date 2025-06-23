/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:26:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/23 16:36:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_textures(t_program *prg)
{
	if (check_textures_1(prg) == ERROR)
		return (ERROR);
	if (check_textures_2(prg) == ERROR)
		return (ERROR);
	return (CORRECT);
}

int	check_textures_1(t_program *prg)
{
	char	*file;

	if (prg->no)
	{
		file = ft_strjoin("texture/", prg->no);
		if (open_file(file) == ERROR)
			return (ERROR);
	}
	else
		return (write(2, "Error\nNO: no Texture\n", 21), ERROR);
	if (prg->so)
	{
		file = ft_strjoin("texture/", prg->so);
		if (open_file(file) == ERROR)
			return (ERROR);
	}
	else
		return (write(2, "Error\nSO: no Texture\n", 21), ERROR);
	return (CORRECT);
}

int	check_textures_2(t_program *prg)
{
	char	*file;

	if (prg->we)
	{
		file = ft_strjoin("texture/", prg->we);
		if (open_file(file) == ERROR)
			return (ERROR);
	}
	else
		return (write(2, "Error\nWE: no Texture\n", 21), ERROR);
	if (prg->ea)
	{
		file = ft_strjoin("texture/", prg->ea);
		if (open_file(file) == ERROR)
			return (ERROR);
	}
	else
		return (write(2, "Error\nEA: no Texture\n", 21), ERROR);
	return (CORRECT);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": file doesn't exist\n", 2);
		free(file);
		return (ERROR);
	}
	free(file);
	close(fd);
	return (CORRECT);
}
