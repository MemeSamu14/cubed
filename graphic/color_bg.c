/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:48:47 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/25 15:58:08 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_to_image(t_data *img, int color_f, int color_c)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			if (i < 540)
				my_mlx_pixel_put(img, j, i, color_c);
			else
				my_mlx_pixel_put(img, j, i, color_f);
			j++;
		}
		i++;
	}
}

int	ft_pow(int num, int power)
{
	int	result;

	if (num == 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result = result * num;
		power--;
	}
	return (result);
}

int	convert_number(char	**code)
{
	int	result;
	int	pow_times;
	int	actual_num;
	int	i;
	int	rest;

	result = 0;
	i = 0;
	pow_times = 5;
	while (i < 3)
	{
		actual_num = ft_atoi(code[i]) % 16;
		rest = actual_num % 16;
		result += (actual_num * ft_pow(16, pow_times)) + (rest * ft_pow(16, pow_times - 1));
		pow_times -= 2;
		i++;
	}
	return (result);
}

int	color_bg(t_program *prg)
{
	prg->img_bg.img = mlx_new_image(prg->mlx, 1920, 1080);
	prg->img_bg.addr = mlx_get_data_addr(prg->img_bg.img, &prg->img_bg.bits_per_pixel, &prg->img_bg.line_length,
		&prg->img_bg.endian);
	draw_to_image(&prg->img_bg, convert_number(prg->code_f), convert_number(prg->code_c));
	mlx_put_image_to_window(prg->mlx, prg->win, prg->img_bg.img, 0, 0);
	return (CORRECT);
}


