/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:05:16 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/07 01:07:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/my_printf_utils.h"

t_parameter	*create_param(void)
{
	int			i;
	t_parameter	*p;

	i = 0;
	p = malloc(sizeof(t_parameter) * 1);
	if (p == NULL)
		return (NULL);
	p->specifier = 0;
	while (i < 5)
	{
		p->flags[i] = 0;
		i ++;
	}
	p->width = 0;
	p->precision = -1;
	p->length = 0;
	p->str = NULL;
	p->len = 0;
	return (p);
}

void	destroy_param(t_parameter *p)
{
	free(p->str);
	free(p);
}
