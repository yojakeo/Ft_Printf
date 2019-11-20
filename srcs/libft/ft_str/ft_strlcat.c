/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:03:41 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/05 17:59:22 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Concatenates two strings together while assuring NULL termination from the
**	given size of the dest. If dst is longer than the size given it'll abort
**	and return the product of dstsize and the len of src. Else while it's in
**	src and the index is one less than the dstsize, it copies to the dest and
**	after either NULL is reached in src or i is no longer 1 less than dstsize
**	we NULL the end of dst and return the product of the two strings.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0 || dstsize < dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
