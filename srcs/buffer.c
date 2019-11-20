/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:37:05 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:47:14 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
