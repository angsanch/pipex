/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:49:17 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 20:12:51 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PRINTF_UTILS_H
# define MY_PRINTF_UTILS_H

# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "linked_list.h"
# include "basic.h"

typedef unsigned long long int	t_llu;
typedef long long int			t_lld;

typedef struct integer_data
{
	char	*parsed_number;
	char	sign[3];
	size_t	min_len;
}	t_ints;

//flags "-+ #0"
typedef struct data_parameter
{
	char	specifier;
	bool	flags[5];
	int		width;
	int		precision;
	int		length;
	size_t	characters;
	char	*str;
	size_t	len;
}	t_parameter;

int			ft_printf(char const *format, ...);
int			genericf(char **result, char const *format, va_list *ap);
t_parameter	*parse_parameter(char const *format, int *i);
void		destroy_param(t_parameter *p);
char		*prepare_parts(t_parameter *param, char *sign, char *number);
t_lld		get_lld(int length, va_list *ap);
t_llu		get_llu(int length, va_list *ap);
void		set_sign(t_parameter *param, int plus, char *sign);
void		set_base(char specifier, char *base);
char		*my_lluitoa_base(unsigned long long int nb, char const *base,
				int min_len);
t_parameter	*create_param(void);

void		signed_decimal_integer(t_parameter *param, va_list *ap, int n);
void		unsigned_decimal_integer(t_parameter *param, va_list *ap, int n);
void		length_exporter(t_parameter *param, va_list *ap, int n);
void		character_print(t_parameter *param, va_list *ap, int n);
void		string_print(t_parameter *param, va_list *ap, int n);
void		pointer_print(t_parameter *param, va_list *ap, int n);
void		length_exporter(t_parameter *param, va_list *ap, int n);
void		print_percentage(t_parameter *param, va_list *ap, int n);

#endif
