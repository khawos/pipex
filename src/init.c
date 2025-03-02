/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:11 by adam              #+#    #+#             */
/*   Updated: 2025/03/02 00:26:57 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_data *pipex, char **argv, char **envp)
{
	pipex->full_path = NULL;
	pipex->env = envp;
	ft_strlcpy(pipex->fd_infile, argv[1], MAX_NAME);
	pipex->cmd1 = ft_split(argv[2], ' ');
	if (!pipex->cmd1)
	{
		clear_memory(pipex);
		exit(0);
	}
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (!pipex->cmd2)
	{
		clear_memory(pipex);
		exit(0);
	}
	ft_strlcpy(pipex->fd_outfile, argv[4], MAX_NAME);
	if (pipe(pipex->pipe_fd) == -1)
	{
		clear_memory(pipex);
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
}
