/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:55:54 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:47:03 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Ft_printf is a variadic function. It takes a string, parsed to find
**	varg (Variadic Argument) indicators and inserted into the stream.
**	Returns the amount of chars printed to the command line.
*/

int		ft_printf(const char *input, ...)
{
	t_format	fmt;
	t_obuf		buff;
	int			intres;

	printf_init(&fmt, &buff, input);
	va_start(fmt.valst, input);
	while (fmt.input[fmt.i])
	{
		if ((intres = non_varg_format(&fmt, &buff)) == -1)
			return (-1);
		if ((intres = input_parser(&fmt, &buff)) == -1)
			return (-1);
	}
	handle_nc(&fmt, &buff);
	write(1, buff.stream, buff.len);
	ft_strdel(&buff.stream);
	va_end(fmt.valst);
	return (buff.len);
}

/*
**	Handles NULL char output if there was a NULL char passed though for %c
**	consersion handling.
*/

void	handle_nc(t_format *fmt, t_obuf *buff)
{
	int i;

	if (fmt->nc_flag)
	{
		i = buff->len;
		while (--i >= 0)
			if (buff->stream[i] == -1)
				buff->stream[i] = '\0';
	}
}

/*
**	resets the state of all flags and measurements to assure flags from previous
**	inputs are not used.
*/

void	reset_flags(t_format *fmt)
{
	fmt->varg_size = 0;
	fmt->precision = -1;
	fmt->pre_flag = 0;
	fmt->width = 0;
	fmt->neg_flag = 0;
	fmt->pos_flag = 0;
	fmt->space_flag = 0;
	fmt->zero_flag = 0;
	fmt->alt_flag = 0;
}

/*
**	Init for ft_printf.
*/

void	printf_init(t_format *fmt, t_obuf *buff, const char *input)
{
	fmt->input = input;
	fmt->i = 0;
	reset_flags(fmt);
	buff->stream = ft_strnew(0);
	buff->len = 0;
	fmt->nc_flag = 0;
}
