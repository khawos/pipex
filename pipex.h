/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:14 by adam              #+#    #+#             */
/*   Updated: 2025/03/01 04:14:50 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define MAX_PATH 32765
# define MAX_NAME 255
# define ERROR_PATH "No PATH variable found in the environment.\n"
# define ERROR_CMD "No binary executable found for your command.\n"
# define ERROR_VALIDE "Please provide a valid arguments.\n"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/stat.h>
# include <errno.h>

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	**env;
	char	**full_path;
	char	fd_infile[MAX_NAME];
	char	fd_outfile[MAX_NAME];
	int		pipe_fd[2];
	char	path[MAX_PATH]; // ligne avec PATH=home/amedenec
}	t_data;

// init
void	init(t_data *pipex, char **argv, char **envp);

// utils
void	clear_memory(t_data *pipex);
void	free_split(char **str);
void	double_free(char *str1, char *str2);
void	close_2_fd(int a, int b);

// path
void	get_path(t_data *pipex);

// check_errors
void	check_error(t_data *pipex);
void	check_error_command(t_data *pipex, char *cmd);

// exec
void	exec_arg(t_data *pipex);
void	handle_first_child(t_data *pipex);
void	handle_second_child(t_data *pipex);
void	execute_first_child(t_data *pipex);
void	execute_second_child(t_data *pipex);

#endif
