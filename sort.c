/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:23:50 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/01 14:17:48 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) == 1)
		return ;
	else if (ft_lstsize(stack_a) == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa_command(stack_a);
	}
	else if (ft_lstsize(stack_a) == 3)
		sort_size3(stack_a);
	else if (ft_lstsize(stack_a) == 4)
		sort_size4(stack_a, stack_b);
	else if (ft_lstsize(stack_a) == 5)
		sort_size5(stack_a, stack_b);
	else if (ft_lstsize(stack_a) < 120)
		big_sort(stack_a, stack_b, 18);
	else
		big_sort(stack_a, stack_b, 50);
}
