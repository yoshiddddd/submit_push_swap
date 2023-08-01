/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:36:25 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/01 14:23:42 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issort(t_list **stack_a)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	i = 1;
	while (tmp != NULL)
	{
		if (i != tmp->pressnum)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
