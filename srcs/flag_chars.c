/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:37:40 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/30 19:40:27 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*flag_char(t_format *format)
{
	char	c;
	char	*res;

	c = (char)va_arg(format->valst, int);
	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = c;
	return (res);	
}

char	*flag_string(t_format *format)
{
	char	*res;
	char	*str;

	str = va_arg(format->valst, char *);
	if (!str)
		str = "(null)";
	if (!(res = ft_strdup(str)))
		return (NULL);
	return (res);
}

char	*flag_percent(t_format *format)
{
	char	*res;
	(void)format->valst;
	res = ft_strdup("%");
	return (res);
}
