/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:52 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:52 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	my_to_upper(char *chr)
{
	if (chr[0] >= 'a' && chr[0] <= 'z')
		chr[0] -= 32;
}

char	*my_strupcase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		my_to_upper(str + i);
		i ++;
	}
	return (str);
}
