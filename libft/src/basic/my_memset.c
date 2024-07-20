/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:29 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:29 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*my_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*strint;

	i = 0;
	strint = b;
	while (i < len)
	{
		strint[i] = c;
		i ++;
	}
	return (b);
}
