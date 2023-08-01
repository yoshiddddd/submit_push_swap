/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:32:00 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/01 15:42:13 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_middle(t_list **stack, int size, int i)
{
	int		middle;
	t_list	*tmp;

	tmp = *stack;
	middle = 0;
	while (tmp != NULL)
	{
		if (tmp->pressnum - 1 == (size / 2) * (2 * i - 1))
			middle = tmp->data;
		tmp = tmp->next;
	}
	return (middle);
}

static int	get_max_index(t_list **stack_b, int size)
{
	int		count;
	t_list	*tmp;

	tmp = *stack_b;
	count = 1;
	while (size != tmp->pressnum)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static int	push_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int	len;

	while (*stack_b != NULL)
	{
		len = ft_lstsize(stack_b);
		if ((*stack_b)->next != NULL && (*stack_b)->pressnum
			+ 1 == (*stack_b)->next->pressnum)
			sb_command(stack_b);
		if (len == (*stack_b)->pressnum)
			pa_command(stack_a, stack_b);
		else if (get_max_index(stack_b, len) > len / 2)
			rrb_command(stack_b);
		else
			rb_command(stack_b);
	}
	return (0);
}

static void	rotate_b(t_list **stack_a, t_list **stack_b, int mid, int min)
{
	long	data_a;
	long	data_b;

	data_a = LONG_MAX;
	data_b = LONG_MAX;
	if (*stack_a != NULL && *stack_b != NULL)
	{
		data_a = (*stack_a)->data;
		data_b = (*stack_b)->data;
	}
	if (data_a != LONG_MAX && data_b != LONG_MAX && data_b < (long)mid + 5
		&& data_a > (long)min)
		rr_command(stack_a, stack_b);
	else if (data_b < (long)mid + 5)
		rb_command(stack_b);
}

int	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	min;
	int	count;
	int	mid;
	int	i;

	i = 1;
	while (*stack_a != NULL)
	{
		count = 0;
		mid = get_middle(stack_a, size, i);
		min = find_press_min(stack_a, size, i);
		while (count < size && *stack_a != NULL)
		{
			find_min_rotate(stack_a, min);
			pb_command(stack_b, stack_a);
			rotate_b(stack_a, stack_b, mid, min);
			count++;
		}
		i++;
	}
	push_b_to_a(stack_a, stack_b);
	return (0);
}
