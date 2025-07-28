/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:41 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/28 18:12:41 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

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
	if (exec->map[(int)exec->view_x][(int)exec->view_y] == '1' || exec->map[(int)exec->view_x][(int)exec->view_y] == 'D')
		return (TRUE);
	return (FALSE);
}

int	touch(float x, float y, char **map)
{
	if (map[(int)x][(int)y] == '1' || map[(int)x][(int)y] == 'D')
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
		put_pixel(x * 32 / 4, y * 32 / 4, 0xFFFF00, exec);
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

int	draw_loop(t_exec *exec)
{
	static int	i = 0;
	static int	j = 15;

	if (i == 300)
		i = 0;
	draw_bg(exec, exec->color_f, exec->color_c);
	movement(&exec->p, exec->map);
	rotation(&exec->p);
	rotation_mouse(&exec->p);
	tred_word(exec, i % 30);
	draw_map(exec);
	draw_player(exec, TRUE);
	if (exec->button == 1)
	{
		exec->button = 0;
		j = 0;
	}
	if (j < 15)
	{
		draw_animation(exec);
		j++;
	}
	draw_shotgun(exec);
	mlx_put_image_to_window(exec->mlx, exec->win, exec->img, 0, 0);
	i++;
	return (0);
}
