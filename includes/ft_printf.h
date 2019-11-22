/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:29:22 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/21 17:21:39 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_ftoa.h"

/*
**	Structures
*/

typedef	struct	s_format
{
	const char	*input;
	size_t		i;
	char		varg_size;
	int			precision;
	char		pre_flag;
	int			width;
	char		nc_flag;
	char		neg_flag;
	char		pos_flag;
	char		space_flag;
	char		zero_flag;
	char		alt_flag;
	va_list		valst;
}				t_format;

typedef struct	s_obuf
{
	char		*stream;
	size_t		len;
}				t_obuf;

/*
**	Init
*/
void			printf_init(t_format *format, t_obuf *buff, const char *input);
/*
**	Main function
*/
int				ft_printf(const char *input, ...);
/*
**	Parsing
*/
int				input_parser(t_format *fmt, t_obuf *buff);
int				conversion_check(int flag);
/*
**	Dispatch Functions
*/
char			*table(int flag, t_format *format);

char			*flag_char(t_format *format);
char			*flag_string(t_format *format);
char			*flag_pointer(t_format *format);
char			*flag_percent(t_format *format);
char			*flag_int(t_format *format);
char			*flag_oct(t_format *format);
char			*flag_uint(t_format *format);
char			*flag_float(t_format *format);
char			*flag_hex(t_format *format);
char			*flag_binary(t_format *format);
/*
**	Flagging
*/
void			reset_flags(t_format *fmt);
/*
**	Floats
*/
char			*ft_ftoa(long double input, int precision);
char			*ft_ftoa_base(long double input, int precision, int base);
/*
**	Buffering
*/
int				non_varg_format(t_format *format, t_obuf *buff);
int				join_buff(t_obuf *buff, char *input);
void			handle_nc(t_format *fmt, t_obuf *buff);
#endif
