/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:25 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_memchr_index(const void *m, int c, int len)
{
	int				i;
	unsigned char	chr;
	const char		*s;

	i = 0;
	chr = c;
	s = m;
	while (i < len)
	{
		if (s[i] == chr)
			break ;
		i ++;
	}
	if (i >= len)
		return (-1);
	if (s[i] == chr)
		return (i);
	else
		return (-1);
}
