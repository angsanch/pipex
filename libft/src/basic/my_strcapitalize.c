/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:40 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:40 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

char	*my_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	my_to_upper(str);
	while (str[i] != 0)
	{
		i ++;
		if (my_isalpha(str[i - 1]) || my_isnumeric(str[i - 1]))
			my_to_lower(str + i);
		else
			my_to_upper(str + i);
	}
	return (str);
}
