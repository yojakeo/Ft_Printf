/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:54:10 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:49 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Takes a string and duplicates it to a fresh string. Returning said string.
*/

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
