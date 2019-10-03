/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:13:52 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/30 21:53:12 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_nb(t_format *format)
{
	long long	nb;

	nb = 0;
	if (format->byte_size == 0)
		nb = va_arg(format->valst, int);
	else if (format->byte_size == 'l')
		nb = va_arg(format->valst, long);
	else if (format->byte_size == 'L')
		nb = va_arg(format->valst, long long);
	else if (format->byte_size == 'h')
		nb = (short)va_arg(format->valst, int);
	else if (format->byte_size == 'H')
		nb = (char)va_arg(format->valst, int);
	return (nb);
}

char	*flag_int(t_format *format)
{
	char		*res;
	long long	va_int;

	va_int = get_nb(format);
	if (!(res = ft_itoa(va_int)))
		return (NULL);
	return (res);
}
