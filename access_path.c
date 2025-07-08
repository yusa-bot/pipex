/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:53:57 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/08 23:03:05 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_can_access_path(char **paths, char *only_cmd)
{
	int		i;
	char	*access_path;

	i = 0;
	while (paths[i])
	{
		if (!paths[i] || paths[i] == NULL)
			return (NULL);
		access_path = malloc(strlen(paths[i]) + strlen(only_cmd) + 2);
		if (!access_path)
			continue ;
		access_path[0] = '\0';
		strcat(access_path, paths[i]);
		strcat(access_path, "/");
		strcat(access_path, only_cmd);
		if (access(access_path, X_OK) == 0)
			return (access_path);
		i++;
	}
	return (NULL);
}

char	**find_env_paths(char **envp)
{
	int		i;
	char	*env_path;
	char	**paths;

	if (!*envp)
		return (NULL);
	i = 0;
	env_path = "";
	while (envp[i])
	{
		if (!envp[i] || envp[i] == NULL)
			return (NULL);
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!env_path)
		return (NULL);
	paths = ft_split_c(env_path, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	**to_cmd_arr(char *cmd)
{
	char	**cmd_arr;

	cmd_arr = ft_split_c(cmd, ' ');
	if (!cmd_arr)
		perror_exit("malloc");
	return (cmd_arr);
}

void	init_commands(t_pipex *px, char **av)
{
	char	**paths;

	px->cmd_arr1 = to_cmd_arr(av[1]);
	px->cmd_arr2 = to_cmd_arr(av[2]);

	paths = find_env_paths(px->envp);
	if (!paths)
		perror_exit("paths");
	px->access_path1 = find_can_access_path(paths, px->cmd_arr1[0]);
	printf("access_path1 = %s\n", px->access_path1);//
	if (!px->access_path1)
		perror_exit("access_path1");
	px->access_path2 = find_can_access_path(paths, px->cmd_arr2[0]);
	if (!px->access_path2)
		perror_exit("access_path2");
}