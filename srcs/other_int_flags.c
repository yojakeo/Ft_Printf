/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_int_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:20:39 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/30 19:40:30 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*flag_oct(t_format *format)
{
	unsigned long long	va_int;

	va_int = va_arg(format->valst, unsigned long long);
	return (ft_itoa_base(va_int, 8));
}

char	*flag_hex(t_format *format)
{
	unsigned long long	va_int;
	char *res;

	va_int = va_arg(format->valst, unsigned long long);
	if (!(res = ft_itoa_base(va_int, 16)))
		return (NULL);
	if (format->input[format->i] == 'X')
		ft_strtoupper(res);
	return (res);
}

char	*flag_binary(t_format *format)
{
	unsigned long long	va_int;

	va_int = va_arg(format->valst, unsigned long long);
	return (ft_itoa_base(va_int, 2));
}
