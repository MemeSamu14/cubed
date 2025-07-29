/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:53:45 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 12:06:23 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	mouse_controls(t_program *prg)
{
	free_all(prg);
	exit(1);
	return (0);
}

void	check_nord_sud(t_program *prg, int *i)
{
	if (prg->exec.p.angle > (PI / 2 - PI / 6) \
	&& prg->exec.p.angle < (PI / 2 + PI / 6))
	{
		while (++(*i) < 3)
		{
			if (prg->map[(int)prg->exec.p.x][(int)prg->exec.p.y - *i] == 'D')
			{
				prg->map[(int)prg->exec.p.x][(int)prg->exec.p.y - *i] = '0';
				break ;
			}
		}
	}
	if (prg->exec.p.angle > (3 * PI / 2 - PI / 6) \
	&& prg->exec.p.angle < (3 * PI / 2 + PI / 6))
	{
		while (++(*i) < 3)
		{
			if (prg->map[(int)prg->exec.p.x][(int)prg->exec.p.y + *i] == 'D')
			{
				prg->map[(int)prg->exec.p.x][(int)prg->exec.p.y + *i] = '0';
				break ;
			}
		}
	}
}
void	check_ovest_est(t_program *prg, int *i)
{
	if ((prg->exec.p.angle >= (2 * PI - PI / 6) \
	&& prg->exec.p.angle <= (2 * PI)) || \
	(prg->exec.p.angle >= 0 && prg->exec.p.angle <= PI / 6))
	{
		while (++(*i) < 3)
		{
			if (prg->map[(int)prg->exec.p.x - *i][(int)prg->exec.p.y] == 'D')
			{
				prg->map[(int)prg->exec.p.x - *i][(int)prg->exec.p.y] = '0';
				break ;
			}
		}
	}
	if ((prg->exec.p.angle >= (PI - PI / 6) \
	&& prg->exec.p.angle <= (PI + PI / 6)))
	{
		while (++(*i) < 3)
		{
			if (prg->map[(int)prg->exec.p.x + *i][(int)prg->exec.p.y] == 'D')
			{
				prg->map[(int)prg->exec.p.x + *i][(int)prg->exec.p.y] = '0';
				break ;
			}
		}
	}
}

void	open_door(t_program *prg)
{
	int	i;

	i = -1;
	check_nord_sud(prg, &i);
	check_ovest_est(prg, &i);
}

int	key_controls(int keysim, t_program *prg)
{
	if (keysim == XK_Escape)
	{
		free_all(prg);
		exit(1);
	}
	if (keysim == 100)
		prg->exec.p.move_right = TRUE;
	if (keysim == 97)
		prg->exec.p.move_left = TRUE;
	if (keysim == 119)
		prg->exec.p.move_up = TRUE;
	if (keysim == 115)
		prg->exec.p.move_down = TRUE;
	if (keysim == 65363)
		prg->exec.p.rotate_right = TRUE;
	if (keysim == 65361)
		prg->exec.p.rotate_left = TRUE;
	if (keysim == 101)
		open_door(prg);
	return (0);
}

int	key_release(int keycode, t_exec *exec)
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
