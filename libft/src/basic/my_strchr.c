/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:41 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:41 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

ssize_t	my_strchr_index(char const *str, char c)
{
	ssize_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

size_t	my_strchr_count(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += str[i] == c;
		i ++;
	}
	return (count);
}

char	*my_strchr(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i ++;
	}
	return (0);
}

size_t	my_strchr_count_consecutive(char const *str)
{
	size_t	i;
	char	c;

	i = 0;
	c = str[0];
	while (str[i] && str[i] == c)
		i ++;
	return (i);
}
