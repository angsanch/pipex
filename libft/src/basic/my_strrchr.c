/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:49 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:49 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*my_strrchr(char const *str, char c)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last = i;
		i ++;
	}
	if (str[last] == c)
		return ((char *)(str + last));
	else
		return (NULL);
}
