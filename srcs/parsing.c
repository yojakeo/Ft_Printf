/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:47:17 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:59:31 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Parses ft_Printf's input stream for variadic inputs and inserts them into
**	the output stream.
*/

static void	find_size(t_format *fmt)
{
	char	*key;
	int		keyi;

	key = "lLhH";
	keyi = -1;
	while (key[++keyi])
		if (key[keyi] == fmt->input[fmt->i])
			break ;
	fmt->varg_size = key[keyi];
	if (fmt->varg_size == 0)
		return ;
	else if (fmt->varg_size == 'l' && fmt->input[fmt->i + 1] == 'l')
	{
		fmt->varg_size = 'L';
		fmt->i += 2;
	}
	else if (fmt->varg_size == 'h' && fmt->input[fmt->i + 1] == 'h')
	{
		fmt->varg_size = 'H';
		fmt->i += 2;
	}
	else
		fmt->i++;
}

static void	handle_star(t_format *fmt, int state)
{
	if (state == 0)
		fmt->width = va_arg(fmt->valst, int);
	else
		fmt->precision = va_arg(fmt->valst, int);
	fmt->i++;
}

/*
**	Grabs the precision and width from the input stream and places them into
**	their proper variables.
*/

static void	precision_width(t_format *fmt)
{
	if (fmt->input[fmt->i] == '*')
		handle_star(fmt, 0);
	else if (ft_isdigit(fmt->input[fmt->i]))
	{
		fmt->width = ft_atoi(&fmt->input[fmt->i]);
		while (ft_isdigit(fmt->input[fmt->i]))
			fmt->i++;
	}
	if (fmt->input[fmt->i] == '.')
	{
		fmt->pre_flag = 1;
		++fmt->i;
		if (fmt->input[fmt->i] == '*')
			handle_star(fmt, 1);
		else if (ft_isdigit(fmt->input[fmt->i]))
		{
			fmt->precision = ft_atoi(&fmt->input[fmt->i]);
			while (fmt->input[fmt->i] && ft_isdigit(fmt->input[fmt->i]))
				++fmt->i;
			if (fmt->precision < 0)
				fmt->precision = 0;
		}
		else
			fmt->precision = 0;
	}
}

/*
**	Grabs the flags from the input stream and flips the value for use in
**	formating the stream.
*/

static void	parse_flags(t_format *fmt)
{
	while (42)
	{
		if (fmt->input[fmt->i] == ' ')
			fmt->space_flag = 1;
		else if (fmt->input[fmt->i] == '+')
			fmt->pos_flag = 1;
		else if (fmt->input[fmt->i] == '-')
			fmt->neg_flag = 1;
		else if (fmt->input[fmt->i] == '#')
			fmt->alt_flag = 1;
		else if (fmt->input[fmt->i] == '0')
			fmt->zero_flag = 1;
		else
			break ;
		++fmt->i;
	}
}

/*
**	Hub of parsing though a varg with consideration for flags, width and
**	precision. Converting it and formating it properly. Then joining it to
**	the buffered data stream.
*/

int			input_parser(t_format *fmt, t_obuf *buff)
{
	if (!fmt->input[fmt->i])
		return (1);
	if (fmt->input[fmt->i] == '%')
		fmt->i++;
	else
		return (-1);
	parse_flags(fmt);
	precision_width(fmt);
	find_size(fmt);
	if ((fmt->input[fmt->i] == 'f' || fmt->input[fmt->i] == 'F') \
		&& fmt->precision == -1)
		fmt->precision = 6;
	else if (fmt->precision == -1)
		fmt->precision = 0;
	if (!fmt->input[fmt->i] || !conversion_check((int)fmt->input[fmt->i]))
		return (-1);
	if (join_buff(buff, table((int)fmt->input[fmt->i], fmt)) == -1)
		return (-1);
	fmt->i++;
	reset_flags(fmt);
	return (1);
}
