/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:55:54 by japarbs           #+#    #+#             */
/*   Updated: 2019/10/02 21:41:26 by japarbs          ###   ########.fr       */
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
	t_format	format;
	t_obuf		buff;
	int			loopnum = 0;
	int			intres;

	printf_init(&format, &buff, input);
	va_start(format.valst, input);
	while (format.input[format.i])
	{
		loopnum++;
		printf("\n\nloop: %i\n", loopnum);
		if ((intres = non_varg_format(&format, &buff)) == -1)
		{
			printf("FAIL(NVARG)\n");
			return (-1);
		}
		if ((intres = input_parser(&format, &buff)) == -1)
		{
			printf("FAIL(PARSE)\n");
			return (-1);
		}
		printf("Current Stream: %s", buff.stream);
	}
	printf("\nEnd of program, Printing.\nbuff.len: %zu, strlen: %zu\n", buff.len, ft_strlen(buff.stream));
	write(1, buff.stream, buff.len);
	ft_strdel(&buff.stream);
	va_end(format.valst);
	return (buff.len);
}

void	printf_init(t_format *format, t_obuf *buff, const char *input)
{
	format->input = input;
	format->i = 0;
	format->byte_size = 0;
	buff->stream = ft_strnew(0);
	buff->len = 0;
}

/*
**	Takes non-varg inputs within the format string and pushes them into
**	the buffer to be printed with varg inputs. It also moves the index
**	to the next '%' char to be processed later on by the input_parser function.
*/

int		non_varg_format(t_format *format, t_obuf *buff)
{
	char *res;
	size_t sublen;

	if (format->input[format->i] && format->input[format->i] != '%')
	{
		sublen = ft_strdlen(&format->input[format->i], '%');
		if (!(res = ft_strsub(format->input, format->i, sublen))
		|| !join_buff(buff, res))
			return (-1);
		format->i += sublen;
	}
	return (1);
}

/*
**	Takes an input and joins that to the buffer.
*/

int		join_buff(t_obuf *buff, char *input)
{
	char *tmp;

	// printf("Entering buff, input: ~%s~\n", input);
	if (!input || !(tmp = ft_strjoin(buff->stream, input)))
		return (-1);
	// printf("Join check\n");
	ft_strdel(&buff->stream);
	buff->stream = tmp;
	ft_strdel(&input);
	buff->len = ft_strlen(buff->stream);
	// printf("Len: %zu, Buff: ~%s~\n", buff->len, buff->stream);
	return (1);
}

/*
**	Parses ft_Printf's input stream for variadic inputs and inserts them into
**	the output stream.
*/

void	find_size(t_format *format)
{
	char	*key;
	int		keyi;

	key = "lLhH";
	keyi = -1;
	while (key[++keyi])
		if (key[keyi] == format->input[format->i])
			break ;
	format->byte_size = key[keyi];
	if (format->byte_size == 0)
		return ;
	else if (format->byte_size == 'l' && format->input[format->i] == 'l')
	{
		format->byte_size = 'L';
		format->i += 2;
	}
	else if (format->byte_size == 'h' && format->input[format->i] == 'h')
	{
		format->byte_size = 'H';
		format->i += 2;
	}
}

// void	parse_flags(t_format *format)
// {

// }

int		input_parser(t_format *format, t_obuf *buff)
{
	printf("Enter Parse\n");
	if (!format->input[format->i])
		return (1);
	if (format->input[format->i] == '%')
		format->i++;
	else
		return (-1);
	printf("Enter size finder\n");
	find_size(format);
	// parse_flags(format);
	printf("Enter Table\n");
	if (join_buff(buff, table((int)format->input[format->i], format)) == -1)
		return (-1);
	format->i++;
	printf("Exit Parse\n");
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

ft_printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", filename, str);
*/