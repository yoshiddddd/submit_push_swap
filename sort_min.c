/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:08:20 by kyoshida          #+#    #+#             */
/*   Updated: 2023/07/16 17:23:03 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b > c)
	{
		sa_command(stack);
		rra_command(stack);
	}
	else if (a > b && b < c && a > c)
		ra_command(stack);
	else if (a > b && b < c && a < c)
		sa_command(stack);
	else if (a < b && b > c && a > c)
		rra_command(stack);
	else if (a < b && b > c && a < c)
	{
		sa_command(stack);
		ra_command(stack);
	}
}

void	sort_size4(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(stack_a);
	while ((*stack_a)->data != min)
		ra_command(stack_a);
	pb_command(stack_b, stack_a);
	sort_size3(stack_a);
	pa_command(stack_a, stack_b);
}

void	sort_size5(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	max = find_max(stack_a);
	min = find_min(stack_a);
	while (ft_lstsize(stack_a) > 3)
	{
		if ((*stack_a)->data == max || (*stack_a)->data == min)
			pb_command(stack_b, stack_a);
		else
			ra_command(stack_a);
	}
	sort_size3(stack_a);
	if ((*stack_b)->data > (*stack_b)->next->data)
		sb_command(stack_b);
	pa_command(stack_a, stack_b);
	pa_command(stack_a, stack_b);
	ra_command(stack_a);
}
