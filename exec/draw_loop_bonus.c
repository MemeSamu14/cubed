/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:41 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 17:38:26 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	draw_loop(t_exec *exec)
{
	static int	i = 0;
	static int	j = 15;

	if (i == 300)
		i = 0;
	draw_bg(exec, exec->color_f, exec->color_c);
	movement(&exec->p, exec->map);
	rotation(&exec->p);
	rotation_mouse(&exec->p);
	tred_word(exec, i % 30);
	draw_map(exec);
	draw_player(exec, TRUE);
	if_animation(exec, &j);
	draw_shotgun(exec);
	mlx_put_image_to_window(exec->mlx, exec->win, exec->img, 0, 0);
	i++;
	return (0);
}

void	if_animation(t_exec *exec, int *j)
{
	if (exec->button == 1)
	{
		exec->button = 0;
		*j = 0;
	}
	if (*j < 15)
	{
		draw_animation(exec);
		(*j)++;
	}
}
