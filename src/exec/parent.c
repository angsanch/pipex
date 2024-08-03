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

int	manage_children(t_pipex *pipex)
{
	pid_t	pid;
	int		wstatus;

	while (pipex->active > 0)
	{
		pid = wait(&wstatus);
		printf("kid %7d has ended.\n", (int)pid);
		pipex->active --;
	}
	return (1);
}
