/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:06:05 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 17:18:25 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	rotation_mouse(t_player *p)
{
	if (p->pos_x_mouse >= 1910)
		p->angle += MOUSE_SENSIBILITY;
	if (p->pos_x_mouse <= 10)
		p->angle -= MOUSE_SENSIBILITY;
}

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

void	vertical_move(t_player *p, float sin_a, float cos_a, char **map)
{
	if (p->move_up == TRUE)
	{
		if (touch(p->x - (cos_a * (SPEED * 10)), p->y \
		- (sin_a * (SPEED * 10)), map) == FALSE)
		{
			p->x -= cos_a * SPEED;
			p->y -= sin_a * SPEED;
		}
	}
	if (p->move_down == TRUE)
	{
		if (touch(p->x + (cos_a * (SPEED * 10)), p->y \
		+ (sin_a * (SPEED * 10)), map) == FALSE)
		{
			p->x += cos_a * SPEED;
			p->y += sin_a * SPEED;
		}
	}
}

void	orizzontal_move(t_player *p, float sin_a, float cos_a, char **map)
{
	if (p->move_right == TRUE)
	{
		if (touch(p->x + (sin_a * (SPEED * 3)), p->y \
		- (cos_a * (SPEED * 3)), map) == FALSE)
		{
			p->x += sin_a * SPEED;
			p->y -= cos_a * SPEED;
		}
	}
	if (p->move_left == TRUE)
	{
		if (touch(p->x - (sin_a * (SPEED * 3)), p->y \
		+ (cos_a * (SPEED * 3)), map) == FALSE)
		{
			p->x -= sin_a * SPEED;
			p->y += cos_a * SPEED;
		}
	}
}

void	movement(t_player *p, char **map)
{
	float	sin_a;
	float	cos_a;

	sin_a = sin(p->angle);
	cos_a = cos(p->angle);
	vertical_move(p, sin_a, cos_a, map);
	orizzontal_move(p, sin_a, cos_a, map);
}
