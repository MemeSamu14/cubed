/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/26 12:00:40 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	moves(void *arg)
{
	t_program	*prg;
	int			i;
	int			j;

	prg = (t_program *)arg;
	i = 0;
	j = 0;
	mini_map(prg);
	return (0);
}

int		exec(t_program *prg)
{
	
	prg->mlx = mlx_init();
	prg->win = mlx_new_window(prg->mlx, 720, 320, "Cubed");
	if (create_images(prg) == ERROR)
		return (ERROR);
	mlx_hook(prg->win, 2, 1L << 0, key_controls, prg);
	mlx_hook(prg->win, 17, 1L << 3, mouse_controls, prg);
	if (graphic(prg) == ERROR)
		return (ERROR);
	mlx_loop_hook(prg->mlx, moves, prg);
	mlx_loop(prg->mlx);

	return (CORRECT);
}
