/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:24:02 by angsanch          #+#    #+#             */
/*   Updated: 2024/08/03 22:40:56 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "basic.h"

struct s_pipe
{
	int	read;
	int	write;
};

typedef struct command_info
{
	char	*path;
	int		argc;
	char	**argv;
	pid_t	pid;
	int		exit_status;
}	t_command;

typedef struct path_info
{
	char	**path;
	size_t	longest;
}	t_path;

typedef struct pipex_info
{
	t_path			path;
	t_command		*command;
	char			**env;
	size_t			command_amount;
	size_t			active;
	struct s_pipe	*pipes;
	struct s_pipe	status;
	int				ifd;
	int				ofd;
}	t_pipex;

t_pipex	*pipex_create(int argc, char **argv, char **env, size_t command_amount);
void	pipex_destroy(t_pipex *pipex);
void	pipex_close(t_pipex *pipex);
int		command_initialize(t_command *command, t_path *path, char *text);
void	command_delete(t_command *command);
void	close_pipe(struct s_pipe *pipe);

int		manage_children(t_pipex *pipex);
void	exec_child(t_pipex *pipex, size_t id);
int		execution(t_pipex *pipex);

#endif
