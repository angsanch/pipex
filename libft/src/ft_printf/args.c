/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:39:38 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 21:50:02 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/my_printf_utils.h"
#include <stddef.h>

long long int	get_lld(int length, va_list *ap)
{
	if (length <= 2)
		return ((long long int)va_arg(*ap, int));
	if (length == 3)
		return ((long long int)va_arg(*ap, long int));
	if (length == 4)
		return ((long long int)va_arg(*ap, long long int));
	if (length == 5)
		return ((long long int)va_arg(*ap, intmax_t));
	if (length == 6)
		return ((long long int)va_arg(*ap, size_t));
	if (length == 7)
		return ((long long int)va_arg(*ap, ptrdiff_t));
	return ((long long int)va_arg(*ap, long int));
}

unsigned long long int	get_llu(int length, va_list *ap)
{
	if (length <= 2)
		return ((unsigned long long int)va_arg(*ap, unsigned int));
	if (length == 3)
		return ((unsigned long long int)va_arg(*ap, unsigned long int));
	if (length == 4)
		return ((unsigned long long int)va_arg(*ap, unsigned long long int));
	if (length == 5)
		return ((unsigned long long int)va_arg(*ap, uintmax_t));
	if (length == 6)
		return ((unsigned long long int)va_arg(*ap, size_t));
	if (length == 7)
		return ((unsigned long long int)va_arg(*ap, ptrdiff_t));
	return ((unsigned long long int)va_arg(*ap, unsigned long int));
}
