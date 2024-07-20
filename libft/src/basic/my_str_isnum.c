/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_isnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:43 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:43 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_isnumeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	my_str_isnum(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!my_isnumeric(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
