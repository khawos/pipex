/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:14:50 by adam              #+#    #+#             */
/*   Updated: 2025/03/01 19:15:03 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	check_error(t_data *pipex)
{
	check_error_command(pipex, pipex->cmd1[0]);
	check_error_command(pipex, pipex->cmd2[0]);
}



void	check_error_command(t_data *pipex, char *cmd)
{
	char	*try_path;
	char	*inter;
	int	i;
	i = 0;
	while (pipex->full_path[i])
	{
		inter = ft_strjoin(pipex->full_path[i], "/");
		try_path = ft_strjoin(inter, cmd);
		if (access(try_path, X_OK) == 0)
		{
			double_free(inter, try_path);
			return ;
		}
		double_free(inter, try_path);
		i++;
	}
	clear_memory(pipex);
	write(2, ERROR_CMD, sizeof(ERROR_CMD));
	exit(0);
}
