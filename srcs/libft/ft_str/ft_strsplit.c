/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:57:51 by japarbs           #+#    #+#             */
/*   Updated: 2019/09/23 21:06:02 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Takes in a string and a delimiting char and splices it into a **char.
**	counts the sub strings by the given delimiter and allocates an appropriately
**	sized **char to fit all substrs. While the current substr index is less
**	than the total amount of substrs it copies to the **char's current index
**	till it hits a delimit or \0. keeps looping to the next index and returns
**	the **char.
*/

char	**ft_strsplit(char const *s, char c)
{
	char		**splitstrs;
	size_t		sub;
	size_t		index;
	size_t		cpy;

	sub = 0;
	index = 0;
	if (!s || !(splitstrs = (char **)malloc(sizeof(char *) * \
		(ft_findsubstrs(s, c) + 1))))
		return (NULL);
	while (index < (size_t)ft_findsubstrs(s, c))
	{
		cpy = 0;
		if (!(splitstrs[index] = ft_strnew(ft_strsdlen(&s[sub], c))))
			return (NULL);
		while (s[sub] == c)
			sub++;
		while (s[sub] && s[sub] != c)
			splitstrs[index][cpy++] = s[sub++];
		index++;
	}
	splitstrs[index] = NULL;
	return (splitstrs);
}
