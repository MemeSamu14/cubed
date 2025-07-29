/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:12 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/29 16:54:34 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	init_player(t_program *prg)
{
	find_player(prg->exec.map, &prg->exec.p.x, &prg->exec.p.y);
	if (prg->orientation == 'E')
		prg->exec.p.angle = 0;
	else if (prg->orientation == 'W')
		prg->exec.p.angle = PI;
	else if (prg->orientation == 'S')
		prg->exec.p.angle = 3 * PI / 2;
	else if (prg->orientation == 'N')
		prg->exec.p.angle = PI / 2;
	prg->exec.p.move_up = FALSE;
	prg->exec.p.move_right = FALSE;
	prg->exec.p.move_down = FALSE;
	prg->exec.p.move_left = FALSE;
	prg->exec.p.rotate_left = FALSE;
	prg->exec.p.rotate_right = FALSE;
	prg->exec.p.pos_x_mouse = -1;
}

void	set_texture_path(t_program *prg)
{
	char	*tmp;

	tmp = prg->no;
	prg->no = ft_strjoin("texture/", tmp);
	free(tmp);
	tmp = prg->so;
	prg->so = ft_strjoin("texture/", tmp);
	free(tmp);
	tmp = prg->ea;
	prg->ea = ft_strjoin("texture/", tmp);
	free(tmp);
	tmp = prg->we;
	prg->we = ft_strjoin("texture/", tmp);
	free(tmp);
}

void	create_images(t_program *prg, int *width, int *height)
{
	prg->exec.t.img_n = mlx_xpm_file_to_image(prg->exec.mlx, \
		prg->no, width, height);
	prg->exec.t.img_s = mlx_xpm_file_to_image(prg->exec.mlx, \
		prg->so, width, height);
	prg->exec.t.img_e = mlx_xpm_file_to_image(prg->exec.mlx, \
		prg->ea, width, height);
	prg->exec.t.img_o = mlx_xpm_file_to_image(prg->exec.mlx, \
		prg->we, width, height);
	prg->exec.t.img_o1 = mlx_xpm_file_to_image(prg->exec.mlx, \
		"texture/piccoletto1.xpm", width, height);
	prg->exec.t.img_o2 = mlx_xpm_file_to_image(prg->exec.mlx, \
		"texture/piccoletto2.xpm", width, height);
	prg->exec.t.img_d = mlx_xpm_file_to_image(prg->exec.mlx, \
		"texture/door.xpm", width, height);
	prg->exec.t.img_shotgun = mlx_xpm_file_to_image(prg->exec.mlx, \
		"texture/shotgun.xpm", width, height);
	prg->exec.t.img_shoot = mlx_xpm_file_to_image(prg->exec.mlx, \
		"texture/shoot.xpm", width, height);
}

void	create_dataset(t_program *prg)
{
	prg->exec.t.xpm_shotgun = mlx_get_data_addr(prg->exec.t.img_shotgun, \
		&prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_shoot = mlx_get_data_addr(prg->exec.t.img_shoot, \
		&prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_n = mlx_get_data_addr(prg->exec.t.img_n, &prg->exec.t.bpp, \
		&prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_s = mlx_get_data_addr(prg->exec.t.img_s, &prg->exec.t.bpp, \
		&prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_e = mlx_get_data_addr(prg->exec.t.img_e, &prg->exec.t.bpp, \
		&prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o = mlx_get_data_addr(prg->exec.t.img_o, &prg->exec.t.bpp, \
		&prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o1 = mlx_get_data_addr(prg->exec.t.img_o1, \
		&prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o2 = mlx_get_data_addr(prg->exec.t.img_o2, \
		&prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_d = mlx_get_data_addr(prg->exec.t.img_d, &prg->exec.t.bpp, \
		&prg->exec.t.size_line, &prg->exec.t.endian);
}

void	init_exec(t_program *prg)
{
	prg->exec.map = prg->map;
	init_color(prg);
	init_player(prg);
	prg->exec.mlx = mlx_init();
	prg->exec.win = mlx_new_window(prg->exec.mlx, WIDTH, HEIGHT, "Cubed");
	prg->exec.img = mlx_new_image(prg->exec.mlx, WIDTH, HEIGHT);
	prg->exec.view_x = 0;
	prg->exec.view_y = 0;
	prg->exec.data = mlx_get_data_addr(prg->exec.img, &prg->exec.bpp, \
		&prg->exec.size_line, &prg->exec.endian);
}
