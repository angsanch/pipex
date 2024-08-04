/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpipex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:09:33 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/21 02:09:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	add_path(t_pipex *pipex, char **env)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (env[i] != NULL)
	{
		if (my_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i ++;
	}
	if (env[i] == NULL)
		return (0);
	pipex->path.path = my_split(my_strchr(env[i], '=') + 1, ':');
	if (pipex->path.path == NULL)
		return (0);
	i = 0;
	while (pipex->path.path[i])
	{
		len = my_strlen(pipex->path.path[i]);
		if (len > pipex->path.longest)
			pipex->path.longest = len;
		i ++;
	}
	return (1);
}

static int	prepare_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	size_t	i;

	if ((size_t)argc != pipex->command_amount + 3)
		return (0);
	if (!add_path(pipex, env))
		return (0);
	pipex->command = my_calloc(sizeof(t_command), pipex->command_amount);
	pipex->pipes = my_calloc(sizeof(struct s_pipe), pipex->command_amount - 1);
	if (pipex->command == NULL || pipex->pipes == NULL)
		return (0);
	i = 0;
	while (i < pipex->command_amount)
	{
		if (!command_initialize(&pipex->command[i], &pipex->path, argv[i + 2]))
			return (0);
		i ++;
	}
	i = 0;
	while (i < pipex->command_amount - 1)
	{
		pipex->pipes[i].read = -1;
		pipex->pipes[i].write = -1;
		i ++;
	}
	return (1);
}

t_pipex	*pipex_create(int argc, char **argv, char **env, size_t command_amount)
{
	t_pipex	*result;

	result = my_calloc(sizeof(t_pipex), 1);
	if (result == NULL)
		return (NULL);
	result->command_amount = command_amount;
	if ((!prepare_pipex(result, argc, argv, env)) || \
		pipe((int *)&result->status) < 0)
	{
		pipex_destroy(result);
		return (NULL);
	}
	result->ifd = -1;
	result->ofd = -1;
	return (result);
}

void	pipex_close(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (i < pipex->command_amount - 1 && pipex->pipes != NULL)
	{
		close_pipe(&pipex->pipes[i]);
		i ++;
	}
	close_pipe(&pipex->status);
	if (pipex->ifd >= 0)
		close(pipex->ifd);
	if (pipex->ofd >= 0)
		close(pipex->ofd);
}

void	pipex_destroy(t_pipex *pipex)
{
	size_t	i;

	if (pipex == NULL)
		return ;
	if (pipex->command != NULL)
	{
		i = 0;
		while (i < pipex->command_amount)
		{
			command_delete(&pipex->command[i]);
			i ++;
		}
		free(pipex->command);
	}
	free_string_array(pipex->path.path);
	free(pipex->pipes);
	free(pipex);
}
