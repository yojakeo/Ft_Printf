/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:52:53 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:20 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putendl(char const *s)
{
	if (!s)
	{
		ft_putstr("null\n");
		return ;
	}
	ft_putstr((char *)s);
	ft_putchar('\n');
}
