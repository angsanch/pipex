/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:28 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:28 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

void	*my_memmove(void *dst, const void *src, size_t n)
{
	char		*dstchr;
	const char	*srcchr;
	size_t		i;

	dstchr = dst;
	srcchr = src;
	i = 0;
	if (src > dst)
	{
		my_memcpy(dst, src, n);
		return (dst);
	}
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dstchr[n - i - 1] = srcchr[n - i - 1];
		i ++;
	}
	return (dst);
}
