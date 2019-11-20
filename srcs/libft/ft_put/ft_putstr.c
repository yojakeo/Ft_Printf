/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:23:12 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/19 20:57:19 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putstr(char *str)
{
	int		len;

	if (!str)
	{
		ft_putstr("null\n");
		return ;
	}
	len = ft_strlen(str);
	write(1, str, len);
}
