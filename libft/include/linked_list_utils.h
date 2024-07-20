/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:49:14 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 20:27:07 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_UTILS_H
# define LINKED_LIST_UTILS_H

# include <stdlib.h>
# include "linked_list.h"

//not necesary but i needed to save lines
struct s_side_pointers
{
	t_elem	*left;
	t_elem	*right;
};

void		initialize_elem(t_elem *e, void *content);
t_elem		*create_elem(void *content);
void		delete_elem(t_elem *e, void (*del)(void *));
void		destroy_elem(t_elem *e, void (*del)(void *));
void		destroy_list(t_list *l);
t_elem		*list_get_last(t_list *l);
t_elem		*list_get_index_elem(t_list *l, size_t index);
t_list		*create_list(void (*del)(void *));
size_t		list_len(t_list *l);

#endif
