/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:23:37 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/05 19:16:17 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Grabs the value with the correct size.
*/

static unsigned long long	get_nb(t_format *fmt)
{
	unsigned long long	va_int;

	va_int = 0;
	if (fmt->varg_size == 0)
		va_int = va_arg(fmt->valst, unsigned int);
	else if (fmt->varg_size == 'l')
		va_int = va_arg(fmt->valst, unsigned long);
	else if (fmt->varg_size == 'L')
		va_int = va_arg(fmt->valst, unsigned long long);
	else if (fmt->varg_size == 'h')
		va_int = (unsigned short)va_arg(fmt->valst, unsigned int);
	else if (fmt->varg_size == 'H')
		va_int = (unsigned char)va_arg(fmt->valst, unsigned int);
	return (va_int);
}

/*
**	Does the math to find the size of the string to allocate.
**	Ensures that width is as wide or wider than the len of the number.
**	Checks for needed additional space for pos and space flags.
**	Creates the padding string with the proper set of chars with NULL.
*/

static char					*format_uint(t_format *fmt, int len)
{
	char *res;

	fmt->width = (fmt->width < len) ? len : fmt->width;
	fmt->precision = len;
	if (fmt->zero_flag && !fmt->pre_flag)
		fmt->precision = fmt->width;
	if (fmt->zero_flag && fmt->pre_flag)
		fmt->zero_flag = 0;
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
**	Creates the number string and takes in precision to correctly size it.
*/

static char					*handle_uint(t_format *fmt, \
							unsigned long long va_int, int *len)
{
	char	*res;
	char	*itoares;
	char	*preres;

	if (fmt->neg_flag && fmt->zero_flag)
		fmt->zero_flag = 0;
	itoares = ft_itoa_base(va_int, 10);
	if (fmt->pre_flag && fmt->precision == 0)
	{
		*len = fmt->precision;
		return (ft_strnew(0));
	}
	if (fmt->pre_flag && fmt->precision > *len)
	{
		preres = (char *)malloc((fmt->precision - *len) + 1);
		ft_memset(preres, '0', (fmt->precision - *len));
		preres[fmt->precision - *len] = '\0';
		res = ft_strjoin(preres, itoares);
		*len = fmt->precision;
		ft_strdel(&preres);
		ft_strdel(&itoares);
	}
	else
		return (itoares);
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

char						*flag_uint(t_format *fmt)
{
	char				*res;
	char				*itoares;
	char				*formatres;
	unsigned long long	va_int;
	int					len;

	va_int = get_nb(fmt);
	len = ft_intlen_base(va_int, 10);
	itoares = handle_uint(fmt, va_int, &len);
	formatres = format_uint(fmt, len);
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, itoares);
	else
		res = ft_strjoin(itoares, formatres);
	ft_strdel(&formatres);
	ft_strdel(&itoares);
	return (res);
}
