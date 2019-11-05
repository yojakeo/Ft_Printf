/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 03:57:45 by japarbs           #+#    #+#             */
/*   Updated: 2019/11/01 18:13:59 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstpush(t_list **head, t_list *new)
{
	t_list	*current;

	current = *head;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}
