/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:50 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:50 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

static size_t	coincidences(char const *base, char const *key, size_t key_len)
{
	size_t	i;
	char	*head;

	i = 0;
	head = (char *)base;
	while (head != (char *)key_len)
	{
		head = (char *)(my_strstr(head, key) + key_len);
		i += head != (char *)key_len;
	}
	return (i);
}

static void	thinker(char *base, char *key, char *replace, char *result)
{
	size_t	offset;
	size_t	jump;
	size_t	base_offset;
	size_t	i;
	t_sizes	sizes;

	offset = 0;
	base_offset = 0;
	sizes.base_len = my_strlen(base);
	sizes.key_len = my_strlen(key);
	sizes.repl_len = my_strlen(replace);
	sizes.coins = coincidences(base, key, sizes.key_len);
	i = 0;
	while (i < sizes.coins)
	{
		jump = my_strstr(base + base_offset, key) - (base + base_offset);
		my_memcpy(result + offset, base + base_offset, jump);
		base_offset += jump + sizes.key_len;
		offset += jump + sizes.repl_len;
		my_memcpy(result + offset - sizes.repl_len, replace, sizes.repl_len);
		i ++;
	}
	if (base_offset != sizes.base_len)
		my_memcpy(result + offset, base + base_offset,
			sizes.base_len - base_offset);
}

char	*my_strreplace(char *base, char *key, char *replace)
{
	size_t	base_len;
	size_t	key_len;
	size_t	repl_len;
	size_t	coins;
	char	*result;

	base_len = my_strlen(base);
	key_len = my_strlen(key);
	repl_len = my_strlen(replace);
	coins = coincidences(base, key, key_len);
	result = my_calloc((base_len + ((repl_len - key_len) * coins)) + 1,
			sizeof(char));
	if (result == NULL)
		return (NULL);
	thinker(base, key, replace, result);
	return (result);
}
