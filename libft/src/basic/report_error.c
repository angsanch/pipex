/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:47:03 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:47:09 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

int	report_error(char *str, int response)
{
	write(2, str, my_strlen(str));
	return (response);
}
