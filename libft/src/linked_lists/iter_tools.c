/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:50 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:45:50 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

void	**list_export(t_list *l, void *(*transform)(void *))
{
	void	**export;
	size_t	i;
	t_elem	*e;

	i = 0;
	if (l->len == 0)
		return (NULL);
	export = malloc(sizeof(char *) * (l->len + 1));
	if (export == NULL)
		return (NULL);
	e = l->first;
	while (i < l->len)
	{
		if (transform == NULL)
			export[i] = e->content;
		else
			export[i] = transform(e->content);
		e = e->next;
		i ++;
	}
	export[l->len] = NULL;
	return (export);
}

void	list_import(t_list *l, void **data)
{
	size_t	i;
	t_elem	*e;

	i = 0;
	e = l->first;
	while (i < l->len)
	{
		e->content = data[i];
		e = e->next;
		i ++;
	}
}

void	list_iter(t_list *l, void (*func)(void *, void *), void *data)
{
	t_elem	*next;
	t_elem	*e;

	next = l->first;
	e = NULL;
	while (next != NULL)
	{
		e = next;
		next = e->next;
		(*func)(e->content, data);
	}
}

ssize_t	list_first_fulfil(t_list *l, int (*func)(void *, void *), void *data)
{
	t_elem	*e;
	size_t	i;

	e = l->first;
	i = 0;
	while (e != NULL)
	{
		if (func(e->content, data))
			return (i);
		e = e->next;
		i ++;
	}
	return (-1);
}

size_t	list_count_fulfil(t_list *l, int (*func)(void *, void *), void *data)
{
	t_elem	*e;
	size_t	count;

	e = l->first;
	count = 0;
	while (e != NULL)
	{
		if (func(e->content, data))
			count ++;
		e = e->next;
	}
	return (count);
}
