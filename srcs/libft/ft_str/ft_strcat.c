/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:30:18 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:51 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Concatenates two strings together. While it's in src it copies to the dst
**	and after NULL is reached in src it NULLs the end and returns the dst.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	j = -1;
	while (s2[++j])
		s1[i++] = s2[j];
	s1[i] = '\0';
	return (s1);
}
