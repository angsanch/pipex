/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:39 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:39 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

static char	*find_next_start(const char *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != delimiter)
			break ;
		i ++;
	}
	return ((char *)str + i);
}

static char	*find_next_end(const char *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == delimiter)
			break ;
		i ++;
	}
	return ((char *)str + i);
}

static int	word_count(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		str = find_next_start(str, delimiter);
		str = find_next_end(str, delimiter);
		if (*str != 0 || *(str - 1) != delimiter)
			i ++;
	}
	return (i);
}

char	**my_split(char const *s, char c)
{
	int		i;
	int		n;
	char	**result;
	char	*end;

	i = 0;
	n = word_count(s, c);
	result = malloc(sizeof(char *) * (n + 1));
	if (result == NULL)
		return (NULL);
	my_memset(result, 0, sizeof(char *) * (n + 1));
	while (i < n)
	{
		s = find_next_start(s, c);
		end = find_next_end(s, c);
		result[i] = malloc(sizeof(char) * (end - s + 1));
		if (result[i] == NULL)
			return (free_string_array(result));
		my_memcpy(result[i], s, end - s);
		result[i][end - s] = 0;
		i ++;
		s = end;
	}
	return (result);
}
