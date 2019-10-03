/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:39 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/30 19:36:09 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_ftoa(double nbr)
{
	char *res;
	(void)nbr;

	res = ft_strnew(0);
	return (res);
}

char	*flag_float(t_format *format)
{
	char	*res;
	double	va_f;

	va_f = va_arg(format->valst, double);
	if (!(res = ft_ftoa(va_f)))
		return (NULL);
	return (res);
}