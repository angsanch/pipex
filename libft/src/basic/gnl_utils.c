/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 04:47:43 by angsanch          #+#    #+#             */
/*   Updated: 2024/08/05 04:47:45 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

t_file_buffer	*gnl_buffer_holder(void)
{
	static t_file_buffer	files[FOPEN_MAX] = {{NULL, 0, NULL, 0}};

	return (files);
}

void	gnl_flush(void)
{
	t_file_buffer	*files;
	size_t			i;

	files = gnl_buffer_holder();
	i = 0;
	while (i < FOPEN_MAX)
	{
		free(files[i].buffer);
		files[i].buffer = NULL;
		i ++;
	}
}
