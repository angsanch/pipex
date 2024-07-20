/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:49 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:45:49 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

void	delete_elem(t_elem *e, void (*del)(void *))
{
	if (e == NULL)
		return ;
	(*del)(e->content);
	e->next = NULL;
	e->content = NULL;
}

void	destroy_elem(t_elem *e, void (*del)(void *))
{
	delete_elem(e, del);
	free(e);
}

void	list_delete(t_list *l)
{
	size_t	i;
	t_elem	*current;

	i = 0;
	if (l == NULL)
		return ;
	while (i < l->len)
	{
		current = l->first;
		l->first = l->first->next;
		destroy_elem(current, l->del);
		i ++;
	}
	l->len = 0;
	l->first = NULL;
	l->del = NULL;
}

t_list	*list_destroy(t_list *l)
{
	list_delete(l);
	free(l);
	return (NULL);
}
