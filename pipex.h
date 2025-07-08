/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:28:59 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/08 22:56:47 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_pipex
{
	char	*in_file;
	char	*out_file;

	char	*access_path1;
	char	*access_path2;

	char	**cmd_arr1;
	char	**cmd_arr2;

	char	**envp;
	char	**av;

	int		pipefd[2];

	pid_t	pid_a;
	pid_t	pid_b;
}	t_pipex;

void	init_commands(t_pipex *px, char **av);
void	perror_exit(char *msg);
void	valid_av(int ac, char **av);
void	wait_close(t_pipex *px);


#endif