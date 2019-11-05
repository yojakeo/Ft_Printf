/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:13:33 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:45 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Finds a string within a string. Uses two indexes that travel through the
**	haystack together until a char matches the start of the needle. I is left
**	at the start of needle while J confirms it's the desired string.
**	If so then a pointer to the start of the needle within haystack. Else J
**	is re-synced and continues to loop.
**	If there is no needle found within len NULL is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = -1;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[++i] && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (needle[j] && haystack[j + i] == needle[j] &&
				(size_t)(i + j) < len)
				++j;
			if (!needle[j])
				return ((char*)&haystack[i]);
		}
	}
	return (NULL);
}
