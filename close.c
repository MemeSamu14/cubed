/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:46:44 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/26 10:55:47 by sfiorini         ###   ########.fr       */
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
	free_matrix(prg->code_f);
	free_matrix(prg->code_c);
	free_exec(&prg->exec);
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

void	free_exec(t_exec *exec)
{
	mlx_destroy_image(exec->mlx, exec->img);
	mlx_destroy_image(exec->mlx, exec->t.img_n);
	mlx_destroy_image(exec->mlx, exec->t.img_s);
	mlx_destroy_image(exec->mlx, exec->t.img_o);
	mlx_destroy_image(exec->mlx, exec->t.img_e);
	mlx_destroy_window(exec->mlx, exec->win);
	mlx_destroy_display(exec->mlx);
	free(exec->mlx);
}
