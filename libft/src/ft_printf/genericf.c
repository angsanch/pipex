/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genericf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:56:08 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/22 14:33:10 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/my_printf_utils.h"
#include "../../include/basic.h"

int	string_parameter(t_parameter *param, va_list *ap, int *n)
{
	int			index;
	const char	*specifiers = "diuoxXcspn%";
	static void	(*param_str[])(t_parameter *param, va_list *ap, int n) = {
		&signed_decimal_integer, &signed_decimal_integer,
		&unsigned_decimal_integer, &unsigned_decimal_integer,
		&unsigned_decimal_integer, &unsigned_decimal_integer,
		&character_print, &string_print,
		&pointer_print, &length_exporter,
		&print_percentage
	};

	index = my_strchr_index(specifiers, param->specifier);
	if (index == -1)
		return (0);
	if (param->width == -1)
		param->width = va_arg(*ap, int);
	if (param->precision == -2)
		param->precision = va_arg(*ap, int);
	param_str[index](param, ap, *n);
	*n += param->len;
	return (1);
}

static t_list	*parse_format(char const *format, va_list *ap, int *n)
{
	int			i;
	t_list		*params;
	t_parameter	*new;

	i = 0;
	params = list_create((void *)&destroy_param);
	if (params == NULL)
		return (NULL);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
		{
			i ++;
			*n += 1;
			continue ;
		}
		new = parse_parameter(format, &i);
		if (new == NULL || !list_append(params, new))
			return (NULL);
		string_parameter(new, ap, n);
		if (new->str == NULL)
			return (NULL);
	}
	return (params);
}

void	prepare_result(char *result, t_list *params, char const *format)
{
	int			i;
	int			n;
	t_parameter	*param;

	i = 0;
	n = 0;
	while (format[i])
	{
		if (format[i] != '%' && format[i])
		{
			result[n] = format[i];
			i ++;
			n ++;
			continue ;
		}
		param = list_get_index(params, 0);
		my_memcpy(result + n, param->str, param->len);
		n += param->len;
		i += param->characters;
		list_pop_first(params);
	}
	result[n] = '\0';
}

int	genericf(char **output, char const *format, va_list *ap)
{
	int		n;
	t_list	*params;
	char	*result;

	n = 0;
	params = parse_format(format, ap, &n);
	if (params == NULL)
	{
		*output = NULL;
		return (-1);
	}
	result = malloc(sizeof(char) * (n + 1));
	if (result != NULL)
		prepare_result(result, params, format);
	list_destroy(params);
	*output = result;
	return (n);
}
