/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:17 by adam              #+#    #+#             */
/*   Updated: 2025/03/01 04:12:27 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_memory(t_data *pipex)
{
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);
	if (pipex->full_path)
		free_split(pipex->full_path);
}

void	double_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

void	close_2_fd(int a, int b)
{
	close(a);
	close(b);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
