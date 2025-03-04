/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:08 by adam              #+#    #+#             */
/*   Updated: 2025/03/04 12:21:29 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(t_data *pipex)
{
	int		i;
	char	**envp;

	envp = pipex->env;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ft_strlcpy(pipex->path, envp[i], MAX_PATH);
			pipex->full_path = ft_split(pipex->path, ':');
			if (!pipex->full_path)
			{
				clear_memory(pipex);
				exit(0);
			}
			return ;
		}
		i++;
	}
	close_2_fd(pipex->pipe_fd[0], pipex->pipe_fd[1]);
	write(2, ERROR_PATH, sizeof(ERROR_PATH));
	clear_memory(pipex);
	exit(0);
}
