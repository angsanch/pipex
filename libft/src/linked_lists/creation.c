/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:46 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:45:46 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

void	initialize_elem(t_elem *e, void *content)
{
	if (e == NULL)
		return ;
	e->next = NULL;
	e->content = content;
}

t_elem	*create_elem(void *content)
{
	t_elem	*e;

	e = malloc(sizeof(t_elem) * 1);
	initialize_elem(e, content);
	return (e);
}

void	list_initialize(t_list *l, void (*del)(void *))
{
	l->len = 0;
	l->first = NULL;
	l->del = del;
}

t_list	*list_create(void (*del)(void *))
{
	t_list	*l;

	l = malloc(sizeof(t_list) * 1);
	if (l == NULL)
		return (NULL);
	list_initialize(l, del);
	return (l);
}
