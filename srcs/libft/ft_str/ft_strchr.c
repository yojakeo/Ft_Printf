/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:59:42 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:18 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Finds where the given char is found within the given string.
**	While the index is still within the string it compares chars, if the char
**	is found then a pointer to the char within the string is returned.
**	Otherwise return NULL.
*/

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if ((char)c == str[i])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
