/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:57:42 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/08 22:22:18 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *msg)
{
	perror(msg);
	exit(1);
}

void	valid_av(int ac, char **av)
{
	int	i;

	if (!*av || ac != 5)
		perror_exit("argv");
	i = 1;
	while (av[i])
	{
		if (!av[i][0] || av[i][0] == '\0')
			perror_exit("argv");
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
