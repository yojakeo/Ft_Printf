/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:29:28 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:58 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Copies memory if a given size from src to dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	while (n-- > 0)
		*(dstcpy++) = *(srccpy++);
	return (dst);
}
