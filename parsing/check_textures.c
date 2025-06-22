/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:26:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/20 18:27:33 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_textures(t_program *prg)
{
	char	*file;

	file = ft_strjoin("texture/", prg->no);
	if (open_file(file) == ERROR)
		return (ERROR);
	file = ft_strjoin("texture/", prg->so);
	if (open_file(file) == ERROR)
		return (ERROR);
	file = ft_strjoin("texture/", prg->we);
	if (open_file(file) == ERROR)
		return (ERROR);
	file = ft_strjoin("texture/", prg->ea);
	if (open_file(file) == ERROR)
		return (ERROR);
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
