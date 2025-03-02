/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:17 by adam              #+#    #+#             */
/*   Updated: 2025/03/02 02:38:55 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_memory(t_data *pipex)
{
	if (pipex->cmd1)
		free_split(pipex->cmd1);
	if (pipex->cmd2)
		free_split(pipex->cmd2);
	if (pipex->full_path)
		free_split(pipex->full_path);
}

void	double_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

void	close_3_fd(int a, int b, int c)
{
	close(a);
	close(b);
	close(c);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	call_free_memory_and_exit(t_data *pipex)
{
	clear_memory(pipex);
	exit(0);
}
