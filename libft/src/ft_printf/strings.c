/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:27:36 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/22 14:53:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/my_printf_utils.h"
#include "../../include/basic.h"

static char	*strt2str(wchar_t *strt)
{
	size_t	i;
	char	*str;

	i = 0;
	while (strt[i] == 0)
		i ++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (strt[i] == 0)
	{
		str[i] = (char)strt[i];
		i ++;
	}
	str[i] = 0;
	return (str);
}

static char	*get_string(t_parameter *param, va_list *ap)
{
	char		*str;
	char		*temp;
	const char	*null_str = "(null)";
	wchar_t		*wtemp;

	if (param->length == 3)
	{
		wtemp = va_arg(*ap, wchar_t *);
		if (wtemp == NULL)
			str = my_strdup(null_str);
		else
			str = strt2str(wtemp);
	}
	else
	{
		temp = va_arg(*ap, char *);
		if (temp == NULL)
			str = my_strdup(null_str);
		else
			str = my_strdup(temp);
	}
	return (str);
}

static char	*complex_string(t_parameter *param, char *str, int len)
{
	char	*result;

	result = malloc(sizeof(char) * (param->width + 1));
	if (result == NULL)
		return (NULL);
	if (param->flags[0])
	{
		my_strcpy(result, str);
		my_memset(result + len, ' ', param->width - len);
		result[param->width] = 0;
	}
	else
	{
		my_memset(result, ' ', param->width - len);
		my_strcpy(result + param->width - len, str);
	}
	return (result);
}

void	string_print(t_parameter *param, va_list *ap, int n)
{
	int		len;
	char	*str;

	(void)n;
	str = get_string(param, ap);
	if (str == NULL)
		return ;
	len = my_strlen(str);
	if (param->precision < len && param->precision >= 0)
	{
		str[param->precision] = '\0';
		len = param->precision;
	}
	if (len >= param->width)
		param->str = str;
	else
	{
		param->str = complex_string(param, str, my_strlen(str));
		free(str);
	}
	param->len = my_strlen(param->str);
}
