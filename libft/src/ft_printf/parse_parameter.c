/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:40:31 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/16 00:05:48 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/my_printf_utils.h"
#include "../../include/basic.h"

static char	flags_called(char const *format, t_parameter *p, int i)
{
	int			index;
	const char	*flags = "-+ #0";

	index = my_strchr_index(flags, format[i]);
	while (index != -1)
	{
		p->flags[index] = 1;
		index = my_strchr_index(flags, format[i]);
		if (index >= 0)
			i++;
	}
	return (i);
}

static char	width_called(char const *format, t_parameter *p, int i)
{
	if (format[i] == '*')
	{
		p->width = -1;
		return (i + 1);
	}
	if (!my_isnumeric(format[i]))
		return (i);
	p->width = my_str_isnum(format + i);
	return (my_intlen(p->width) + i);
}

static int	precision_called(char const *format, t_parameter *p, int i)
{
	if (format[i] != '.')
		return (i);
	i++;
	if (format[i] == '*')
	{
		p->precision = -2;
		return (i + 1);
	}
	if (!my_isnumeric(format[i]))
	{
		p->precision = 0;
		return (i);
	}
	p->precision = my_getnbr(format + i);
	return (my_intlen(p->precision) + i);
}

static int	length_called(char const *format, t_parameter *p, int i)
{
	p->length = my_strchr_index("hhlljztL", format[i]) + 1;
	if (p->length == 0)
		return (i);
	if (p->length == 1)
	{
		if (format[i + 1] != 'h')
		{
			p->length ++;
			return (i + 1);
		}
		else
			return (i + 2);
	}
	if (p->length == 3)
	{
		if (format[i + 1] != 'l')
			return (i + 1);
		else
		{
			p->length ++;
			return (i + 2);
		}
	}
	return (i + p->length != 0);
}

t_parameter	*parse_parameter(char const *format, int *i)
{
	t_parameter	*data;

	data = create_param();
	if (data == NULL)
		return (NULL);
	data->characters = *i;
	*i += 1;
	*i = flags_called(format, data, *i);
	*i = width_called(format, data, *i);
	*i = precision_called(format, data, *i);
	*i = length_called(format, data, *i);
	data->specifier = format[*i];
	if (format[*i] != '\0')
		*i += 1;
	data->characters = *i - data->characters;
	return (data);
}
