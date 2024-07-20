/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:53 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 00:09:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

static t_elem	*elem_advance(t_elem *e, size_t steps)
{
	size_t	i;

	i = 0;
	while (i < steps)
	{
		e = e->next;
		i ++;
	}
	return (e);
}

static void	merge_lists(t_elem **head, size_t left_size, size_t right_size,
	int (*comp)(void *, void *))
{
	struct s_side_pointers	sides;

	sides.left = *head;
	sides.right = elem_advance(sides.left, left_size);
	while (left_size * right_size != 0)
	{
		if (comp(sides.left->content, sides.right->content) <= 0)
		{
			(*head) = sides.left;
			head = &(*head)->next;
			sides.left = sides.left->next;
			left_size --;
		}
		else
		{
			(*head) = sides.right;
			head = &(*head)->next;
			sides.right = sides.right->next;
			right_size --;
		}
	}
	if (left_size == 0)
		*head = sides.right;
	if (right_size == 0)
		*head = sides.left;
}

static void	merge_sort(t_elem **first, size_t size,
	int (*comp)(void *, void *))
{
	size_t	left_size;
	size_t	right_size;
	t_elem	**center;
	t_elem	*end;

	left_size = size / 2;
	right_size = size - left_size;
	end = elem_advance(*first, size);
	if (size == 1)
		return ;
	merge_sort(first, left_size, comp);
	center = &elem_advance(*first, left_size - 1)->next;
	merge_sort(center, right_size, comp);
	merge_lists(first, left_size, right_size, comp);
	elem_advance(*first, size - 1)->next = end;
}

int	list_sort(t_list *l, int (*comp)(void *, void *))
{
	if (l->len < 2)
		return (1);
	merge_sort(&l->first, l->len, comp);
	return (1);
}
