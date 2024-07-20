/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:41 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:41 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*my_strcpy(char *dest, char const *src)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = src[i];
	return (dest);
}
