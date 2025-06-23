/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:24:35 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/23 16:38:44 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_colors(t_program *prg)
{
	if (check_char(prg) == ERROR)
		return (ERROR);
	if (check_numbers(prg) == ERROR)
		return (ERROR);
	if (check_code(prg) == ERROR)
		return (ERROR);
	return (CORRECT);
}

int	color_code_limits(t_program *prg)
{
	int	i;
	int	value;

	i = 0;
	while (prg->code_f[i])
	{
		value = ft_atoi(prg->code_f[i]);
		if (value < 0 || value > 255)
			return (ERROR);
		i++;
	}
	i = 0;
	while (prg->code_c[i])
	{
		value = ft_atoi(prg->code_c[i]);
		if (value < 0 || value > 255)
			return (ERROR);
		i++;
	}
	return (CORRECT);
}

int	check_code(t_program *prg)
{
	if (color_code_limits(prg) == ERROR)
	{
		free_matrix(prg->code_f);
		free_matrix(prg->code_c);
		write(2, "Error\nInvalid color numbers\n", 28);
		return (ERROR);
	}
	return (CORRECT);
}

int	check_numbers(t_program *prg)
{
	prg->code_f = ft_split(prg->f, ',');
	prg->code_c = ft_split(prg->c, ',');
	if (matrix_len(prg->code_f) != 3 || matrix_len(prg->code_c) != 3)
	{
		free_matrix(prg->code_c);
		free_matrix(prg->code_f);
		write(2, "Error\nIvalid Color code\n", 24);
		return (ERROR);
	}
	return (CORRECT);
}

int	check_char(t_program *prg)
{
	int		i;

	i = -1;
	if (prg->f)
	{
		while (prg->f && prg->f[++i])
		{
			if ((prg->f[i] < '0' || prg->f[i] > '9') && prg->f[i] != ',')
				return (write(2, "Error\nF: Ivalid color code\n", 27), ERROR);
		}
	}
	else
		return (write(2, "Error\nF: Ivalid color code\n", 27), ERROR);
	i = -1;
	if (prg->c)
	{
		while (prg->c && prg->c[++i])
		{
			if ((prg->c[i] < '0' || prg->c[i] > '9') && prg->c[i] != ',')
				return (write(2, "Error\nC: Ivalid color code\n", 27), ERROR);
		}
	}
	else
		return (write(2, "Error\nC: Ivalid color code\n", 27), ERROR);
	return (CORRECT);
}
