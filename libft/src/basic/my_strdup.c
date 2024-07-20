/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:42 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

char	*my_strdup(char const *src)
{
	size_t	len;
	char	*result;

	len = my_strlen(src) + 1;
	result = malloc(sizeof(char) * len);
	if (result == NULL)
		return (NULL);
	my_strcpy(result, src);
	return (result);
}
