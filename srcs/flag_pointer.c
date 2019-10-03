/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:36:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/30 19:37:14 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*flag_pointer(t_format *format)
{
	char	*res;
	char	*tmp;
	unsigned long long va_ptr;

	va_ptr = va_arg(format->valst, unsigned long long);
	if (!(res = ft_itoa_base(va_ptr, 16)) || \
		!(tmp = ft_strjoin("0x", res)))
		return (NULL);
	ft_strdel(&res);
	res = tmp;
	return (res);
}
