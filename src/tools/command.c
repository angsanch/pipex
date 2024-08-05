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

static char	*get_path(t_path *path, char *name)
{
	char	*result;
	size_t	i;

	if (my_strchr_count(name, '/') > 0)
		return (my_strdup(name));
	result = malloc((path->longest + my_strlen(name) + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (path->path[i])
	{
		my_strcpy(result, path->path[i]);
		if (result[my_strlen(result) - 1] != '/')
			my_strcat(result, "/");
		my_strcat(result, name);
		if (access(result, R_OK | X_OK) == 0)
			return (result);
		i ++;
	}
	free(result);
	return (NULL);
}

int	command_initialize(t_command *command, t_path *path, char *text)
{
	command->argv = my_coolersplit(text, " \t");
	if (command->argv == NULL)
		return (0);
	command->argc = get_pointer_array_len(command->argv);
	if (command->argc < 1)
	{
		my_dprintf(2, ": Empty command.\n");
		return (0);
	}
	command->path = get_path(path, command->argv[0]);
	command->pid = -1;
	command->exit_status = 1;
	if (command->path != NULL)
		return (1);
	my_dprintf(2, "%s: command not found.\n", text);
	return (0);
}

void	command_delete(t_command *command)
{
	if (command == NULL)
		return ;
	free(command->path);
	free_string_array(command->argv);
}
