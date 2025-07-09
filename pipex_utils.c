/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:57:42 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/09 17:19:24 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	valid_av(int ac, char **av)
{
	int	i;

	if (ac != 5)
	{
		ft_printf("Error: invalid number of arguments\n");
		exit(1);
	}
	i = 1;
	while (av[i])
	{
		if (!av[i][0] || av[i][0] == '\0' || av[i][0] == ' ')
		{
			ft_printf("Error: empty argument\n");
			exit(1);
		}
		i++;
	}
}

void	wait_close(t_pipex *px)
{
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	waitpid(px->pid_a, NULL, 0);
	waitpid(px->pid_b, NULL, 0);
}

void	free_split(char **ag)
{
	int	i;

	if (!ag)
		return ;
	i = 0;
	while (ag[i])
		free(ag[i++]);
	free(ag);
}

void	perror_exit(char *msg)
{
	perror(msg);
	exit(1);
}

void	free_and_exit(t_pipex *px, char *msg)
{
	if (px->cmd_arr1)
		free_split(px->cmd_arr1);
	if (px->cmd_arr2)
		free_split(px->cmd_arr2);
	if (px->pipefd[0] > 0)
		close(px->pipefd[0]);
	if (px->pipefd[1] > 0)
		close(px->pipefd[1]);
	if (px->access_path1)
		free(px->access_path1);
	if (px->access_path2)
		free(px->access_path2);
	perror_exit(msg);
}
