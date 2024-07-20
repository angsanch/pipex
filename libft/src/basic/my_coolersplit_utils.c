/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_coolersplit_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:44:57 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 01:45:03 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

void	copy_without_quotations(char *dst, char const *src, size_t n)
{
	size_t	d;
	size_t	s;
	char	p_block;
	char	block;
	char	l;

	d = 0;
	s = 0;
	p_block = 0;
	block = 0;
	while (s < n)
	{
		p_block = block;
		l = src[s];
		if (block == 0 && (l == '\'' || l == '\"'))
		{
			block = 0;
			l = 0;
		}
		if (p_block == block)
			dst[d] = src[s];
		d += p_block == block;
		s ++;
	}
	dst[d] = '\0';
}

void	*delete_t_splited(t_splited *spl, int delete_result)
{
	if (spl == NULL)
		return (NULL);
	if (delete_result)
		free_string_array(spl->result);
	return (NULL);
}
