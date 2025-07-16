/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:06:05 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/16 11:12:39 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	rotation(t_player *p)
{
	if (p->rotate_left == TRUE)
		p->angle -= ANGLE_SPEED;
	if (p->rotate_right == TRUE)
        p->angle += ANGLE_SPEED;
	if (p->angle > 2 * PI)
		p->angle = 0;
	if (p->angle < 0)
		p->angle = 2 * PI;
}

void	movement(t_player *p)
{
	float	sin_a;
	float	cos_a;

	sin_a = sin(p->angle);
	cos_a = cos(p->angle);
	if (p->move_up == TRUE)
	{
		p->x -= cos_a * SPEED;
		p->y -= sin_a * SPEED;
	}
	if (p->move_down == TRUE)
	{
		p->x += cos_a * SPEED;
		p->y += sin_a * SPEED;
	}
	if (p->move_right == TRUE)
	{
		p->y -= cos_a * SPEED;
		p->x += sin_a * SPEED;
	}
	if (p->move_left == TRUE)
	{
		p->y += cos_a * SPEED;
		p->x -= sin_a * SPEED;
	}
}
