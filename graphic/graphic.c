/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:49:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/26 12:31:12 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	graphic(t_program *prg)
{
	if (color_bg(prg) == ERROR)
		return (ERROR);
	full_fill_black(prg);
	return (CORRECT);
}
