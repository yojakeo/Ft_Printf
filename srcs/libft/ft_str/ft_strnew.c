/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:47:13 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:45 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Creates a new string of the given size +1 for NULL termination, then
**	bzeros the string to assure there's no garbage in the memory.
*/

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(newstr, size + 1);
	return (newstr);
}
