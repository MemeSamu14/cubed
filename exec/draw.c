/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:41 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 11:53:04 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

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
				draw_square((i * 32 / 4), (j * 32 / 4), 0xFFC0CB, exec);
			else if (exec->map[i][j] == '0' || exec->map[i][j] == 'P')
				draw_square((i * 32 / 4), (j * 32 / 4), 0x000000, exec);
			else if (exec->map[i][j] == 'D')
				draw_square((i * 32 / 4), (j * 32 / 4), 0x5C3317, exec);
			else
				draw_square((i * 32 / 4), (j * 32 / 4), 0x0000FF, exec);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_player(t_exec *exec, int v)
{
	float	start;
	float	end;
	int		i;

	i = 0;
	if (v == TRUE)
	{
		start = exec->p.angle - (PI / 6);
		end = exec->p.angle + (PI / 6);
		while (start < end)
		{
			draw_line(exec, exec->p.x + 0.5, exec->p.y, start);
			start += PI / WIDTH / 3;
			i++;
		}
	}
	draw_square(exec->p.x * 32 / 4, exec->p.y * 32 / 4, 0x008F39, exec);
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

void	draw_animation(t_exec *exec)
{
	int		x;
	int		y;
	int		index;
	int		num;

	num = 0;
	x = 0;
	index = 0;
	while (x < 274)
	{
		y = 0;
		while (y < 322)
		{
			num = ((exec->t.xpm_shoot[index + 2] & 0xFF) << 16) | \
			((exec->t.xpm_shoot[index + 1] & 0xFF) << 8) | \
			(exec->t.xpm_shoot[index + 0] & 0xFF);
			if (num != 0x000000)
				put_pixel(820 + y, (HEIGHT - 80 - 320) + x, num, exec);
			y++;
			index += 4;
		}
		x++;
	}
}

void	draw_shotgun(t_exec *exec)
{
	int		x;
	int		y;
	int		index;
	int		num;

	num = 0;
	x = 0;
	index = 0;
	while (x < 240)
	{
		y = 0;
		while (y < 291)
		{
			num = ((exec->t.xpm_shotgun[index + 2] & 0xFF) << 16) | \
			((exec->t.xpm_shotgun[index + 1] & 0xFF) << 8) | \
			(exec->t.xpm_shotgun[index + 0] & 0xFF);
			if (num != 0x000000)
				put_pixel(900 + y, (HEIGHT - 80 - 240) + x, num, exec);
			y++;
			index += 4;
		}
		x++;
	}
}
