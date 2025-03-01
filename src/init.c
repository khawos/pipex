/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:11 by adam              #+#    #+#             */
/*   Updated: 2025/03/01 04:15:19 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_data *pipex, char **argv, char **envp)
{
	pipex->full_path = NULL;
	pipex->env = envp;
	ft_strlcpy(pipex->fd_infile, argv[1], MAX_NAME);
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	ft_strlcpy(pipex->fd_outfile, argv[4], MAX_NAME);
	if (pipe(pipex->pipe_fd) == -1)
	{
		clear_memory(pipex);
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
}