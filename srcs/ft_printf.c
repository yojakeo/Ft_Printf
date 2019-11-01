/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:55:54 by japarbs           #+#    #+#             */
/*   Updated: 2019/10/31 20:54:56 by japarbs          ###   ########.fr       */
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
	write(1, buff.stream, buff.len);
	ft_strdel(&buff.stream);
	va_end(fmt.valst);
	return (buff.len);
}

/*
**	resets the state of all flags and measurements to assure flags from previous
**	inputs are not used.
*/

void	reset_flags(t_format *fmt)
{
	fmt->varg_size = 0;
	fmt->precision = -1;
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
}

/*
**	Takes non-varg inputs within the fmt string and pushes them into
**	the buffer to be printed with varg inputs. It also moves the index
**	to the next '%' char to be processed later on by the input_parser function.
*/

int		non_varg_format(t_format *fmt, t_obuf *buff)
{
	char	*res;
	size_t	sublen;

	if (fmt->input[fmt->i] && fmt->input[fmt->i] != '%')
	{
		sublen = ft_strdlen(&fmt->input[fmt->i], '%');
		if (!(res = ft_strsub(fmt->input, fmt->i, sublen))
		|| !join_buff(buff, res))
			return (-1);
		fmt->i += sublen;
	}
	return (1);
}

/*
**	Takes an input and joins that to the buffer. Deleting the input.
**	This function will always receive a allocated string.
*/

int		join_buff(t_obuf *buff, char *input)
{
	char *tmp;

	if (!input || !(tmp = ft_strjoin(buff->stream, input)))
		return (-1);
	ft_strdel(&buff->stream);
	buff->stream = tmp;
	ft_strdel(&input);
	buff->len = ft_strlen(buff->stream);
	return (1);
}
