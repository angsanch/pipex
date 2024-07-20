/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:16:43 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/22 14:40:12 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic.h"
#include "../../include/my_printf_utils.h"

void	print_percentage(t_parameter *param, va_list *ap, int n)
{
	(void)ap;
	(void)n;
	param->str = my_strdup("%");
	param->len = 1;
}

void	character_print(t_parameter *param, va_list *ap, int n)
{
	(void)n;
	param->len = 1;
	if (param->width > 1)
		param->len = param->width;
	param->str = malloc(sizeof(char) * (param->len + 1));
	if (param->str == NULL)
		return ;
	if (param->flags[0])
	{
		param->str[0] = (char)va_arg(*ap, int);
		my_memset(param->str + 1, ' ', param->len - 1);
	}
	else
	{
		my_memset(param->str, ' ', param->len - 1);
		param->str[param->len - 1] = (char)va_arg(*ap, int);
	}
	param->str[param->len] = '\0';
}

void	length_exporter(t_parameter *param, va_list *ap, int n)
{
	if (param->length == 0)
		*(va_arg(*ap, int *)) = n;
	if (param->length == 1)
		*(va_arg(*ap, signed char *)) = n;
	if (param->length == 2)
		*(va_arg(*ap, short int *)) = n;
	if (param->length == 3)
		*(va_arg(*ap, long int *)) = n;
	if (param->length == 4)
		*(va_arg(*ap, long long int *)) = n;
	if (param->length == 5)
		*(va_arg(*ap, intmax_t *)) = n;
	if (param->length == 6)
		*(va_arg(*ap, size_t *)) = n;
	if (param->length == 7)
		*(va_arg(*ap, ptrdiff_t *)) = n;
	param->str = my_strdup("");
	param->len = 0;
}
