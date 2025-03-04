/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:14:50 by adam              #+#    #+#             */
/*   Updated: 2025/03/04 12:33:57 by amedenec         ###   ########.fr       */
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
	int		i;

	i = 0;
	while (pipex->full_path[i])
	{
		inter = ft_strjoin(pipex->full_path[i], "/");
		if (!inter)
			call_free_memory_and_exit(pipex);
		try_path = ft_strjoin(inter, cmd);
		if (!try_path)
			call_free_memory_and_exit(pipex);
		if (access(try_path, X_OK) == 0)
		{
			double_free(inter, try_path);
			return ;
		}
		double_free(inter, try_path);
		i++;
	}
	clear_memory(pipex);
	close_2_fd(pipex->pipe_fd[0], pipex->pipe_fd[1]);
	write(2, ERROR_CMD, sizeof(ERROR_CMD));
	exit(0);
}

/*
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
}*/
