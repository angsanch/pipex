/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:51 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:45:51 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

int	list_append(t_list *l, void *content)
{
	t_elem	*last;
	t_elem	*e;

	last = list_get_last(l);
	e = create_elem(content);
	if (e == NULL)
		return (0);
	if (last == NULL)
		l->first = e;
	else
		last->next = e;
	l->len ++;
	return (1);
}

int	list_push(t_list *l, void *content)
{
	t_elem	*e;

	e = create_elem(content);
	if (e == NULL)
		return (0);
	e->next = l->first;
	l->first = e;
	l->len ++;
	return (1);
}

int	list_insert(t_list *l, size_t index, void *content)
{
	t_elem	*e;
	t_elem	*prev;

	if (index == 0)
		return (list_push(l, content));
	prev = list_get_index_elem(l, index - 1);
	if (prev == NULL)
		return (0);
	e = create_elem(content);
	if (e == NULL)
		return (0);
	e->next = prev->next;
	prev->next = e;
	l->len ++;
	return (1);
}

int	list_pop(t_list *l, size_t index)
{
	t_elem	*prev;
	t_elem	*deletion;

	if (index == 0)
	{
		list_pop_first(l);
		return (1);
	}
	prev = list_get_index_elem(l, index - 1);
	if (prev == NULL)
		return (0);
	deletion = prev->next;
	prev->next = deletion->next;
	destroy_elem(deletion, l->del);
	l->len --;
	return (1);
}

void	list_unlink(t_list *l)
{
	t_elem	*e;
	t_elem	*next;

	e = l->first;
	next = NULL;
	while (e != NULL)
	{
		next = e->next;
		free(e);
		e = next;
	}
	l->len = 0;
}
