/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:42:12 by sfiorini          #+#    #+#             */
/*   Updated: 2025/07/25 16:57:46 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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

void init_player(t_exec *exec)
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

char	**get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "10000010000P001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}


void	init_texture(t_exec *exec)
{
	char	*path_img_n = "wall_nord.xpm";
	char	*path_img_s = "wall_sud.xpm";
	char	*path_img_o = "wall_ovest.xpm";
	char	*path_img_e = "wall_est.xpm";
	int		height = BLOCK;
	int		width = BLOCK;

	exec->t.img_n = mlx_xpm_file_to_image(exec->mlx, path_img_n, &width, &height);
	exec->t.img_s = mlx_xpm_file_to_image(exec->mlx, path_img_s, &width, &height);
	exec->t.img_e = mlx_xpm_file_to_image(exec->mlx, path_img_e, &width, &height);
	exec->t.img_o = mlx_xpm_file_to_image(exec->mlx, path_img_o, &width, &height);

	exec->t.xpm_n = mlx_get_data_addr(exec->t.img_n, &exec->t.bpp, &exec->t.size_line, &exec->t.endian);
	exec->t.xpm_s = mlx_get_data_addr(exec->t.img_s, &exec->t.bpp, &exec->t.size_line, &exec->t.endian);
	exec->t.xpm_e = mlx_get_data_addr(exec->t.img_e, &exec->t.bpp, &exec->t.size_line, &exec->t.endian);
	exec->t.xpm_o = mlx_get_data_addr(exec->t.img_o, &exec->t.bpp, &exec->t.size_line, &exec->t.endian);
	// controlliamo nel parsing in caso
}


void	init(t_exec *exec)
{
	exec->map = get_map();
	init_player(exec);
	exec->mlx = mlx_init();
	exec->win = mlx_new_window(exec->mlx, WIDTH, HEIGHT, "Cubed");
	exec->img = mlx_new_image(exec->mlx, WIDTH, HEIGHT);
	init_texture(exec);
	exec->view_x = 0;
	exec->view_y = 0;
	exec->data = mlx_get_data_addr(exec->img, &exec->bpp, &exec->size_line, &exec->endian);
}



int	main(void)
{
	t_exec	exec;

	init(&exec);
	mlx_hook(exec.win, 2, 1L << 0, key_controls, &exec);
	mlx_hook(exec.win, 3, 1L << 1, key_release, &exec);
	mlx_hook(exec.win, 17, 1L << 3, mouse_controls, &exec);
	
    mlx_loop_hook(exec.mlx, draw_loop, &exec);
	mlx_loop(exec.mlx);
	return (0);
}
