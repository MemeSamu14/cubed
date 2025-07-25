/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/25 12:35:33 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


int	get_color(t_exec *exec, int ofset_y, int ofset_x)
{
	int	red;
	int	green;
	int	blue;

	// ofset_x = ((ofset_x * BLOCK) / WIDTH);
	ofset_x = (ofset_x % BLOCK);
	// printf("ofset_x: %d\n", ofset_x);
	red = exec->t.xpm_n[(ofset_y * exec->t.size_line) + ((ofset_x * exec->t.bpp) / 8) + 2];
	green = exec->t.xpm_n[(ofset_y * exec->t.size_line) + ((ofset_x * exec->t.bpp) / 8) + 1];
	blue = exec->t.xpm_n[(ofset_y * exec->t.size_line) + ((ofset_x * exec->t.bpp) / 8) + 0];
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

void	draw_vertical_line(t_exec *exec, int x, float distance)
{
	int		y;
	float	height;
	float	height_start;
	float	height_end;

	height = (HEIGHT / distance);
	height_start = (HEIGHT - height) / 2;
	height_end = height_start + height;
	y = height_start;
	float		ofset_y;
	float		y_pixel = 0;
	ofset_y = (BLOCK / height);
	
	while (y < height_end)
	{
		y_pixel += ofset_y;
		put_pixel(x, y, get_color(exec, y_pixel, x), exec);
		y++;
	}
}

float	module(float x1, float y1, float x2, float y2, t_player *p)
{
	float	distance;
	float	delta_x;
	float	delta_y;
	float	angle;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - p->angle;
	distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2)) * fabs(cos(angle));
	return (distance);
}

float	calculate_distance(t_exec *exec, float angle /* int *orientation */)
{
	float	view_sin;
	float	view_cos;
	float	view_x;
	float	view_x_tmp;
	float	view_y_tmp;
	float	view_y;
	float	distance;

	view_sin = sin(angle);
	view_cos = cos(angle);
	view_x = exec->p.x;
	view_y = exec->p.y;
	while (!touch(view_x, view_y, exec->map/* , view_x_tmp, view_y_tmp, orientation */))
	{
		view_x_tmp = view_x;
		view_y_tmp = view_y;
		view_x -= view_cos * 0.03;
		view_y -= view_sin * 0.03;
	}
	distance = module(exec->p.x, exec->p.y, view_x, view_y, &exec->p);
	return (distance);
}

void	tred_word(t_exec *exec)
{
	float	start;
	float	end;
	int		i;
	// int		orientation;

	i = 0;
	start = exec->p.angle - (PI / 6);
	end = exec->p.angle + (PI / 6);
	while (start < end)
	{
		// orientation
		draw_vertical_line(exec, i, calculate_distance(exec, start));
		
		
		start += PI / WIDTH / 3;
		i++;
	}
}

