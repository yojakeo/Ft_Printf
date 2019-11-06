/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:29:22 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/02 13:23:29 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

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
/*
**	Buffering
*/
int				non_varg_format(t_format *format, t_obuf *buff);
int				join_buff(t_obuf *buff, char *input);
#endif

/*

Length	d i	u o x X	f F e E g G a A	c	s	p	n
(none)	int	unsigned int	double	int	char*	void*	int*
hh	signed char	unsigned char					signed char*
h	short int	unsigned short int					short int*
l	long int	unsigned long int		wint_t	wchar_t*		long int*
ll	long long int	unsigned long long int					long long int*
j	intmax_t	uintmax_t					intmax_t*
z	size_t	size_t					size_t*
t	ptrdiff_t	ptrdiff_t					ptrdiff_t*
L			long double				

hh	For integer types, causes printf to expect an int-sized integer argument which was promoted from a char.
h	For integer types, causes printf to expect an int-sized integer argument which was promoted from a short.
l	For integer types, causes printf to expect a long-sized integer argument.
For floating point types, this has no effect.[3]

ll	For integer types, causes printf to expect a long long-sized integer argument.
L	For floating point types, causes printf to expect a long double argument.
z	For integer types, causes printf to expect a size_t-sized integer argument.
j	For integer types, causes printf to expect a intmax_t-sized integer argument.
t	For integer types, causes printf to expect a ptrdiff_t-sized integer argument.
*/
