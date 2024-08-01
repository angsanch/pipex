/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:07:06 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/24 20:07:09 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static size_t	forking(t_pipex *pipex)
{
	size_t	i;
	pid_t	pid;

	i = 0;
	while (i < pipex->command_amount)
	{
		pid = fork();
		if (pid > 0)
			pipex->command[i].pid = pid;
		else if (pid == 0)
		{
			exec_child(pipex, i);
			exit(84);
		}
		else
			return (i);
		i ++;
	}
	return (pipex->command_amount);
}

static int	fork_proccesses(t_pipex *pipex)
{
	size_t	i;
	char	status;

	pipex->active = forking(pipex);
	if (pipex->active == pipex->command_amount)
		status = 't';
	else
		status = 'f';
	i = 0;
	while (i < pipex->active)
	{
		write(pipex->status.write, &status, 1);
		i ++;
	}
	return (status == 't');
}

static int	create_pipes(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (i < pipex->command_amount - 1)
	{
		if (pipe((int *)&pipex->pipes[i]) < 0)
			return (0);
		i ++;
	}
	return (1);
}

int	execution(t_pipex *pipex)
{
	if (!create_pipes(pipex))
		return (0);
	if (!fork_proccesses(pipex))
		return (0);
	if (!manage_children(pipex))
		return (0);
	return (1);
}
