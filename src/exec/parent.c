/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:11:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/31 15:11:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	close_fds(t_pipex *pipex, size_t id)
{
	if (id == 0)
		close(pipex->ifd);
	else
		close(pipex->pipes[id - 1].read);
	if (id == pipex->command_amount - 1)
		close(pipex->ofd);
	else
		close(pipex->pipes[id].write);
}

static ssize_t	get_id_by_pid(t_pipex *pipex, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i < pipex->command_amount)
	{
		if (pipex->command[i].pid == pid)
			return (i);
		i ++;
	}
	return (-1);
}

static void	manage_wstatus(t_command *c, int wstatus)
{
	if (WIFEXITED(wstatus))
		c->exit_status = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	{
		c->exit_status = 128 + WTERMSIG(wstatus);
	}
	else
		c->exit_status = 1;
}

int	manage_children(t_pipex *pipex)
{
	ssize_t	id;
	int		wstatus;

	while (pipex->active > 0)
	{
		id = get_id_by_pid(pipex, wait(&wstatus));
		if (id < 0)
			continue ;
		close_fds(pipex, id);
		manage_wstatus(&pipex->command[id], wstatus);
		pipex->active --;
	}
	return (1);
}
