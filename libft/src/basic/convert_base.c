/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:15 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:15 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

static size_t	int_len_base(int nbr, int base)
{
	size_t			i;
	unsigned int	n;

	i = 0;
	n = nbr;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i ++;
		n = -nbr;
	}
	while (n > 0)
	{
		n /= base;
		i ++;
	}
	return (i);
}

char	*convert_base(char const *nbr, char const *base_from,
	char const *base_to)
{
	int				nb;
	unsigned int	n;
	int				len_base;
	int				result_len;
	char			*result;

	nb = my_getnbr_base(nbr, base_from);
	n = nb;
	len_base = my_strlen(base_to);
	result_len = int_len_base(n, len_base);
	result = malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	if (nb < 0)
		n = -nb;
	result[0] = '-';
	nb = 0;
	while (n > 0 || nb < 1)
	{
		result[result_len - nb - 1] = base_to[n % len_base];
		n /= len_base;
		nb ++;
	}
	result[result_len] = 0;
	return (result);
}
