/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:39 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:36:08 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Takes a number and brings it up to a given power.
*/

long		ft_pow(int a, int b)
{
	long	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}

int			count_zeros(double fnum, int precision)
{
	int		count;
	double	fwork;

	count = 0;
	fwork = fnum;
	while (count < precision)
	{
		fwork = fwork * 10;
		if (!(long long)fwork)
			count++;
		else
			break ;
	}
	if (count == precision)
		return (precision - 1);
	return (count);
}

static char	*make_float(char *ires, long double fnum, int precision, int base)
{
	char	*res;
	char	*fres;
	int		zeros;

	zeros = count_zeros(fnum, precision);
	fres = ft_itoa_base((unsigned long long)fnum, base);
	res = ft_strnew(ft_strlen(ires) + ft_strlen(fres) + zeros + 1);
	ft_strcat(res, ires);
	ft_strcat(res, ".");
	if (zeros)
		ft_memset(&res[ft_strlen(res)], '0', zeros);
	ft_strcat(res, fres);
	ft_strdel(&fres);
	return (res);
}

/*
**	Float to ASCII conversion. Converts the int part first. Then if
**	there is a defined precision convert to that point past the decimal point.
**	returning the converted float. If there's no precision it returns only the
**	converted interger part.
*/

char		*ft_ftoa_base(long double input, int precision, int base)
{
	char				*res;
	char				*ires;
	unsigned long long	inum;
	long double			fnum;

	inum = (long long)input;
	ires = ft_itoa_base(inum, base);
	if (precision)
	{
		fnum = (input - (long double)inum);
		fnum *= ft_pow(10, precision);
		res = make_float(ires, fnum, precision, base);
	}
	else
		res = ft_strdup(ires);
	ft_strdel(&ires);
	return (res);
}

/*
**	Float to ASCII conversion without base. Handles sign and
**	calls ft_ftoa_base for the conversion.
*/

char		*ft_ftoa(long double input, int precision)
{
	char	*res;
	char	*tmp;
	int		s;

	if (input < 0)
	{
		s = 1;
		input = -input;
	}
	else
		s = 0;
	if (!(res = ft_ftoa_base(input, precision, 10)))
		return (NULL);
	if (s)
	{
		if (!(tmp = ft_strjoin("-", res)))
			return (NULL);
		ft_strdel(&res);
		res = tmp;
	}
	return (res);
}
