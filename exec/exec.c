/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:12 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/28 17:55:30 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int shoot(int button, int x, int y, t_program *prg)
{
	(void)x;
	(void)y;
	(void)prg;
	if (button == 1)
	{
		prg->exec.button = 1;
	}
	return (0);
}

int	pointer(int x, int y, t_program *prg)
{
	(void)y;
	if (prg->exec.p.pos_x_mouse == -1)
		prg->exec.p.pos_x_mouse = x;
	if (prg->exec.p.pos_x_mouse < x - 15)
	{
		if (x > 10)
			prg->exec.p.angle += MOUSE_SENSIBILITY;
		prg->exec.p.pos_x_mouse = x;
	}
	if (prg->exec.p.pos_x_mouse > x + 15)
	{
		if (x < 1910)
			prg->exec.p.angle -= MOUSE_SENSIBILITY;
		prg->exec.p.pos_x_mouse = x;
	}	
	return (0);
}

int	exec(t_program *prg)
{
	init_exec(prg);
	mlx_hook(prg->exec.win, 2, 1L << 0, key_controls, prg);
	mlx_hook(prg->exec.win, 3, 1L << 1, key_release, &prg->exec);
	mlx_hook(prg->exec.win, 17, 1L << 3, mouse_controls, prg);
	mlx_hook(prg->exec.win, 6, 1L << 6, pointer, prg);	
	mlx_hook(prg->exec.win, 4, 1L << 2, shoot, prg);	
	init_texture(prg);
	mlx_loop_hook(prg->exec.mlx, draw_loop, &prg->exec);
	mlx_loop(prg->exec.mlx);
	return (0);
}

void	find_player(char **map, float *x, float *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

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

void	init_texture(t_program *prg)
{
	int		height = BLOCK;
	int		width = BLOCK;
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
	prg->exec.t.img_n = mlx_xpm_file_to_image(prg->exec.mlx, prg->no, &width, &height);
	prg->exec.t.img_s = mlx_xpm_file_to_image(prg->exec.mlx, prg->so, &width, &height);
	prg->exec.t.img_e = mlx_xpm_file_to_image(prg->exec.mlx, prg->ea, &width, &height);
	prg->exec.t.img_o = mlx_xpm_file_to_image(prg->exec.mlx, prg->we, &width, &height);
	prg->exec.t.img_o1 = mlx_xpm_file_to_image(prg->exec.mlx, "texture/piccoletto1.xpm", &width, &height);
	prg->exec.t.img_o2 = mlx_xpm_file_to_image(prg->exec.mlx, "texture/piccoletto2.xpm", &width, &height);
	prg->exec.t.img_d = mlx_xpm_file_to_image(prg->exec.mlx, "texture/door.xpm", &width, &height);
	prg->exec.t.img_shotgun = mlx_xpm_file_to_image(prg->exec.mlx, "texture/shotgun.xpm", &width, &height);
	prg->exec.t.img_shoot = mlx_xpm_file_to_image(prg->exec.mlx, "texture/shoot.xpm", &width, &height);
	prg->exec.t.xpm_shotgun = mlx_get_data_addr(prg->exec.t.img_shotgun, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_shoot = mlx_get_data_addr(prg->exec.t.img_shoot, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_n = mlx_get_data_addr(prg->exec.t.img_n, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_s = mlx_get_data_addr(prg->exec.t.img_s, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_e = mlx_get_data_addr(prg->exec.t.img_e, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o = mlx_get_data_addr(prg->exec.t.img_o, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o1 = mlx_get_data_addr(prg->exec.t.img_o1, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o2 = mlx_get_data_addr(prg->exec.t.img_o2, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_d = mlx_get_data_addr(prg->exec.t.img_d, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
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
	prg->exec.data = mlx_get_data_addr(prg->exec.img, &prg->exec.bpp, &prg->exec.size_line, &prg->exec.endian);
}



