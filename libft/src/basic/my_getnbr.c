/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:23 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:23 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic.h"

int	my_intlen(int nb)
{
	return (my_intlen_base(nb, 10));
}

int	my_getnbr(char const *str)
{
	long	result;
	long	n;
	int		i;
	int		multiplicator;

	result = 0;
	i = 0;
	multiplicator = 1;
	while (!my_isnumeric(str[i]))
	{
		if (str[i] != '+' && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] == '-')
			multiplicator *= -1;
		i ++;
	}
	while (my_isnumeric(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		n = result * multiplicator;
		if (n > 2147483647 || n < -2147483648)
			return (0);
		i ++;
	}
	return (result * multiplicator);
}
