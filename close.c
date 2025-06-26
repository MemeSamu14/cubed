/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:46:44 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/25 18:08:20 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_all(t_program *prg)
{
	free_matrix(prg->map);
	free(prg->map_name);
	free(prg->no);
	free(prg->so);
	free(prg->we);
	free(prg->ea);
	free(prg->f);
	free(prg->c);
	mlx_destroy_image(prg->mlx, prg->wall_img);
	mlx_destroy_image(prg->mlx, prg->floor_img);
	mlx_destroy_image(prg->mlx, prg->player_img);
	mlx_destroy_image(prg->mlx, prg->empty_img);
	mlx_destroy_image(prg->mlx, prg->img_bg.img);
	free_matrix(prg->code_f);
	free_matrix(prg->code_c);
	mlx_destroy_window(prg->mlx, prg->win);
	mlx_destroy_display(prg->mlx);
	free(prg->mlx);
}

void	free_parsing(t_program *prg)
{
	free_matrix(prg->map);
	free(prg->map_name);
	free(prg->no);
	free(prg->so);
	free(prg->we);
	free(prg->ea);
	free(prg->f);
	free(prg->c);
	free_matrix(prg->code_f);
	free_matrix(prg->code_c);
}
