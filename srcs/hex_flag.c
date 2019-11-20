/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:20:39 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:52:38 by japarbs          ###   ########.fr       */
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
**	Handles alternate flag.
**	It applies the flag IF the there's enough space (Either there's enough
**	precision or there's no defined precision). It will then be applied and
**	cleaned up before being returned.
*/

static char					*handle_alt(t_format *fmt, char *input, int *len, \
							int fmt_flag)
{
	char		*res;
	static int	hagate;

	res = NULL;
	if (!(fmt->zero_flag && !fmt_flag))
	{
		if (!hagate && fmt->alt_flag)
		{
			if (fmt->precision < *len)
				fmt->precision = *len;
			fmt->precision += 2;
			res = ft_strjoin("0x", input);
			hagate = 1;
		}
	}
	if (fmt->precision > *len)
		*len = fmt->precision;
	if (res)
		ft_strdel(&input);
	else
		res = input;
	if (fmt_flag)
		hagate = 0;
	return (res);
}

/*
**	Does the math to find the size of the string to allocate.
**	Ensures that width is as wide or wider than the len of the number.
**	Checks for needed additional space for pos and space flags.
**	Creates the padding string with the proper set of chars with NULL.
*/

static char					*format_hex(t_format *fmt, int *len)
{
	char *res;

	fmt->width = (fmt->width < *len) ? *len : fmt->width;
	fmt->precision = *len;
	if (fmt->zero_flag && !fmt->pre_flag)
		fmt->precision = fmt->width;
	if (fmt->alt_flag && fmt->zero_flag)
		fmt->width -= 2;
	if ((fmt->width - *len) >= 1)
		res = (char *)malloc(fmt->width - *len);
	else
		return (handle_alt(fmt, ft_strnew(0), len, 1));
	if (res && fmt->zero_flag)
		ft_memset(res, '0', (fmt->width - *len) + 1);
	else if (res)
		ft_memset(res, ' ', (fmt->width - *len) + 1);
	if (res)
		res[fmt->width - *len] = '\0';
	return (handle_alt(fmt, res, len, 1));
}

/*
**	Creates the number string and takes in precision to correctly size it.
*/

static char					*handle_hex(t_format *fmt, \
							unsigned long long va_int, int *len)
{
	char	*res;
	char	*itoares;
	char	*preres;

	if ((fmt->neg_flag || fmt->pre_flag) && fmt->zero_flag)
		fmt->zero_flag = 0;
	itoares = ft_itoa_base(va_int, 16);
	if (fmt->pre_flag && fmt->precision == 0)
	{
		*len = 0;
		return (ft_strnew(0));
	}
	if (fmt->pre_flag && fmt->precision > *len)
	{
		preres = (char *)malloc((fmt->precision - *len) + 1);
		ft_memset(preres, '0', (fmt->precision - *len));
		preres[fmt->precision - *len] = '\0';
		res = ft_strjoin(preres, itoares);
		ft_strdel(&preres);
		ft_strdel(&itoares);
	}
	else
		return (handle_alt(fmt, itoares, len, 0));
	return (handle_alt(fmt, res, len, 0));
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

char						*flag_hex(t_format *fmt)
{
	char				*res;
	char				*itoares;
	char				*formatres;
	unsigned long long	va_int;
	int					len;

	va_int = get_nb(fmt);
	len = ft_intlen_base(va_int, 16);
	if (fmt->alt_flag && va_int == 0)
		fmt->alt_flag = 0;
	itoares = handle_hex(fmt, va_int, &len);
	if (!fmt->pre_flag && !len)
		len = ft_intlen_base(va_int, 16);
	formatres = format_hex(fmt, &len);
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, itoares);
	else
		res = ft_strjoin(itoares, formatres);
	if (fmt->input[fmt->i] == 'X')
		ft_strtoupper(res);
	ft_strdel(&formatres);
	ft_strdel(&itoares);
	return (res);
}
