/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:53:57 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/09 17:02:45 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_can_access_path(char **paths, char *only_cmd)
{
	int		i;
	char	*access_path;

	i = -1;
	while (paths[++i])
	{
		access_path = malloc(strlen(paths[i]) + strlen(only_cmd) + 2);
		if (!access_path)
			continue ;
		access_path[0] = '\0';
		strcat(access_path, paths[i]);
		strcat(access_path, "/");
		strcat(access_path, only_cmd);
		if (access(access_path, X_OK) == 0)
			return (access_path);
		else
			free(access_path);
	}
	return (NULL);
}

static char	**find_env_paths(t_pipex *px, char **envp)
{
	int		i;
	char	*env_path;
	char	**paths;

	if (!*envp)
		free_and_exit(px, "not envp");
	i = 0;
	env_path = "";
	while (envp[i])
	{
		if (!envp[i] || envp[i] == NULL)
			free_and_exit(px, "not envp");
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!env_path)
		free_and_exit(px, "not env_path");
	paths = ft_split_c(env_path, ':');
	if (!paths)
		free_and_exit(px, "malloc paths");
	return (paths);
}

static char	**to_cmd_arr(t_pipex *px, char *cmd)
{
	char	**cmd_arr;

	cmd_arr = ft_split_c(cmd, ' ');
	if (!cmd_arr)
		free_and_exit(px, "malloc cmd_arr");
	return (cmd_arr);
}

void	init_commands(t_pipex *px, char **av)
{
	char	**paths;

	px->cmd_arr1 = to_cmd_arr(px, av[2]);
	px->cmd_arr2 = to_cmd_arr(px, av[3]);
	paths = find_env_paths(px, px->envp);
	px->access_path1 = find_can_access_path(paths, px->cmd_arr1[0]);
	if (!px->access_path1)
	{
		free_split(paths);
		free_and_exit(px, "not access_path");
	}
	px->access_path2 = find_can_access_path(paths, px->cmd_arr2[0]);
	if (!px->access_path2)
	{
		free_split(paths);
		free_and_exit(px, "not access_path");
	}
	if (paths)
		free_split(paths);
}
