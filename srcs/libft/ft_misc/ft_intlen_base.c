/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:05:10 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:56 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Takes an unsigned int and counts the amount of bytes needed to print
**	the integer. Takes a base and applies it to the number to count
**	the amount of places.
*/

size_t	ft_intlen_base(unsigned long long n, int base)
{
	size_t				len;
	unsigned long long	nbr;

	len = 0;
	nbr = n;
	if (base < 2 && base > 16)
		return (0);
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
