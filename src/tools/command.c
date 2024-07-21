/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:41:16 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/21 02:41:17 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	command_initialize(t_command *command, char **path, char *text)
{
	(void)command;
	(void)path;
	(void)text;
	return (1);
}

void	command_delete(t_command *command)
{
	free(command->path);
	free_string_array(command->argv);
}
