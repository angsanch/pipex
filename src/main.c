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

static int	compare_without_linechange(char *l, char *in, size_t len)
{
	bool	line_change;
	int		status;

	line_change = l[len - 1] == '\n';
	if (line_change)
		l[len - 1] = '\0';
	status = my_strcmp(l, in) == 0;
	if (line_change)
		l[len - 1] = '\n';
	return (status);
}

static int	here_doc(char *in)
{
	struct s_pipe	p;
	char			*l;
	size_t			len;

	if (pipe((int *)&p))
		return (-1);
	while (true)
	{
		l = get_next_line(0);
		if (l == NULL)
			break ;
		len = my_strlen(l);
		if (compare_without_linechange(l, in, len))
		{
			free(l);
			break ;
		}
		write(p.write, l, len);
		free(l);
	}
	gnl_flush();
	close(p.write);
	return (p.read);
}

static int	get_fds(t_pipex *pipex, char *in, char *out, bool bonus)
{
	int		flags;

	if (bonus)
		pipex->ifd = here_doc(in);
	else
		pipex->ifd = open(in, O_RDONLY);
	if (pipex->ifd < 0)
	{
		my_dprintf(2, "%s: %s.\n", in, strerror(errno));
		return (0);
	}
	flags = O_WRONLY | O_CREAT;
	if (bonus)
		flags |= O_APPEND;
	pipex->ofd = open(out, flags, 0664);
	if (pipex->ofd < 0)
	{
		my_dprintf(2, "%s: %s.\n", out, strerror(errno));
		close(pipex->ifd);
		return (0);
	}
	return (1);
}

static int	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		status;
	bool	bonus;

	bonus = my_strcmp("here_doc", argv[1]) == 0;
	if (bonus)
	{
		my_memmove(&argv[1], &argv[2], sizeof(char *) * (argc - 2));
		argc --;
	}
	pipex = pipex_create(argc, argv, env, argc - 3);
	if (pipex == NULL)
		return (84);
	pipex->env = env;
	if (!get_fds(pipex, argv[1], argv[argc - 1], bonus))
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
