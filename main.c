/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:42:33 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/06 04:04:45 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_set(t_list **stack_a)
{
	(*stack_a)->data = 0;
	(*stack_a)->pressnum = 0;
	(*stack_a)->next = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = NULL;
	if (stack_a == NULL)
		return (0);
	lst_set(&stack_a);
	if (lstadd_a(&stack_a, argc, argv) == 1 || checklst_error(&stack_a) == 1)
	{
		lst_free(stack_a, stack_b);
		printerror();
		return (0);
	}
	if (issort(&stack_a) == 1)
		return (0);
	ft_sort(&stack_a, &stack_b);
	lst_free(stack_a, stack_b);
	return (0);
}
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }