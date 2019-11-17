/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:35:34 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/16 17:56:46 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Dispatch table that calls the correct conversion. Uses an input char as an
**	index to call the correct function.
*/

char	*table(int flag, t_format *fmt)
{
	char	*key;
	int		i;

	key = "csp%idDoufFxXb";
	i = -1;
	while (key[++i] != flag)
		if (!key[i])
			return (ft_strnew(0));
	static char	*(*p[])() = {
		['c'] = flag_char,
		['s'] = flag_string,
		['p'] = flag_pointer,
		['%'] = flag_percent,
		['i'] = flag_int,
		['d'] = flag_int,
		['D'] = flag_uint,
		['o'] = flag_oct,
		['u'] = flag_uint,
		['f'] = flag_float,
		['F'] = flag_float,
		['x'] = flag_hex,
		['X'] = flag_hex,
		['b'] = flag_binary,
	};

	return (p[flag](fmt));
}
