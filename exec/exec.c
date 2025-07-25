/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:12 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/25 18:36:40 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	exec(t_program *prg)
{
	prg->exec.map = matrix_dup(prg->map);
	init_exec(&prg->exec);
	mlx_hook(prg->exec.win, 2, 1L << 0, key_controls, &prg->exec);
	mlx_hook(prg->exec.win, 3, 1L << 1, key_release, &prg->exec);
	mlx_hook(prg->exec.win, 17, 1L << 3, mouse_controls, &prg->exec);
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

void	init_player(t_exec *exec)
{
	find_player(exec->map, &exec->p.x, &exec->p.y);
	exec->p.angle = PI / 2;
	exec->p.move_up = FALSE;
	exec->p.move_right = FALSE;
	exec->p.move_down = FALSE;
	exec->p.move_left = FALSE;
	exec->p.rotate_left = FALSE;
	exec->p.rotate_right = FALSE;
}

/* char	**get_map(void)
{
    char **map = malloc(sizeof(char *) * 15);
    map[0] = "1111111111111111111111111";
    map[1] = "10000000000110000000000001";
    map[2] = "1011000001110000P00000001";
    map[3] = "100100000000000000000000111111111";
    map[4] = "101111111011000001110000000000001";
    map[5] = "100000000011000001110111111111111";
    map[6] = "10110111111111011100000010001";
    map[7] = "10110111111111011101010010001";
    map[8] = "10000000110101011100000010001";
    map[9] = "10000000000000001100000010001111111111";
    map[10] = "10000000000000000000000000000000000001";
    map[11] = "1000000111010101111101111000111111111111";
    map[12] = "10110111 1110101 101111010001";
    map[13] = "11111111 1111111 111111111111";
    map[14] = NULL;
    return (map);
} */


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
	prg->exec.t.xpm_n = mlx_get_data_addr(prg->exec.t.img_n, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_s = mlx_get_data_addr(prg->exec.t.img_s, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_e = mlx_get_data_addr(prg->exec.t.img_e, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
	prg->exec.t.xpm_o = mlx_get_data_addr(prg->exec.t.img_o, &prg->exec.t.bpp, &prg->exec.t.size_line, &prg->exec.t.endian);
}


void	init_exec(t_exec *exec)
{
	init_player(exec);
	exec->mlx = mlx_init();
	exec->win = mlx_new_window(exec->mlx, WIDTH, HEIGHT, "Cubed");
	exec->img = mlx_new_image(exec->mlx, WIDTH, HEIGHT);
	exec->view_x = 0;
	exec->view_y = 0;
	exec->data = mlx_get_data_addr(exec->img, &exec->bpp, &exec->size_line, &exec->endian);
}



