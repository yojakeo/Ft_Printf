/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:38:47 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:59 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		if (!(new_lst->content = (void *)malloc(content_size)))
		{
			free(new_lst);
			return (NULL);
		}
		ft_memcpy(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = NULL;
	return (new_lst);
}
