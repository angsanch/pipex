/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:52 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 00:10:50 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

size_t	list_len(t_list *l)
{
	t_elem	*e;
	size_t	i;

	e = l->first;
	i = 0;
	while (e != NULL)
	{
		e = e->next;
		i ++;
	}
	return (i);
}

t_elem	*list_get_last(t_list *l)
{
	t_elem	*e;

	e = l->first;
	if (e == NULL)
		return (NULL);
	while (e->next != NULL)
		e = e->next;
	return (e);
}

void	list_pop_first(t_list *l)
{
	t_elem	*e;

	e = l->first;
	l->first = e->next;
	destroy_elem(e, l->del);
	l->len --;
}

t_elem	*list_get_index_elem(t_list *l, size_t index)
{
	t_elem	*e;
	size_t	i;

	e = l->first;
	i = 0;
	while (e != NULL && i < index)
	{
		i ++;
		e = e->next;
	}
	return (e);
}

void	*list_get_index(t_list *l, size_t index)
{
	t_elem	*e;

	e = list_get_index_elem(l, index);
	if (e == NULL)
		return (NULL);
	else
		return (e->content);
}
