/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:27 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:27 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

void	*my_memjoin(const void *m1, size_t s1, const void *m2, size_t s2)
{
	void	*result;

	result = my_calloc(sizeof(char), (s1 + s2 + 2));
	if (result == NULL)
		return (NULL);
	my_memcpy(result, m1, s1);
	my_memcpy(result + s1, m2, s2);
	return (result);
}
