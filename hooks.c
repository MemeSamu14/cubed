/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:53:45 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/25 18:35:45 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	right_movement(t_program *prg);
void	left_movement(t_program *prg);
void	up_movement(t_program *prg);
void	down_movement(t_program *prg);

int	mouse_controls(t_program *prg)
{
	free_all(prg);
	exit(1);
	return (0);
}

int	key_controls(int keysim, t_program *prg)
{
	if (keysim == XK_Escape)
	{
		free_all(prg);
		exit(1);
	}
	if (keysim == 100 || keysim == 65363)
		right_movement(prg);
	else if (keysim == 97 || keysim == 65361)
		left_movement(prg);
	else if (keysim == 119 || keysim == 65362)
		up_movement(prg);
	else if (keysim == 115 || keysim == 65364)
		down_movement(prg);
	return (0);
}

void	right_movement(t_program *prg)
{
	int	x;
	int	y;

	printf("D premuta\n");
	x = 0;
	y = 0;
	find_player(prg, &x, &y);
	if (prg->map[y][x + 1] != '1')
	{
		prg->map[y][x + 1] = 'P';
		prg->map[y][x] = '0';
	}
}

void	left_movement(t_program *prg)
{
	int	x;
	int	y;

	printf("A premuta\n");
	x = 0;
	y = 0;
	find_player(prg, &x, &y);
	if (prg->map[y][x - 1] != '1')
	{
		prg->map[y][x - 1] = 'P';
		prg->map[y][x] = '0';
	}
}

void	up_movement(t_program *prg)
{
	int	x;
	int	y;

	printf("W premuta\n");
	x = 0;
	y = 0;
	find_player(prg, &x, &y);
	if (prg->map[y - 1][x] != '1')
	{
		prg->map[y - 1][x] = 'P';
		prg->map[y][x] = '0';
	}
}

void	down_movement(t_program *prg)
{
	int	x;
	int	y;

	printf("S premuta\n");
	x = 0;
	y = 0;
	find_player(prg, &x, &y);
	if (prg->map[y + 1][x] != '1')
	{
		prg->map[y + 1][x] = 'P';
		prg->map[y][x] = '0';
	}
}
