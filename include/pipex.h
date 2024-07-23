/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:24:02 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/21 01:30:27 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "basic.h"

typedef struct command_info
{
	char	*path;
	int		argc;
	char	**argv;
}	t_command;

typedef struct path_info
{
	char	**path;
	size_t	longest;
}	t_path;

typedef struct pipex_info
{
	t_path		path;
	t_command	*command;
	size_t		command_amount;
	int			ifd;
	int			ofd;
}	t_pipex;

t_pipex	*pipex_create(int argc, char **argv, char **env, size_t command_amount);
void	pipex_destroy(t_pipex *pipex);
int		command_initialize(t_command *command, t_path *path, char *text);
void	command_delete(t_command *command);

#endif
