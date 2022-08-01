/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:03:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/01 19:41:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last_new;

	if (!new)
		return ;
	if (!lst)
		*lst = new;
	else
	{
		last_new = ft_lstlast(new);
		(*last_new).next = *lst;
		*lst = new;
	}
}
