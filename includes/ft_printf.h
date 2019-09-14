/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:29:22 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/18 22:39:06 by japarbs          ###   ########.fr       */
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
	void		*varg;
	enum types	type;
	enum flags	flag;
	enum bases	base;
}				t_va;

typedef struct	s_val
{
	char		*base;
	char		*type;
	char		*flag;
}				t_val;

typedef struct	s_obuf
{
	char		*stream;
	size_t		len;
}				t_obuf;

enum	types
{
	s = (char *)
	c = (char)
	p = (void *) print address
	d = (int)
	i = (int)
	u = (unsigned int)
	f = (float)
	//bonus types
	e = (char *) scientific notation
	g = (double)
}		types;

enum	bases
{
	b = 2;
	o = 8;
	x = 16;
	X = 16;
}		bases;

enum	flags
{
	hh = unsigned char;
	h = short;
	l = long;
	ll = long long;
	L = long double;
}		flags;
/*
**	Main function
*/
void			ft_printf(const char * restrict format, ...);
/*
**	Parsing
*/
int				input_parser(t_format *format);
char			*convert_input(t_format *format, t_obuf *buff);
/*
**	Dispatch Table
*/
int				find_type(t_format format);
int				find_flag_type(t_format format);
/*
**	Flagging
*/
int				flag_check(t_format *format);
/*
**	Buffering
*/
int				non_varg_format(t_format format, t_obuf buff);
int				join_buff(t_format *format, t_obuf *buff, char *input);
char			*obuf_vargs(t_format *format, t_obuf *buff);
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
