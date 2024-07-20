/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:46 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:46 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	my_to_lower(char *chr)
{
	if (chr[0] >= 'A' && chr[0] <= 'Z')
		chr[0] += 32;
}

char	*my_strlowcase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		my_to_lower(str + i);
		i ++;
	}
	return (str);
}
