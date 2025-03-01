/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:02 by adam              #+#    #+#             */
/*   Updated: 2025/03/01 03:15:26 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	pipex;
	
	if (argc != 5 || !argv[1][0] || !argv[2][0] || !argv[3][0] || !argv[4][0])
	{
		write(2, ERROR_VALIDE, sizeof(ERROR_VALIDE));
		return (1);
	}
	init(&pipex, argv, envp);
	get_path(&pipex);
	check_error(&pipex);
	exec_arg(&pipex);
	clear_memory(&pipex);
	return (0);
}
