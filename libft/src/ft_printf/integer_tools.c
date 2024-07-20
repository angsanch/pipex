/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:48:42 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/16 00:29:04 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/my_printf_utils.h"
#include "../../include/basic.h"

static size_t	numlen_base(unsigned long long int nb, size_t base_size)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base_size;
		size ++;
	}
	return (size);
}

char	*my_lluitoa_base(unsigned long long int nb, char const *base,
		int min_len)
{
	int		i;
	int		base_size;
	int		num_size;
	char	*result;

	i = 0;
	base_size = my_strlen(base);
	num_size = numlen_base(nb, base_size);
	if (min_len < 0)
		min_len = 1;
	if (num_size < min_len)
		num_size = min_len;
	num_size *= !(min_len == 0 && nb == 0);
	result = malloc(sizeof(char) * (num_size + 1));
	if (result == NULL)
		return (NULL);
	my_memset(result, '0', num_size);
	while (i < num_size)
	{
		result[num_size - i - 1] = base[nb % base_size];
		nb /= base_size;
		i ++;
	}
	result[num_size] = '\0';
	return (result);
}

char	*prepare_parts(t_parameter *param, char *sign, char *number)
{
	size_t	len;
	size_t	min_len;
	size_t	used;
	char	*result;

	len = my_strlen(sign) + my_strlen(number);
	min_len = param->width;
	used = min_len;
	if (len > min_len)
		used = len;
	result = my_calloc(sizeof(char), used + 1);
	if (result == NULL)
		return (NULL);
	if (!param->flags[0])
		my_memset(result, ' ', used - len);
	result[used - len] = '\0';
	my_strcat(result, sign);
	my_strcat(result, number);
	if (param->flags[0])
		my_memset(result + my_strlen(result), ' ', used - len);
	result[used] = '\0';
	return (result);
}

void	set_sign(t_parameter *param, int plus, char *sign)
{
	my_memset(sign, '\0', 3);
	if (!plus)
		sign[0] = '-';
	if (param->flags[1] && plus)
		sign[0] = '+';
	if (param->flags[2] && sign[0] == 0)
		sign[0] = ' ';
	if (param->flags[3])
	{
		if (param->specifier == 'o')
			my_strcpy(sign, "0");
		if (param->specifier == 'x')
			my_strcpy(sign, "0x");
		if (param->specifier == 'X')
			my_strcpy(sign, "0X");
	}
}

void	set_base(char specifier, char *base)
{
	if (specifier == 'u')
		my_strcpy(base, "0123456789");
	if (specifier == 'o')
		my_strcpy(base, "01234567");
	if (specifier == 'x')
		my_strcpy(base, "0123456789abcdef");
	if (specifier == 'X')
		my_strcpy(base, "0123456789ABCDEF");
}
