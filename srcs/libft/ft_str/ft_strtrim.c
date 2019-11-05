/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:30:58 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:40 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Trims the string of white space at the start and end of the string.
**	Finds the index of the first and last alphanumeric char and copies
**	the str between those indexes. Returning a fresh string.
*/

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		len;

	start = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	i = len;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	return (ft_strcut(s, start, i));
}
