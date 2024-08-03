/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:40:18 by angsanch          #+#    #+#             */
/*   Updated: 2024/08/03 22:40:20 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	close_pipe(struct s_pipe *pipe)
{
	if (pipe->read >= 0)
		close(pipe->read);
	if (pipe->write >= 0)
		close(pipe->write);
}
