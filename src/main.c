/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:23:17 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/21 01:23:20 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	get_fds(t_pipex *pipex, char *in, char *out)
{
	pipex->ifd = open(in, O_RDONLY);
	if (pipex->ifd < 0)
		return (0);
	pipex->ofd = open(out, O_WRONLY | O_CREAT, 0664);
	if (pipex->ofd < 0)
	{
		close(pipex->ifd);
		return (0);
	}
	return (1);
}

static int	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		status;

	pipex = pipex_create(argc, argv, env, argc - 3);
	if (pipex == NULL)
		return (84);
	pipex->env = env;
	if (!get_fds(pipex, argv[1], argv[argc - 1]))
	{
		pipex_destroy(pipex);
		return (84);
	}
	if (!execution(pipex))
		status = 1;
	else
		status = pipex->command[pipex->command_amount - 1].exit_status;
	pipex_destroy(pipex);
	return (status);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		return (84);
	return (pipex(argc, argv, env));
}
