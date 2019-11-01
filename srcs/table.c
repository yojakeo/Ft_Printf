/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:35:34 by japarbs           #+#    #+#             */
/*   Updated: 2019/10/31 21:00:36 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Dispatch table that calls the correct conversion. Uses an input char as an
**	index to call the correct function.
*/

char	*table(int flag, t_format *fmt)
{
	static char	*(*p[])() = {
		['c'] = flag_char,
		['s'] = flag_string,
		['p'] = flag_pointer,
		['%'] = flag_percent,
		['i'] = flag_int,
		['d'] = flag_int,
		['o'] = flag_oct,
		['u'] = flag_uint,
		['f'] = flag_float,
		['x'] = flag_hex,
		['X'] = flag_hex,
		['b'] = flag_binary,
	};

	return (p[flag](fmt));
}
