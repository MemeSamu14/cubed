/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:12 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 16:55:19 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	init_texture(t_program *prg)
{
	int		height;
	int		width;

	height = BLOCK;
	width = BLOCK;
	set_texture_path(prg);
	create_images(prg, &width, &height);
	create_dataset(prg);
}

void	init_color(t_program *prg)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(prg->code_c[0]);
	green = ft_atoi(prg->code_c[1]);
	blue = ft_atoi(prg->code_c[2]);
	prg->exec.color_c = ((red & 0xFF) << 16) \
	| ((green & 0xFF) << 8) | (blue & 0xFF);
	red = ft_atoi(prg->code_f[0]);
	green = ft_atoi(prg->code_f[1]);
	blue = ft_atoi(prg->code_f[2]);
	prg->exec.color_f = ((red & 0xFF) << 16) \
	| ((green & 0xFF) << 8) | (blue & 0xFF);
}
