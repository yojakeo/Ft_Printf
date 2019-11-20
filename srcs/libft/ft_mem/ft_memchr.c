/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:40:25 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:24 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Locates the first occurrence of c in the block. Returning a pointer to the
**	index of the delimiter. If no delimiter is found it returns NULL.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char)c) == ((unsigned char *)s)[i])
			return ((void *)s + i);
		++i;
	}
	return (NULL);
}
