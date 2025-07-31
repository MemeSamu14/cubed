/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:12 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/31 16:07:33 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	shoot(int button, int x, int y, t_program *prg)
{
	(void)x;
	(void)y;
	(void)prg;
	if (button == 1)
		prg->exec.button = 1;
	return (0);
}

int	pointer(int x, int y, t_program *prg)
{
	(void)y;
	if (prg->exec.p.pos_x_mouse == -1)
		prg->exec.p.pos_x_mouse = x;
	if (prg->exec.p.pos_x_mouse < x - 15)
	{
		if (x > 10)
			prg->exec.p.angle += MOUSE_SENSIBILITY;
		prg->exec.p.pos_x_mouse = x;
	}
	if (prg->exec.p.pos_x_mouse > x + 15)
	{
		if (x < 1910)
			prg->exec.p.angle -= MOUSE_SENSIBILITY;
		prg->exec.p.pos_x_mouse = x;
	}
	return (0);
}

int	exec(t_program *prg)
{
	init_exec(prg);
	mlx_hook(prg->exec.win, 2, 1L << 0, key_controls, prg);
	mlx_hook(prg->exec.win, 3, 1L << 1, key_release, &prg->exec);
	mlx_hook(prg->exec.win, 17, 1L << 3, mouse_controls, prg);
	init_texture(prg);
	mlx_loop_hook(prg->exec.mlx, draw_loop, &prg->exec);
	mlx_loop(prg->exec.mlx);
	return (0);
}

void	find_player(char **map, float *x, float *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}
