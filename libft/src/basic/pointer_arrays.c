/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:49:12 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 01:49:14 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	get_pointer_array_len(void *arr_in)
{
	size_t	i;
	void	**arr;

	i = 0;
	arr = arr_in;
	while (arr[i])
		i ++;
	return (i);
}

char	**free_string_array(char **result)
{
	int	i;

	i = 0;
	if (result == NULL)
		return (NULL);
	while (result[i])
	{
		free(result[i]);
		i ++;
	}
	free(result);
	return (NULL);
}
