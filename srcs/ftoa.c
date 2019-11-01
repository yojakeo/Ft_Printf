/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:39 by japarbs           #+#    #+#             */
/*   Updated: 2019/10/30 23:51:52 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Takes a number and brings it up to a given power.
*/

long	ft_pow(int a, int b)
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

int		count_zeros(double fnum, int precision)
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

static char	*make_float(char *ires, long long fnum, int precision, int zeros)
{
	char	*res;
	char	*fres;

	fres = (fnum > 0) ? \
	ft_itoa_base((unsigned long long)fnum, 10) : \
	ft_itoa_base((unsigned long long)-fnum, 10);
	(void)precision;
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
**	Float & Double Float to ASCII conversion.
*/

char	*ft_ftoa(long double input, int precision)
{
	char		*res;
	char		*ires;
	long long	inum;
	long double	fnum;
	int			zeros;

	inum = (long long)input;
	ires = ft_itoa(inum);
	if (precision)
	{
		fnum = (input - (long double)inum);
		zeros = count_zeros(fnum, precision);
		fnum *= ft_pow(10, precision);
		res = make_float(ires, fnum, precision, zeros);
	}
	else
		res = ft_strdup(ires);
	ft_strdel(&ires);
	return (res);
}
