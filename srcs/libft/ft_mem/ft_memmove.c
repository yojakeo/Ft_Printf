/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 00:44:19 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:57 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Moves memory of a given size from src to dst. This is safer than memcpy as
**	it protects if the dst is less than the size of src. It will switch what end
**	it will copy from to avoid data loss at the start.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (dstcpy > srccpy)
		while (0 < len)
		{
			len--;
			dstcpy[len] = srccpy[len];
		}
	else
		while (len > i)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	return (dst);
}
