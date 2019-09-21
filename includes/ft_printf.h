/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:29:22 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/20 15:31:58 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libftplus/libft.h"

/*
**	Structures
*/
typedef	struct	s_format
{
	const char	*input;
	char		*farr;
	size_t		i;
	t_va		va;
}				t_format;

typedef struct	s_va
{
	va_list		valst;
	int			i;
	int			count;
}				t_va;

typedef struct	s_obuf
{
	char		*stream;
	size_t		len;
}				t_obuf;

/*
**	Main function
*/
void			ft_printf(const char * restrict format, ...);
/*
**	Parsing
*/
int				input_parser(t_format *format);
/*
**	Dispatch Functions
*/
char			*table(int index, t_format *format, t_obuf *buff);

char			*flag_char(t_format *format, t_obuf *buff);
char			*flag_string(t_format *format, t_obuf *buff);
char			*flag_pointer(t_format *format, t_obuf *buff);
char			*flag_percent(t_format *format, t_obuf *buff);
char			*flag_int(t_format *format, t_obuf *buff);
char			*flag_oct(t_format *format, t_obuf *buff);
char			*flag_uint(t_format *format, t_obuf *buff);
char			*flag_float(t_format *format, t_obuf *buff);
char			*flag_hex(t_format *format, t_obuf *buff);
char			*flag_binary(t_format *format, t_obuf *buff);
/*
**	Flagging
*/
/*
**	Buffering
*/
int				non_varg_format(t_format format, t_obuf buff);
int				join_buff(t_format *format, t_obuf *buff, char *input);
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
