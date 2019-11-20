/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:06:26 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:24 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Allocates the given size and bzero's the new block of memory.
*/

void	*ft_memalloc(size_t size)
{
	void	*nmem;

	if (!(nmem = malloc(size)))
		return (NULL);
	ft_bzero(nmem, size);
	return (nmem);
}
