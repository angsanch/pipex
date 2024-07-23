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
	pipex->ofd = open(out, O_WRONLY);
	if (pipex->ofd < 0)
	{
		close(pipex->ofd);
		return (0);
	}
	return (1);
}

static int	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		status;

	pipex = pipex_create(argc, argv, env, 2);
	if (pipex == NULL)
		return (0);
	for (size_t i = 0; i < pipex->command_amount; i++)
		printf("%2d\t%s\n", pipex->command[i].argc, pipex->command[i].path);
	status = get_fds(pipex, argv[1], argv[argc - 1]);
	printf("%2d\t%2d\n", pipex->ifd, pipex->ofd);
	pipex_destroy(pipex);
	return (status);
}

int	main(int argc, char **argv, char **env)
{
	if (!pipex(argc, argv, env))
		return (84);
	else
		return (0);
}
