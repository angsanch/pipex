/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:42 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

int	my_isalnum(char c)
{
	return (my_isalpha(c) || my_isnumeric(c));
}

int	my_str_isalnum(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!my_isalnum(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
