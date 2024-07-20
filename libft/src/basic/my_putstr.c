/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:36 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:36 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	my_putstr(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, str + i, 1);
		i ++;
	}
	return (i);
}
