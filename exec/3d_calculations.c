/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/31 16:11:31 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	draw_vertical_line(t_exec *exec, int x, float distance, int status)
{
	int			y;
	float		height;
	float		height_end;
	float		ofset_y;
	float		y_pixel;

	y_pixel = 0;
	height = (HEIGHT / distance);
	y = (HEIGHT - height) / 2;
	height_end = y + height;
	ofset_y = (BLOCK / height);
	while (y < height_end)
	{
		y_pixel += ofset_y;
		if (exec->orientation == EST || exec->orientation == OVEST)
			put_pixel(x, y, get_color(exec, y_pixel, exec->view_y, \
				status), exec);
		else if (exec->orientation == NORD || exec->orientation == SUD)
			put_pixel(x, y, get_color(exec, y_pixel, exec->view_x, \
				status), exec);
		y++;
	}
}

float	module(t_exec *exec)
{
	float	distance;
	float	delta_x;
	float	delta_y;
	float	angle;

	delta_x = exec->view_x - exec->p.x;
	delta_y = exec->view_y - exec->p.y;
	angle = atan2(delta_y, delta_x) - exec->p.angle;
	distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2)) * fabs(cos(angle));
	return (distance);
}

float	calculate_distance(t_exec *exec, float angle)
{
	float	view_sin;
	float	view_cos;
	float	view_x_tmp;
	float	view_y_tmp;
	float	distance;

	view_x_tmp = exec->view_x;
	view_y_tmp = exec->view_y;
	view_sin = sin(angle);
	view_cos = cos(angle);
	exec->view_x = exec->p.x;
	exec->view_y = exec->p.y;
	while (!touch_orient(exec, view_x_tmp, view_y_tmp))
	{
		view_x_tmp = exec->view_x;
		view_y_tmp = exec->view_y;
		exec->view_x -= view_cos * 0.01;
		exec->view_y -= view_sin * 0.01;
	}
	distance = module(exec);
	return (distance);
}

void	tred_word(t_exec *exec, int status)
{
	float	start;
	float	end;
	int		i;

	i = 0;
	start = exec->p.angle - (PI / 6);
	end = exec->p.angle + (PI / 6);
	while (start < end)
	{
		draw_vertical_line(exec, i, calculate_distance(exec, \
			start), status);
		start += PI / WIDTH / 3;
		i++;
	}
}
