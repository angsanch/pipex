/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:50 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:50 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

char	*my_strstr(char *str, char const *to_find)
{
	size_t	i;
	size_t	str_len;
	size_t	find_len;

	i = 0;
	str_len = my_strlen(str);
	find_len = my_strlen(to_find);
	if (str_len < find_len)
		return (0);
	if (find_len == 0)
		return (str);
	while (i < str_len - find_len + 1)
	{
		if (my_strncmp(str + i, to_find, find_len) == 0)
			return (str + i);
		i ++;
	}
	return (0);
}
