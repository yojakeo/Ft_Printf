/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:54:39 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:51:50 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	get_nb(t_format *fmt)
{
	long double	va_float;

	va_float = 0;
	if (fmt->varg_size == 0)
		va_float = va_arg(fmt->valst, double);
	else if (fmt->varg_size == 'l')
		va_float = va_arg(fmt->valst, double);
	else if (fmt->varg_size == 'L')
		va_float = va_arg(fmt->valst, long double);
	return (va_float);
}

/*
**	Places signs and padding in the proper position with
**	consideration for alignment.
*/

static void			handle_flags(t_format *fmt, \
					char *res, long long va_float)
{
	int	signpos;

	if ((fmt->neg_flag && va_float < 0) || fmt->space_flag || fmt->pos_flag)
		fmt->width++;
	if (!fmt->neg_flag)
		signpos = fmt->width - fmt->precision;
	else
		signpos = 0;
	if ((fmt->pos_flag || fmt->space_flag) || va_float < 0)
	{
		if (va_float < 0)
			res[signpos] = '-';
		else if (fmt->pos_flag && va_float >= 0)
			res[signpos] = '+';
		else if (fmt->space_flag && va_float >= 0)
			res[signpos] = ' ';
	}
}

/*
**	Does the math to find the size of the string to allocate.
**	Ensures that width is as wide or wider than the len of the number.
**	Checks for needed additional space for pos and space flags.
**	Creates the padding string with the proper set of chars with NULL.
*/

static char			*format_float(t_format *fmt, long long va_float, int len)
{
	char *res;

	fmt->width = (fmt->width < len) ? len : fmt->width;
	fmt->precision = len;
	if ((fmt->pos_flag || fmt->space_flag) || va_float < 0)
	{
		++fmt->precision;
		if (fmt->width == len)
			++fmt->width;
	}
	if (fmt->zero_flag && !fmt->pre_flag)
		fmt->precision = fmt->width;
	if ((fmt->neg_flag && va_float < 0) || fmt->space_flag || fmt->pos_flag)
		fmt->width--;
	if ((fmt->width - len) >= 1)
		res = (char *)malloc(fmt->width - len);
	else
		return (ft_strnew(0));
	if (res && fmt->zero_flag && !fmt->pre_flag)
		ft_memset(res, '0', (fmt->width - len) + 1);
	else if (res)
		ft_memset(res, ' ', (fmt->width - len) + 1);
	if (res)
		res[fmt->width - len] = '\0';
	return (res);
}

static char			*handle_float(t_format *fmt, long double va_float)
{
	char	*res;
	char	*ftoares;

	if (fmt->pos_flag && fmt->space_flag)
		fmt->space_flag = 0;
	if (fmt->neg_flag && fmt->zero_flag)
		fmt->zero_flag = 0;
	ftoares = (va_float < 0) ? \
	ft_ftoa(-va_float, fmt->precision) : ft_ftoa(va_float, fmt->precision);
	res = ftoares;
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

char				*flag_float(t_format *fmt)
{
	char		*res;
	char		*floatres;
	char		*formatres;
	long double	va_float;
	int			len;

	va_float = get_nb(fmt);
	len = ft_intlen((long long)va_float) + fmt->precision;
	len += (fmt->precision) ? 1 : 0;
	floatres = handle_float(fmt, va_float);
	if ((fmt->neg_flag && va_float < 0) || fmt->space_flag || fmt->pos_flag)
	{
		res = ft_strjoin("0", floatres);
		ft_strdel(&floatres);
		floatres = res;
	}
	formatres = format_float(fmt, va_float, len);
	res = (!fmt->neg_flag) ? \
	ft_strjoin(formatres, floatres) : ft_strjoin(floatres, formatres);
	ft_strdel(&formatres);
	ft_strdel(&floatres);
	handle_flags(fmt, res, va_float);
	return (res);
}
