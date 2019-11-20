/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 04:06:27 by japarbs           #+#    #+#             */
/*   Updated: 2019/06/22 06:20:31 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Creates a substr from the given string from the given index till given
**	length. Copies all chars from start index till the desired len is reached.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	if (!(substr = ft_strnew(len)))
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}
