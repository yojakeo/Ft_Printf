/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:06:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/05 17:58:13 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Finds the last point where the given char is found within the given string.
**	While the index is still within the string it compares chars and logs the
**	last position of the char and continues until \0. Returning a pointer to
**	the last position of the char in the given string. Otherwise return NULL.
*/

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		last_pos;
	int		ischar;

	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	i = 0;
	last_pos = 0;
	ischar = 0;
	while (str[i])
	{
		if ((char)c == str[i])
		{
			last_pos = i;
			ischar = 1;
		}
		i++;
	}
	if (ischar)
		return ((char *)&str[last_pos]);
	return (NULL);
}
