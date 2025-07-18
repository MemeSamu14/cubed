/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/18 12:24:23 by sfiorini         ###   ########.fr       */
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
	float	view_x;
	float	view_y;
	float	distance;

	view_sin = sin(angle);
	view_cos = cos(angle);
	view_x = exec->p.x;
	view_y = exec->p.y;
	while (!touch(view_x, view_y, exec->map))
	{
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
	int		i = 0;

	start = exec->p.angle - (PI / 6);
	end = exec->p.angle + (PI / 6);
	while (start < end)
	{
		// draw_line(exec, exec->p.x + 0.5, \
		// exec->p.y, start);
		draw_vertical_line(exec, i, calculate_distance(exec, start));
		start += PI / WIDTH / 3;
		i++;
	}
}


// float	calculate_distance_2(t_exec *exec, float view_x, float view_y)
// {
// 	float	view_sin;
// 	float	view_cos;
// 	float	distance;

// 	view_sin = sin(exec->p.angle);
// 	view_cos = cos(exec->p.angle);
// 	while (!touch(view_x, view_y, exec->map))
// 	{
// 		view_x -= view_cos * 0.03;
// 		view_y -= view_sin * 0.03;
// 	}
// 	distance = module(exec->p.x, exec->p.y, view_x, view_y, &exec->p);
// 	// printf("distance: %f\n", distance);
// 	return (distance);
// }
// void	tred_word(t_exec *exec)
// {
// 	float	start;
// 	int		i;

// 	i = 0;
// 	start = exec->p.angle - (PI / 6);
// 	while (start < exec->p.angle)
// 	{
// 		start += PI / WIDTH / 3;
// 		i++;
// 	}

// 	float	sin_a;
// 	float	cos_a;
// 	float	cam_x;
// 	float	cam_y;

// 	cam_x = exec->p.x;
// 	cam_y = exec->p.y;
// 	sin_a = sin(exec->p.angle);
// 	cos_a = cos(exec->p.angle);
// 	// printf("sin: %f\n", sin_a);
// 	// printf("cos: %f\n", cos_a);

// 	int	j = 0;
// 	while (j < i && (!touch(cam_x, cam_y, exec->map)))
// 	{
// 		cam_y += cos_a * 0.03;
// 		cam_x -= sin_a * 0.03;
// 		put_pixel(cam_x, cam_y, 0xFFFF00, exec);
// 		j++;
// 	}
// 	// printf("x: %f\n", cam_x);
// 	// printf("y: %f\n", cam_y);

// 	j = 0;
// 	i *= 2;
// 	cam_y -= cos_a * 0.03;
// 	cam_x += sin_a * 0.03;
// 	while ((!touch(cam_x, cam_y, exec->map)))
// 	{
// 		cam_y -= cos_a * 0.03;
// 		cam_x += sin_a * 0.03;
// 		draw_vertical_line(exec, j, calculate_distance_2(exec, cam_x, cam_y));
// 		j++;
// 		printf("camx: %f | cam: %f\n", cam_x, cam_y);
// 		// if (touch(cam_x, cam_y, exec->map))
// 		// 	break ;
// 	}
// }
