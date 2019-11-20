/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:37:40 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:09:08 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Correctly formats the padding of the C and S flags.
*/

static char		*format_char(t_format *fmt, int len)
{
	char *res;

	fmt->width = (fmt->width < len) ? len : fmt->width;
	if ((fmt->width - len) >= 1)
		res = (char *)malloc(fmt->width - len);
	else
		return (ft_strnew(0));
	if (res)
	{
		ft_memset(res, ' ', (fmt->width - len) + 1);
		res[fmt->width - len] = '\0';
	}
	return (res);
}

/*
**	Handles precision of the String flag.
*/

static char		*handle_string(t_format *fmt, char *va_str, int *len)
{
	char	*res;

	if (fmt->pre_flag && fmt->precision < *len)
	{
		res = (char *)malloc(fmt->precision + 1);
		ft_strncpy(res, va_str, fmt->precision);
		res[fmt->precision] = '\0';
		*len = fmt->precision;
	}
	else
		return (ft_strdup(va_str));
	return (res);
}

/*
**	Handles the c flag with padding. Precision is not considered as it
**	is a single character.
**	Finds the correct padding with a len of 1. then joins it in the
**	correct order before freeing and returning to be pushed to buffer.
*/

char			*flag_char(t_format *fmt)
{
	char	*res;
	char	charstr[2];
	char	va_char;
	char	*formatres;

	ft_memset(charstr, 0, 2);
	va_char = va_arg(fmt->valst, int);
	if (!va_char)
	{
		fmt->nc_flag = 1;
		charstr[0] = -1;
	}
	else
		charstr[0] = (char)va_char;
	formatres = format_char(fmt, 1);
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, charstr);
	else
		res = ft_strjoin(charstr, formatres);
	ft_strdel(&formatres);
	return (res);
}

/*
**	Handles the s flag with padding and precision.
**	Takes the string and handles precision. Cutting off the string to the size
**	given. Then creating the correct amount of padding to be joined together
**	before freeing and returning to be joined with the buffer.
*/

char			*flag_string(t_format *fmt)
{
	char	*res;
	char	*va_str;
	char	*formatres;
	char	*stringres;
	int		len;

	va_str = va_arg(fmt->valst, char *);
	if (!va_str)
		va_str = "(null)";
	len = ft_strlen(va_str);
	stringres = handle_string(fmt, va_str, &len);
	formatres = format_char(fmt, len);
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, stringres);
	else
		res = ft_strjoin(stringres, formatres);
	ft_strdel(&formatres);
	ft_strdel(&stringres);
	return (res);
}

/*
**	Handles %%.
*/

char			*flag_percent(t_format *fmt)
{
	char	*res;
	char	*formatres;

	formatres = format_char(fmt, 1);
	if (fmt->neg_flag && fmt->zero_flag)
		fmt->zero_flag = 0;
	if (fmt->zero_flag && formatres)
		ft_memset(formatres, '0', (fmt->width - 1));
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, "%");
	else
		res = ft_strjoin("%", formatres);
	ft_strdel(&formatres);
	return (res);
}
