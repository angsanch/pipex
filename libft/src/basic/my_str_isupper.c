/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_isupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:44 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	my_str_isupper(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!my_isupper(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
