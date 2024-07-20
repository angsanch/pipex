/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:45:37 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 22:20:55 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic.h"
#include "../../include/my_printf_utils.h"

int	my_printf(char const *format, ...)
{
	va_list	ap;
	char	*result;
	int		len;

	va_start(ap, format);
	len = genericf(&result, format, &ap);
	va_end(ap);
	if (result == NULL)
		return (-1);
	write(1, result, len);
	free(result);
	return (len);
}

int	my_sprintf(char *str, char const *format, ...)
{
	va_list	ap;
	char	*result;
	int		len;

	va_start(ap, format);
	len = genericf(&result, format, &ap);
	va_end(ap);
	if (result == NULL)
		return (-1);
	my_memcpy(str, result, len + 1);
	free(result);
	return (len);
}

int	my_sbufferf(char **str, char const *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = genericf(str, format, &ap);
	va_end(ap);
	if (*str == NULL)
		return (-1);
	return (len);
}

int	my_dprintf(int fd, char const *format, ...)
{
	va_list	ap;
	char	*result;
	int		len;

	va_start(ap, format);
	len = genericf(&result, format, &ap);
	va_end(ap);
	if (result == NULL)
		return (-1);
	write(fd, result, len);
	free(result);
	return (len);
}
