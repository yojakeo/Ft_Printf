/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:36:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/10/31 21:00:03 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*format_pointer(t_format *fmt, int len)
{
	char *res;

	fmt->width = (fmt->width < len) ? len : fmt->width;
	fmt->precision = len;
	if (fmt->pos_flag || fmt->space_flag)
	{
		++fmt->precision;
		if (fmt->width == len)
			++fmt->width;
	}
	if (fmt->zero_flag)
		fmt->precision = fmt->width;
	if ((fmt->width - len) >= 1)
		res = (char *)malloc(fmt->width - len);
	else
		return (ft_strnew(0));
	if (res && fmt->zero_flag)
		ft_memset(res, '0', (fmt->width - len) + 1);
	else if (res)
		ft_memset(res, ' ', (fmt->width - len) + 1);
	if (res)
		res[fmt->width - len] = '\0';
	return (res);
}

/*
**	The function that handles int flag conversion.
**	Logic:
**	Grabs varg with proper byte sizing.
**	Finds len with Precision consideration if 0.
**	Uses itoa for int conversion. If neg it will treated as a positive.
**	Allocs int padding with flag consideration.
**	Joins the two strings together with alignment.
**	Handles placement of flags and sign placement.
**	Free and return res to be joined with the buffer.
*/

char				*flag_pointer(t_format *fmt)
{
	char				*res;
	char				*itoares;
	char				*formatres;
	unsigned long long	va_ptr;
	int					len;

	va_ptr = va_arg(fmt->valst, unsigned long long);
	len = ft_intlen_base(va_ptr, 16) + 2;
	itoares = ft_itoa_base(va_ptr, 16);
	res = ft_strjoin("0x", res);
	ft_strdel(&itoares);
	itoares = res;
	formatres = format_pointer(fmt, len);
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, itoares);
	else
		res = ft_strjoin(itoares, formatres);
	ft_strdel(&res);
	res = res;
	ft_strdel(&itoares);
	ft_strdel(&formatres);
	return (res);
}
