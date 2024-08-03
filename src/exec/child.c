/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:11:51 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/31 15:11:54 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	prepare_env(t_pipex *pipex, size_t id)
{
	int	status;

	close(0);
	close(1);
	if (id == 0)
		status = dup2(pipex->ifd, 0);
	else
		status = dup2(pipex->pipes[id - 1].read, 0);
	if (status < 0)
		return (0);
	if (id == pipex->command_amount - 1)
		status = dup2(pipex->ofd, 1);
	else
		status = dup2(pipex->pipes[id].write, 1);
	if (status < 0)
		return (0);
	return (1);
}

void	exec_child(t_pipex *pipex, size_t id)
{
	char		status;
	t_command	*com;

	if (read(pipex->status.read, &status, 1) < 1)
		exit(84);
	if (status == 'f')
		exit(84);
	if (!prepare_env(pipex, id))
		exit(84);
	pipex_close(pipex);
	com = &pipex->command[id];
	execve(com->path, com->argv, pipex->env);
}
