/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:13:05 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:46 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Finds the length of a string till either NULL, a delimiter is reached or
**	the max amount of chars is reached and returns the size of the string to
**	that point. Also skips delimiters that are at the start.
*/

size_t	ft_strndlen(char const *str, char c, size_t max)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] == c && i < max)
		i++;
	while (str[i] && str[i] != c && i < max)
	{
		i++;
		len++;
	}
	return (len);
}
