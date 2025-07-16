/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/16 16:07:25 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_vertical_line(t_exec *exec, int x, float distance)
{
	int		i;
	float	height;
	float	height_start;
	float	height_end;

	height = (HEIGHT / distance);
	height_start = (HEIGHT - height) / 2;
	height_end = height_start + height;
	i = height_start;
	while (i < height_end)
	{
		put_pixel(x, i, 0xFF0000, exec);
		i++;
	}
}

float	module(float x1, float y1, float x2, float y2, t_player *p)
{
	float	distance;
	float	delta_x;
	float	delta_y;
	// float	angle;
	(void )p;
	delta_x = (x2 /* / BLOCK */) - x1;
	delta_y =(y2 /* / BLOCK */)- y1;
	// angle = atan2(delta_x, delta_y) - p->angle;
	distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2)) /* * cos(angle) */;
	return (distance);
}

float	calculate_distance(t_exec *exec, float angle)
{
	float	view_sin;
	float	view_cos;
	float	view_x;
	float	view_y;
	float	distance;

	view_sin = sin(angle);
	view_cos = cos(angle);
	view_x = exec->p.x;
	view_y = exec->p.y;
	while (!touch(view_x, view_y, exec->map))
	{
		view_x -= view_cos * 0.01;
		view_y -= view_sin * 0.01;
	}
	distance = module(exec->p.x, exec->p.y, view_x, view_y, &exec->p);
	return (distance);
}
