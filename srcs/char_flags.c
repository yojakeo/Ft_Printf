/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:37:40 by japarbs           #+#    #+#             */
/*   Updated: 2019/10/23 16:48:23 by japarbs          ###   ########.fr       */
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

static char		*handle_string(t_format *fmt, char *va_str, int len)
{
	char	*res;

	fmt->precision = (fmt->precision < len) ? len : fmt->precision;
	if (fmt->precision >= 1)
		res = (char *)malloc(fmt->precision + 1); 
	else
		return (ft_strdup(va_str));
	ft_strncpy(res, va_str, fmt->precision);
	return (res);
}

/*
**	Handles the c flag with padding. Precision is not considered as it
**	is a single character.
**	Finds the correct padding with a len of 1. then joins it in the
**	correct order before freeing and returning to be pushed to buffer.
*/

char	*flag_char(t_format *fmt)
{
	char	*res;
	char	va_char;
	char	*formatres;

	va_char = va_arg(fmt->valst, int);
	formatres = format_char(fmt, 1);
	if (!fmt->neg_flag)
		res = ft_strjoin(formatres, &va_char);
	else
		res = ft_strjoin(&va_char, formatres);
	ft_strdel(&formatres);
	return (res);
}

/*
**	Handles the s flag with padding and precision.
**	Takes the string and handles precision. Cutting off the string to the size
**	given. Then creating the correct amount of padding to be joined together
**	before freeing and returning to be joined with the buffer.
*/

char	*flag_string(t_format *fmt)
{
	char	*res;
	char	*va_str;
	char	*formatres;
	char	*stringres;
	int		len;

	va_str = va_arg(fmt->valst, char *);
	len = ft_strlen(va_str);
	stringres = (!va_str) ? "(null)" : handle_string(fmt, va_str, len);
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

char	*flag_percent(t_format *fmt)
{
	char	*res;
	(void)fmt->valst;
	res = ft_strdup("%");
	return (res);
}
