/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:24 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/25 16:23:55 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_exec(t_exec *exec)
{
	free(exec->map);
	mlx_destroy_image(exec->mlx, exec->img);
	mlx_destroy_image(exec->mlx, exec->t.img_n);
	mlx_destroy_window(exec->mlx, exec->win);
	mlx_destroy_display(exec->mlx);
	free(exec->mlx);
}
