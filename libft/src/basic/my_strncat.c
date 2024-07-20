/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:47 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:47 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

char	*my_strncat(char *dest, char const *src, size_t nb)
{
	size_t	len;

	len = my_strlen(dest);
	my_strncpy(dest + len, src, nb);
	return (dest);
}
