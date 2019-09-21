/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:55:54 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/20 17:54:48 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Printf is a variadic function. It takes a string, parsed to find
**	varg (Variadic Argument) indicators and inserted into the stream.
**	Returns the amount of chars printed to the command line.
*/

int		ft_printf(const char *input, ...)
{
	t_format	*format;
	t_obuf		*buff;

	format->input = input;
	va_start(format->va->valst, format->input);
	format->i = 0;
	while (format->input[format->i])
	{
		if (!non_varg_format(format, buff))
			return (-1);
		if (!input_parser(format))
			return (-1);
	}
	write(1, buff->stream, buff->len);
	ft_strdel(&buff->stream);
	va_end(format->va->valst);
	return (buff->len);
}

/*
**	Takes non-varg inputs within the format string and pushes them into
**	the buffer to be printed with varg inputs.
*/

int		non_varg_format(t_format *format, t_obuf *buff)
{
	char *res;
	int len;

	if (format->input[format->i] != '%')
	{
		len = format->i;
		while (format->input[len] != '%')
			++len;
		if(!(res = ft_strsub(format-> input, format->i, len)))
			return (-1);
		if (!join_buff(format, buff, res))
			return (-1);
		format->i += len;
	}
	return (1);
}

/*
**	Takes an input and joins that to the buffer.
*/

int		join_buff(t_obuf *buff, char *input)
{
	char *tmp;

	if (!(tmp = ft_strjoin(buff->stream, input)));
		return (-1);
	buff->len = ft_strlen(buff->stream);
	ft_strdel(buff->stream);
	buff->stream = tmp;
	ft_strdel(&input);
	return (1);
}

/*
**	Parses Printf's input stream for variadic inputs and inserts them into
**	the output stream.
*/

int		input_parser(t_format *format, t_obuf *buff)
{
	int		index;
	char	*key;

	index = 0;
	key = "csp%diouxXfb";

	while (format->input[format->i] != key[index])
		++index
	if !(join_buff(buff, table(index, format, buff)))
		return (-1);
	return (1);
}

/*
Syntax
%[parameter][flags][width][.precision][length]type

• You have to manage the following conversions: csp
• You have to manage the following conversions: diouxX with the following flags: hh,
h, l and ll.
• You have to manage the following conversion: f with the following flags: l and L.
• You must manage %%
• You must manage the flags #0-+ and space
• You must manage the minimum field-width
• You must manage the precision

Bonus
• More detailed conversions management: e and g. Be careful, your L flag must works
with both of them to validate this bonus.
• More detailed flags management: *, $ and ’.
• Non-existing flags management: %b to print in binary, %r to print a string of
non-printable characters, %k to print a date in any ordinary ISO format etc.
• Management of alter tools for colors, fd or other fun stuff like that

printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", filename, str);
*/