#include "pipex.h"

void	exec_arg(t_data *pipex)
{
	handle_first_child(pipex);
	handle_second_child(pipex);
	close_2_fd(pipex->pipe_fd[0], pipex->pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}

void	handle_first_child(t_data *pipex)
{
	pid_t pid;
	int	fd;

	pid = fork();
	if (pid == -1)
	{
		clear_memory(pipex);
		exit(0);
	}
	if (pid == 0)
	{
		fd = open(pipex->fd_infile, O_CREAT | O_RDONLY, 0644);
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			clear_memory(pipex);
			exit(0);
		}
		if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		{
			clear_memory(pipex);
			exit(0);
		}
		close_2_fd(pipex->pipe_fd[0], pipex->pipe_fd[1]);
		execute_first_child(pipex);
	}
}

void	execute_first_child(t_data *pipex)
{
	char	*try_path;
	char	*inter;
	int	i;

	i = 0;
	while (pipex->full_path[i])
	{
		inter = ft_strjoin(pipex->full_path[i], "/");
		try_path = ft_strjoin(inter, pipex->cmd1[0]);
		if (access(try_path, X_OK) == 0)
		{
			execve(try_path, pipex->cmd1, pipex->env);
			return ;
		}
		i++;
	}
}
void	handle_second_child(t_data *pipex)
{
	pid_t pid;
	int	fd;

	pid = fork();
	if (pid == -1)
	{
		clear_memory(pipex);
		exit(0);
	}
	if (pid == 0)
	{
		fd = open(pipex->fd_outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (dup2(pipex->pipe_fd[0] , STDIN_FILENO) == -1)
		{
			clear_memory(pipex);
			exit(0);
		}
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			clear_memory(pipex);
			exit(0);
		}
		close_2_fd(pipex->pipe_fd[0], pipex->pipe_fd[1]);
		execute_second_child(pipex);
	}
}

void	execute_second_child(t_data *pipex)
{
	char	*try_path;
	char	*inter;
	int	i;

	i = 0;
	while (pipex->full_path[i])
	{
		inter = ft_strjoin(pipex->full_path[i], "/");
		try_path = ft_strjoin(inter, pipex->cmd2[0]);
		if (access(try_path, X_OK) == 0)
		{
			execve(try_path, pipex->cmd2, pipex->env);
			return ;
		}
		i++;
	}
}
