/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 21:13:01 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/08 22:55:22 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(t_pipex *px)
{
	int	in_fd;

	in_fd = open(px->in_file, O_RDONLY);
	if (in_fd < 0)
		perror_exit("open infile");
	dup2(in_fd, STDIN_FILENO);
	dup2(px->pipefd[1], STDOUT_FILENO);
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	execve(px->access_path1, px->cmd_arr1, px->envp);
	perror_exit("execve cmd1");
}

void	child_2(t_pipex *px)
{
	int	out_fd;

	out_fd = open(px->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		perror_exit("open outfile");
	dup2(px->pipefd[0], STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	execve(px->access_path2, px->cmd_arr2, px->envp);
	perror_exit("execve cmd2");
}

void	execute_pipex(t_pipex *px)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
		perror_exit("pipe");
	px->pid_a = fork();
	if (px->pid_a < 0)
		perror_exit("fork pid_a");
	else if (px->pid_a == 0)
		child_1(px);
	px->pid_b = fork();
	if (px->pid_b < 0)
		perror_exit("fork pid_b");
	else if (px->pid_b == 0)
		child_2(px);

	wait_close(px);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	px.in_file = av[1];
	px.out_file = av[4];
	px.av = av;
	px.envp = envp;

	valid_av(ac, px.av);
	init_commands(&px, px.av);
	execute_pipex(&px);

	return (0);
}
