/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 10:53:13 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	get_color(t_exec *exec, int ofset_y, float ofset_x, int status)
{
	int		red;
	int		green;
	int		blue;
	char	*img_data;

	img_data = NULL;
	ofset_x = (ofset_x - (int)ofset_x) * 100;
	correct_color(exec, &img_data, &ofset_x, status);
	red = img_data[(ofset_y * exec->t.size_line) + (((int)ofset_x \
		* exec->t.bpp) / 8) + 2];
	green = img_data[(ofset_y * exec->t.size_line) + (((int)ofset_x \
		* exec->t.bpp) / 8) + 1];
	blue = img_data[(ofset_y * exec->t.size_line) + (((int)ofset_x \
		* exec->t.bpp) / 8) + 0];
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

void	correct_color(t_exec *exec, char **img_data, float *ofset_x, int status)
{
	if (exec->orientation == SUD || exec->orientation == OVEST)
		*ofset_x = BLOCK - ((*ofset_x * BLOCK) / 100);
	else
		*ofset_x = ((*ofset_x * BLOCK) / 100);
	if (exec->map[(int)exec->view_x][(int)exec->view_y] == 'D')
		*img_data = exec->t.xpm_d;
	else if (exec->orientation == EST)
		*img_data = exec->t.xpm_e;
	else if (exec->orientation == SUD)
		*img_data = exec->t.xpm_s;
	else if (exec->orientation == NORD)
		*img_data = exec->t.xpm_n;
	else if (exec->orientation == OVEST)
	{
		if (status >= 0 && status <= 9)
			*img_data = exec->t.xpm_o;
		else if (status >= 10 && status <= 19)
			*img_data = exec->t.xpm_o1;
		else
			*img_data = exec->t.xpm_o2;
	}
}
