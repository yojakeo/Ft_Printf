/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:08:06 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:47 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Creates a string the same size of the given string. Travels through the
**	string and applies a function to each char that's stored in the new string
**	while also passing the function it's index. After the string is mapped the
**	function returns the new mapped string.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		map[i] = (*f)(i, s[i]);
	return (map);
}
