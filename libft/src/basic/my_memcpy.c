/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:26 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:26 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*my_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destchr;
	const char	*srcchr;

	i = 0;
	destchr = dest;
	srcchr = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		destchr[i] = srcchr[i];
		i ++;
	}
	return (dest);
}
