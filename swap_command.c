/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:00:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/01 14:18:00 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_list **stack)
{
	t_list	*now;
	t_list	*after;

	if (ft_lstsize(stack) < 2 || *stack == NULL)
		return (1);
	now = *stack;
	after = (*stack)->next;
	now->next = after->next;
	after->next = now;
	*stack = after;
	return (0);
}

int	sa_command(t_list **stack_a)
{
	if (ft_swap(stack_a) == 1)
		return (1);
	ft_printf("sa\n");
	return (0);
}

int	sb_command(t_list **stack_b)
{
	if (ft_swap(stack_b) == 1)
		return (1);
	ft_printf("sb\n");
	return (0);
}

int	ss_command(t_list **stack_a, t_list **stack_b)
{
	if (ft_swap(stack_a) == 1 || ft_swap(stack_b) == 1)
		return (1);
	ft_printf("ss\n");
	return (0);
}
