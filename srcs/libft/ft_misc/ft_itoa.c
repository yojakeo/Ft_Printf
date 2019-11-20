/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:54:23 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:21 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Takes an int type (up to long long) and converts to ASCII. If the
**	number is negitive the result has an '-' it is added to the start.
*/

char	*ft_itoa(long long n)
{
	char	*res;
	char	*tmp;
	int		s;

	if (n < 0)
	{
		s = 1;
		n = -n;
	}
	else
		s = 0;
	if (!(res = ft_itoa_base(n, 10)))
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
