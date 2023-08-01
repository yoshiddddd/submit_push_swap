/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:21:45 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/01 14:16:21 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstfrontlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
