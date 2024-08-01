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

void	exec_child(t_pipex *pipex, size_t id)
{
	char		status;
	t_command	*com;

	if (read(pipex->status.read, &status, 1) < 1)
		exit(84);
	if (status == 'f')
		exit(84);
	com = &pipex->command[id];
	execve(com->path, com->argv, pipex->env);
}
