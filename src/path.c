/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:08 by adam              #+#    #+#             */
/*   Updated: 2025/03/01 01:31:28 by adam             ###   ########.fr       */
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
			return ;
		}
		i++;
	}
	write(2, ERROR_PATH, sizeof(ERROR_PATH));
	clear_memory(pipex);
	exit(0);
}
