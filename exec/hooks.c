/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:53:45 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/25 17:21:13 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	mouse_controls(t_exec *exec)
{
	free_exec(exec);
	exit(1);
	return (0);
}

int	key_controls(int keysim, t_exec *exec)
{
	if (keysim == XK_Escape)
	{
		free_exec(exec);
		exit(1);
	}
	if (keysim == 100)
		exec->p.move_right = TRUE;
	if (keysim == 97)
		exec->p.move_left = TRUE;
	if (keysim == 119)
		exec->p.move_up = TRUE;
	if (keysim == 115)
		exec->p.move_down = TRUE;
	if (keysim == 65363)
		exec->p.rotate_right = TRUE;
	if (keysim == 65361)
		exec->p.rotate_left = TRUE;
	return (0);
}

int key_release(int keycode, t_exec *exec)
{
	if (keycode == 100)
		exec->p.move_right = FALSE;
	if (keycode == 97)
		exec->p.move_left = FALSE;
	if (keycode == 119)
		exec->p.move_up = FALSE;
	if (keycode == 115)
		exec->p.move_down = FALSE;
	if (keycode == 65363)
		exec->p.rotate_right = FALSE;
	if (keycode == 65361)
		exec->p.rotate_left = FALSE;
	return (0);
}
