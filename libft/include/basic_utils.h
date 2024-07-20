/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:49:13 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 19:40:40 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_UTILS_H
# define BASIC_UTILS_H

# include "basic.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 128
# endif

typedef struct file_buffer_t_container
{
	char	*buffer;
	size_t	buff_len;
	char	*line;
	ssize_t	len;
}	t_file_buffer;

typedef struct coolersplit_sizes
{
	size_t	base_len;
	size_t	key_len;
	size_t	repl_len;
	size_t	coins;
}	t_sizes;

typedef struct coolersplit_context
{
	char const	*str;
	char const	*separators;
	ssize_t		word_count;
	char		**result;
	size_t		offset;
	char		on_block;
}	t_splited;

void	*delete_t_splited(t_splited *spl, int delete_result);
void	copy_without_quotations(char *dst, char const *src, size_t n);

#endif
