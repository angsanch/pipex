/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:01:39 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/22 14:50:57 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/my_printf_utils.h"
#include "../../include/basic.h"

void	signed_decimal_integer(t_parameter *param, va_list *ap, int n)
{
	long long int			num;
	unsigned long long int	nb;
	t_ints					data;

	(void)n;
	num = get_lld(param->length, ap);
	nb = num;
	data.min_len = param->precision;
	if (num < 0)
		nb = -num;
	set_sign(param, num >= 0, data.sign);
	if (param->flags[4] && !param->flags[0])
		data.min_len = param->width - my_strlen(data.sign);
	data.parsed_number = my_lluitoa_base(nb, "0123456789", data.min_len);
	if (data.parsed_number == NULL)
		return ;
	param->str = prepare_parts(param, data.sign, data.parsed_number);
	free(data.parsed_number);
	param->len = my_strlen(param->str);
}

void	unsigned_decimal_integer(t_parameter *param, va_list *ap, int n)
{
	unsigned long long int	num;
	char					base[17];
	t_ints					data;

	(void)n;
	num = get_llu(param->length, ap);
	data.min_len = param->precision;
	set_sign(param, 1, data.sign);
	if (num == 0)
		data.sign[0] = 0;
	set_base(param->specifier, base);
	if (param->flags[4])
		data.min_len = param->width;
	data.parsed_number = my_lluitoa_base(num, base, data.min_len);
	if (data.parsed_number == NULL)
		return ;
	param->str = prepare_parts(param, data.sign, data.parsed_number);
	free(data.parsed_number);
	param->len = my_strlen(param->str);
}

void	pointer_print(t_parameter *param, va_list *ap, int n)
{
	unsigned long long int	ptr;
	char					*parsed_number;
	char					sign[4];

	(void)n;
	ptr = (unsigned long long int)va_arg(*ap, void *);
	my_strcpy(sign, "+0x");
	parsed_number = my_lluitoa_base(ptr, "0123456789abcdef", param->precision);
	if (parsed_number == NULL)
		return ;
	if (!param->flags[1])
	{
		if (param->flags[2])
			sign[0] = ' ';
	}
	param->str = prepare_parts(param, sign + 1 - param->flags[2],
			parsed_number);
	free(parsed_number);
	param->len = my_strlen(param->str);
}
