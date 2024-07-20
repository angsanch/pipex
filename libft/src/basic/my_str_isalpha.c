/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_isalpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:43 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:43 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_isalpha(char c)
{
	int	result;

	result = 0;
	result += c >= 'a' && c <= 'z';
	result += c >= 'A' && c <= 'Z';
	return (result > 0);
}

int	my_str_isalpha(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!my_isalpha(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
