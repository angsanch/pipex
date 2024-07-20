/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:17 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:17 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

void	*my_calloc(size_t count, size_t size)
{
	size_t	space;
	void	*result;

	if (SIZE_MAX == count || SIZE_MAX == size)
		return (NULL);
	space = count * size;
	result = malloc(space);
	if (result == NULL)
		return (NULL);
	my_memset(result, 0, space);
	return (result);
}
