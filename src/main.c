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

static int	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = pipex_create(argc, argv, env);
	if (pipex == NULL)
		return (0);
	for (size_t i = 0; i < pipex->command_amount; i++)
		printf("%2d\t%s\n", pipex->command[i].argc, pipex->command[i].path);
	pipex_destroy(pipex);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	if (!pipex(argc, argv, env))
		return (84);
	else
		return (0);
}
