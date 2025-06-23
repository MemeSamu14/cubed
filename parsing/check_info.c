/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:20:22 by sfiorini          #+#    #+#             */
/*   Updated: 2025/06/23 16:34:28 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_info(t_program *prg)
{
	int	file;
	int	counter;
	int	exit_status;

	counter = 0;
	file = open(prg->map_name, O_RDONLY);
	while (1)
	{
		prg->buff = get_next_line_bonus(file);
		if (prg->buff == NULL)
			break ;
		exit_status = find_id(prg);
		if (exit_status == ERROR)
			return (ERROR);
		else if (exit_status == CORRECT)
			counter++;
		free(prg->buff);
		if (counter == 6)
			break ;
		prg->start_map++;
	}
	close(file);
	return (0);
}

int	find_id(t_program *prg)
{
	int	i;

	i = 0;
	while (prg->buff[i] && (prg->buff[i] == ' ' || prg->buff[i] == '	'))
		i++;
	if (prg->buff[i] == '\0' || prg->buff[i] == '\n')
		return (WRONG);
	if (check_id(prg, prg->buff + i) == ERROR)
		return (ERROR);
	return (CORRECT);
}

int	check_id(t_program *prg, char *buff)
{
	int	flag;

	flag = WRONG;
	if (ft_strncmp(buff, "NO", 2) == 0)
		flag = set_id(prg, "NO", buff + 2);
	else if (ft_strncmp(buff, "SO", 2) == 0)
		flag = set_id(prg, "SO", buff + 2);
	else if (ft_strncmp(buff, "WE", 2) == 0)
		flag = set_id(prg, "WE", buff + 2);
	else if (ft_strncmp(buff, "EA", 2) == 0)
		flag = set_id(prg, "EA", buff + 2);
	else if (ft_strncmp(buff, "F", 1) == 0)
		set_id_num(prg, "F", buff + 1);
	else if (ft_strncmp(buff, "C", 1) == 0)
		set_id_num(prg, "C", buff + 1);
	if (flag == ERROR)
		return (write(2, "Error\nInvalid Characters\n", 25), ERROR);
	return (CORRECT);
}

int	set_id(t_program *prg, char *id, char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && (buff[i] == ' ' || buff[i] == '	'))
		i++;
	if (ft_strncmp(buff + i, "./", 2) == 0)
	{
		if (ft_strncmp(id, "NO", 2) == 0)
			prg->no = ft_substr(buff, i + 2, (ft_strlen(buff) - 3 - i));
		if (ft_strncmp(id, "SO", 2) == 0)
			prg->so = ft_substr(buff, i + 2, (ft_strlen(buff) - 3 - i));
		if (ft_strncmp(id, "WE", 2) == 0)
			prg->we = ft_substr(buff, i + 2, (ft_strlen(buff) - 3 - i));
		if (ft_strncmp(id, "EA", 2) == 0)
			prg->ea = ft_substr(buff, i + 2, (ft_strlen(buff) - 3 - i));
		return (CORRECT);
	}
	return (ERROR);
}

void	set_id_num(t_program *prg, char *id, char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && (buff[i] == ' ' || buff[i] == '	'))
		i++;
	if (ft_strncmp(id, "F", 1) == 0)
		prg->f = ft_substr(buff, i, (ft_strlen(buff) - 1 - i));
	if (ft_strncmp(id, "C", 1) == 0)
		prg->c = ft_substr(buff, i, (ft_strlen(buff) - 1 - i));
}
