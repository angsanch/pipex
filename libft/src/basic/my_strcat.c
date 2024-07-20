/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:40 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:40 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

char	*my_strcat(char *dest, char const *src)
{
	size_t	len;

	len = my_strlen(dest);
	my_strcpy(dest + len, src);
	return (dest);
}
