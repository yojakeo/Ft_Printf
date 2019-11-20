/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:15:27 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:18 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
**	Sets all chars in the passed string to \0.
*/

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	ft_memset(s, '\0', (size_t)ft_strlen(s));
}
