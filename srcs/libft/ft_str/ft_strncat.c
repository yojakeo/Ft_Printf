/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:33:08 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:47 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Concatenates two strings together up to the given length. while it's in
**	src and the index less then the max length it copies to the dst and
**	after either NULL is reached in src or i is no longer less than max length
**	we NULL the end of dst and return the dst.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j] && j < n)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
