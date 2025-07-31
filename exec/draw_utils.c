/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:41 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/31 16:19:36 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	put_pixel(int x, int y, int color, t_exec *exec)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * exec->size_line + x * exec->bpp / 8;
	exec->data[index] = color & 0xFF;
	exec->data[index + 1] = (color >> 8) & 0xFF;
	exec->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(float x, float y, int color, t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32 / 4)
	{
		j = 0;
		while (j < 32 / 4)
		{
			put_pixel(x + i, y + j, color, exec);
			j++;
		}
		i++;
	}
}

void	draw_line(t_exec *exec, float x, float y, float angle)
{
	float	sin_a;
	float	cos_a;
	int		i;

	i = 0;
	sin_a = sin(angle);
	cos_a = cos(angle);
	while (!touch(x, y, exec->map))
	{
		x -= cos_a * 0.01;
		y -= sin_a * 0.01;
		put_pixel(x * 32 / 4, y * 32 / 4, 0xFFFF00, exec);
		i++;
	}
}

int	touch_orient(t_exec *exec, int x_prev, int y_prev)
{
	if ((int)exec->view_x < x_prev)
		exec->orientation = OVEST;
	if ((int)exec->view_x > x_prev)
		exec->orientation = EST;
	if ((int)exec->view_y < y_prev)
		exec->orientation = NORD;
	if ((int)exec->view_y > y_prev)
		exec->orientation = SUD;
	if (exec->map[(int)exec->view_x][(int)exec->view_y] == '1' || \
	exec->map[(int)exec->view_x][(int)exec->view_y] == 'D' || \
	exec->map[(int)exec->view_x][(int)exec->view_y] == ' ')
		return (TRUE);
	return (FALSE);
}

int	touch(float x, float y, char **map)
{
	
	if (map[(int)x][(int)y] == '1' || map[(int)x][(int)y] == 'D' || \
	map[(int)x][(int)y] == ' ')
		return (TRUE);
	return (FALSE);
}
