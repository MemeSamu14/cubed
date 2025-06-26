/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:23:43 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/25 16:00:38 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	create_mini_images(t_program *prg);

int	create_images(t_program *prg)
{
	create_mini_images(prg);
	return (CORRECT);
}

void	create_mini_images(t_program *prg)
{
	prg->height = 16;
	prg->wall_img = mlx_xpm_file_to_image(prg->mlx, \
		"texture/wall.xpm", &prg->height, &prg->height);
	prg->floor_img = mlx_xpm_file_to_image(prg->mlx, \
		"texture/floor.xpm", &prg->height, &prg->height);
	prg->player_img = mlx_xpm_file_to_image(prg->mlx, \
		"texture/player.xpm", &prg->height, &prg->height);
	prg->empty_img = mlx_xpm_file_to_image(prg->mlx, \
		"texture/empty.xpm", &prg->height, &prg->height);
}
