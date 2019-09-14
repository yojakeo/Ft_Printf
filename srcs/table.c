/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:35:34 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/16 20:59:15 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Finds the type of data for the convertion.
**	0: char, 1: String, 2: Bases, 3: Ints, 4: Floats, 5: Exit, -1: Invalid.
*/

int		find_type(t_format format)
{
	if (format->input[format->i] == 'c')
		return (0);
	if (format->input[format->i] == 's')
		return (1);
	if (format->input[format->i] == 'b' || format->input[format->i] == 'o' || \
	format->input[format->i] == 'x' || format->input[format->i] == 'X')
		return (2);
	if (format->input[format->i] == 'i' || format->input[format->i] == 'd' || \
	format->input[format->i] == 'u')
		return (3);
	if 	(format->input[format->i] == 'f' || format->input[format->i] == 'g')
		return (4);
	// return (find_flag_type(format));
	return (-1)
}

int		find_flag_type(t_format format)
{
	if (format->input[format->i] == 'l' || 
	(format->input[format->i] == 'l' && format->input[format->i + 1] == 'l'))
		return (3);
	
}