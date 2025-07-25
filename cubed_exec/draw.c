/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:41 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/25 16:37:55 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	put_pixel(int x, int y, int color, t_exec *exec)
{
	int index;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * exec->size_line + x * exec->bpp / 8;
	exec->data[index] = color & 0xFF;
	exec->data[index + 1] = (color >> 8) & 0xFF;
	exec->data[index + 2] = (color >> 16) & 0xFF;
}

void draw_square(float x, float y, int color, t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK)
	{
		j = 0;
		while (j < BLOCK)
		{
			put_pixel(x + i, y + j, color, exec);
			j++;
		}
		i++;
	}
}

int	draw_map(t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (exec->map[i])
	{
		j = 0;
		while (exec->map[i][j])
		{
			if (exec->map[i][j] == '1')
				draw_square(i * BLOCK, j * BLOCK, 0xFFC0CB, exec);
			else if (exec->map[i][j] == '0' || exec->map[i][j] == 'P')
				draw_square(i * BLOCK, j * BLOCK, 0x000000, exec);
			j++;
		}
		i++;
	}
	return (0);
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
	if (exec->map[(int)exec->view_x][(int)exec->view_y] == '1')
		return (TRUE);
	return (FALSE);
}

int	touch(float x, float y, char **map)
{
	if (map[(int)x][(int)y] == '1')
		return (TRUE);
	return (FALSE);
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
		put_pixel(x * BLOCK, y * BLOCK, 0xFFFF00, exec);
		i++;
	}
}

int	draw_player(t_exec *exec, int v)
{
	float	start;
	float	end;
	int		i = 0;

	if (v == TRUE)
	{
		start = exec->p.angle - (PI / 6);
		end = exec->p.angle + (PI / 6);
		while (start < end)
		{
			draw_line(exec, exec->p.x + 0.5, \
			exec->p.y, start);
			start += PI / WIDTH / 3;
			i++;
		}
	}
	draw_square(exec->p.x * BLOCK, \
		exec->p.y * BLOCK, 0x008F39, exec);
	return (0);
}

void	draw_bg(t_exec *exec, int color_f, int color_c)
{
	int	i;
	int	j;
	int	middle;

	i = 0;
	middle = (HEIGHT / 2);
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < middle)
				put_pixel(j, i, color_c, exec);
			else
				put_pixel(j, i, color_f, exec);
			j++;
		}
		i++;
	}
}

void	draw_texture(t_exec *exec)
{
	int		x;
	int		y;
	int		index;
	int		num;

	num = 0;
	x = 0;
	index = 0;
	while (x < BLOCK)
	{
		y = 0;
		while (y < BLOCK)
		{
			num = ((exec->t.xpm_n[index + 2] & 0xFF) << 16) | \
			((exec->t.xpm_n[index + 1] & 0xFF) << 8) | \
			(exec->t.xpm_n[index + 0] & 0xFF);
			put_pixel(y, x, num , exec);
			y++;
			index += 4;
		}
		x++;
	}
}


int	draw_loop(t_exec *exec)
{
	draw_bg(exec, 0x008F39, 0xA2CADF);
	movement(&exec->p, exec->map);
	rotation(&exec->p);
	tred_word(exec);
	draw_texture(exec);
	draw_map(exec);
	draw_player(exec, TRUE);
    mlx_put_image_to_window(exec->mlx, exec->win, exec->img, 0, 0);
	return (0);
}
