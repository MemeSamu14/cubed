/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:49:19 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/25 18:12:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


int	main(int ac, char **av)
{
	t_program	prg;

	if (ac != 2)
		return (write(2, "Error\nWrong number of arguments\n", 32), ERROR);
	init(&prg, av[1]);
	if (parsing(&prg) == ERROR)
		return (ERROR);
	else if (exec(&prg) == ERROR)
		return (ERROR);
	free_all(&prg);
	return (0);
}

void	init(t_program *prg, char *map_name)
{
	prg->map = NULL;
	prg->max_len = 0;
	prg->start_map = 0;
	prg->row = 0;
	prg->map_name = ft_strdup(map_name);
	prg->buff = NULL;
	prg->no = NULL;
	prg->so = NULL;
	prg->we = NULL;
	prg->ea = NULL;
	prg->f = NULL;
	prg->c = NULL;
	prg->code_f = NULL;
	prg->code_c = NULL;
}
