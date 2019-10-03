/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:23:37 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/30 21:29:44 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_nb(t_format *format)
{
	unsigned long long	nb;

	nb = 0;
	if (format->byte_size == 0)
		nb = va_arg(format->valst, unsigned int);
	else if (format->byte_size == 'l')
		nb = va_arg(format->valst, unsigned long);
	else if (format->byte_size == 'L')
		nb = va_arg(format->valst, unsigned long long);
	else if (format->byte_size == 'h')
		nb = (unsigned short)va_arg(format->valst, unsigned int);
	else if (format->byte_size == 'H')
		nb = (unsigned char)va_arg(format->valst, unsigned int);
	return (nb);
}

char	*flag_uint(t_format *format)
{
	unsigned long long va_int;

	va_int = get_nb(format);
	return (ft_itoa_base(va_int, 10));
}
