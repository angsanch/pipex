/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_coolersplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:19 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

static size_t	find_next_start(t_splited *spl)
{
	size_t	i;

	i = 0;
	while (spl->str[spl->offset + i] != 0)
	{
		if (!my_strchr(spl->separators, spl->str[spl->offset + i]))
			break ;
		i ++;
	}
	return (i);
}

static ssize_t	find_next_end(t_splited *spl)
{
	ssize_t	i;
	char	l;

	i = 0;
	while (spl->str[spl->offset + i] != 0)
	{
		l = spl->str[spl->offset + i];
		if (spl->on_block == 0 && (l == '\'' || l == '\"'))
		{
			spl->on_block = l;
			l = 0;
		}
		if (spl->on_block == l)
			spl->on_block = 0;
		if (my_strchr(spl->separators, spl->str[spl->offset + i]) && \
			!spl->on_block)
			break ;
		i ++;
	}
	if (spl->on_block)
		return (-1);
	else
		return (i);
}

static int	word_count(t_splited *spl)
{
	int		i;
	ssize_t	end;

	i = 0;
	while (spl->str[spl->offset] != 0)
	{
		spl->offset += find_next_start(spl);
		end = find_next_end(spl);
		if (end < 0)
			return (-1);
		spl->offset += end;
		if (spl->str[spl->offset] != 0 || \
			!my_strchr(spl->separators, spl->str[spl->offset - 1]))
			i ++;
	}
	return (i);
}

static int	init_t_splited(t_splited *spl, char const *s, char const *separtrs)
{
	my_memset(spl, 0, sizeof(t_splited));
	spl->separators = separtrs;
	spl->str = s;
	spl->word_count = word_count(spl);
	if (spl->word_count < 0)
		return (0);
	spl->result = my_calloc(sizeof(char *), (spl->word_count + 1));
	if (spl->result == NULL)
		return (0);
	spl->offset = 0;
	return (1);
}

char	**my_coolersplit(char const *s, char const *separators)
{
	int			i;
	size_t		end;
	t_splited	spl;

	i = 0;
	if (!init_t_splited(&spl, s, separators))
		return (NULL);
	while (i < spl.word_count)
	{
		spl.offset += find_next_start(&spl);
		end = find_next_end(&spl);
		spl.result[i] = malloc(sizeof(char) * (end + 1));
		if (spl.result[i] == NULL)
			return (delete_t_splited(&spl, 1));
		copy_without_quotations(spl.result[i], spl.str + spl.offset, end);
		i ++;
		spl.offset += end;
	}
	delete_t_splited(&spl, 0);
	return (spl.result);
}
