/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:55:54 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/22 11:52:16 by japarbs          ###   ########.fr       */
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
		non_varg_format(format, buff);
		input_parser(format);
		flag_check(format);
		convert_input(format, buff);
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
		if(!(res = ft_strsub(format->input, format->i, len)))
			return (-1);
		if (!join_buff(format, buff, res))
		return (-1);
	}
	format->i += len;
	return (1);
}

/*
**	Takes an input and joins that to the buffer.
*/

int		join_buff(t_format *format, t_obuf *buff, char *input)
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

int		input_parser(t_format *format)
{
	int findres;
	if (findres = (find_type(format)) == -1)
		return (-1);
	else if (findres = 0)
	{
		format->va->varg = va_arg(format->va->valst, char)
		join_buff()
	}
}

typedef void (*fun)(char * thing, int i);

/*
**	When input_parser finds a flag. It will find its type and pass it to
**	Print_flag and print out the flag with its paired variadic value.
*/

int		flag_check(t_format *format)
{	
	format->va->flag = format->farr[0];
	format->va->type = format->farr[1];
	format->va->base = format->farr[2];
	format->va->varg = va_arg(format->va->valst, format->va->type);
}

/*
**	Takes the flag index from Flag_check and converts the variadic value
**	to ASCII and inserts it into the buffer to be printed.
*/

char	*convert_input(t_format *format, t_obuf *buff)
{
	char		*res;

	if (!(res = ft_itoa_base(format->va->varg, format->va->base)))
		return (NULL);
	return (res);
}

/*
**	Takes the buffer and vargs
*/

char	*obuf_vargs(t_format *format, t_obuf *buff)
{
	char *input;

	if (!(join_buff(format, buff, input)))
		return (NULL);

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