/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/27 16:42:27 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	get_color(t_exec *exec, int ofset_y, float ofset_x, int status)
{
	int	red;
	int	green;
	int	blue;
	char	*img_data = NULL;

	ofset_x = (ofset_x - (int)ofset_x ) * 100;
	if (exec->orientation == SUD || exec->orientation == OVEST)
		ofset_x = BLOCK - ((ofset_x * BLOCK) / 100);
	else
		ofset_x = ((ofset_x * BLOCK) / 100);
	if (exec->orientation == EST)
		img_data = exec->t.xpm_e;
	else if (exec->orientation == SUD)
		img_data = exec->t.xpm_s;
	else if (exec->orientation == NORD)
		img_data = exec->t.xpm_n;
	else if (exec->orientation == OVEST)
	{
		if (status >= 0 && status <= 9)
			img_data = exec->t.xpm_o;
		else if (status >= 10 && status <= 19)
			img_data = exec->t.xpm_o1;
		else
			img_data = exec->t.xpm_o2;
	}
	red = img_data[(ofset_y * exec->t.size_line) + (((int)ofset_x * exec->t.bpp) / 8) + 2];
	green = img_data[(ofset_y * exec->t.size_line) + (((int)ofset_x * exec->t.bpp) / 8) + 1];
	blue = img_data[(ofset_y * exec->t.size_line) + (((int)ofset_x * exec->t.bpp) / 8) + 0];
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

void	draw_vertical_line(t_exec *exec, int x, float distance, int status)
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
		if (exec->orientation == EST || exec->orientation == OVEST)
			put_pixel(x, y, get_color(exec, y_pixel, exec->view_y, status), exec);
		if (exec->orientation == NORD || exec->orientation == SUD)
			put_pixel(x, y, get_color(exec, y_pixel, exec->view_x, status), exec);
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

float	calculate_distance(t_exec *exec, float angle)
{
	float	view_sin;
	float	view_cos;
	float	view_x_tmp = exec->view_x;
	float	view_y_tmp = exec->view_y;
	float	distance;

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
	distance = module(exec->p.x, exec->p.y, exec->view_x, exec->view_y, &exec->p);
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
		draw_vertical_line(exec, i, calculate_distance(exec, start), status);
		start += PI / WIDTH / 3;
		i++;
	}
}

