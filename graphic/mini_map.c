/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:42:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/26 12:45:28 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	find_player(t_program *prg, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (prg->map[i])
	{
		j = 0;
		while (prg->map[i][j])
		{
			if (prg->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	set_images(t_program *prg, int i, int j, char id)
{
	if (id == '0')
		mlx_put_image_to_window(prg->mlx, prg->win, prg->floor_img, j * 16, i * 16);
	else if (id == '1')
		mlx_put_image_to_window(prg->mlx, prg->win, prg->wall_img, j * 16, i * 16);
	else if (id == 'P')
		mlx_put_image_to_window(prg->mlx, prg->win, prg->player_img, j * 16, i * 16);
	else if (id == ' ')
		mlx_put_image_to_window(prg->mlx, prg->win, prg->empty_img, j * 16, i * 16);
}

void	full_fill_black(t_program *prg)
{
	int	i;
	int	j;

	i = 0;
	while (i < 13)
	{
		j = 0;
		while (j < 19)
		{
			mlx_put_image_to_window(prg->mlx, prg->win, prg->empty_img, j * 16, i * 16);
			j++;
		}
		i++;
	}
}

void	skip_rows(t_program *prg, int *y, int *k, int *i)
{
	while (((*y + *k) < 0 || (*y + *k) > prg->row) && *k < 7)
	{
		(*k)++;
		(*i)++;
	}
}

void	skip_columns(int *x, int *z, int *j)
{
	if ((*x + *z) < 0 && *z + *x < 10) 
	{
		(*z)++;
		(*j)++;
	}
}


void	print_mini_map(t_program *prg, int x, int y)
{
	t_variables	a;

	a.i = 0;
	a.k = -7;
	while (++a.k < 7)
	{
		skip_rows(prg, &y, &a.k, &a.i);
		if (a.k < 7)
		{
			a.z = -9;
			a.j = 0;
			while (a.z < 10)
			{
				skip_columns(&x, &a.z, &a.j);
				if (x + a.z > 0 && x + a.z < prg->max_len)
					set_images(prg, a.i, a.j, prg->map[y + a.k][x + a.z]);
				else
					set_images(prg, a.i, a.j, ' ');
				a.z++;
				a.j++;
			}
		}
		a.i++;
	}
}

void	mini_map(t_program *prg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	find_player(prg, &x, &y);
	print_mini_map(prg, x, y);
}
