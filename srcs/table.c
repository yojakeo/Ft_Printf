/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:35:34 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/20 22:49:34 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define CONVS "csp%diouxXfbrk"

/*
**	Dispatch table that calls the correct conversion. Uses a string to find the
**	conversion from an index. (csp%diouxXfbrk)
*/

char	*table(int index, t_format *format, t_obuf *buff)
{
	static char	*(*p[])() = {
		[0] = flag_char,
		[1] = flag_string,
		[2] = flag_pointer,
		[3] = flag_percent,
		[4] = flag_int,
		[5] = flag_int,
		[6] = flag_oct,
		[7] = flag_uint,
		[8] = flag_float,
		[9] = flag_hex,
		[10] = flag_hex,
		[11] = flag_binary,
	};
	return (p[index](format, buff));
}

char	*flag_char(t_format *format, t_obuf *buff)
{
	char	c;
	char	*res;

	c = (char)va_arg(format->va->valst, int);
	if (!(res = ft_strdup(c)))
		return (NULL);
	return (res);	
}

char	*flag_string(t_format *format, t_obuf *buff)
{
	char	*res;
	char	*str;

	str = va_arg(format->va->valst, char *);
	if (!str)
		str = "(null)";
	if (!(res = ft_strdup(str)))
		return (NULL);
	return (res);
}

char	*flag_pointer(t_format *format, t_obuf *buff)
{
	char	*res;
	va_int = va_arg(format->va->valst, unsigned long long);

	return (res);
}

char	*flag_percent(t_format *format, t_obuf *buff)
{
	char	*res;
	res = ft_strdup("%");
	return (res);
}

char	*flag_int(t_format *format, t_obuf *buff)
{
	char		*res;
	long long	va_int;

	va_int = va_arg(format->va->valst, long long);
	return (ft_itoa(va_int));
}

char	*flag_oct(t_format *format, t_obuf *buff)
{
	char				*res;
	unsigned long long	va_int;

	va_int = va_arg(format->va->valst, unsigned long long);
	return (ft_itoa_base(va_int, 8));
	return (res);
}

char	*flag_uint(t_format *format, t_obuf *buff)
{
	char	*res;


	return (res);
}

char	*flag_float(t_format *format, t_obuf *buff)
{
	char	*res;


	return (res);
}

char	*flag_hex(t_format *format, t_obuf *buff)
{
	char				*res;
	unsigned long long	va_int;

	va_int = va_arg(format->va->valst, unsigned long long);
	return (ft_itoa_base(va_int, 16));
	return (res);
}

char	*flag_binary(t_format *format, t_obuf *buff)
{
	char				*res;
	unsigned long long	va_int;

	va_int = va_arg(format->va->valst, unsigned long long);
	return (ft_itoa_base(va_int, 2));
	return (res);
}
