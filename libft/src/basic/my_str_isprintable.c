/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_isprintable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:44 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_isprintable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	my_str_isprintable(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!my_isprintable(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
