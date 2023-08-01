/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:19:19 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/01 14:17:41 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*bubble_sort(t_list **stack, int *num)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ft_lstsize(stack))
	{
		j = 0;
		while (j < ft_lstsize(stack) - i - 1)
		{
			if (num[j] > num[j + 1])
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (num);
}

static void	pressnum_in(t_list **stack, int *num)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	while (tmp != NULL)
	{
		i = 0;
		while (i < ft_lstsize(stack))
		{
			if (tmp->data == num[i])
				tmp->pressnum = i + 1;
			i++;
		}
		tmp = tmp->next;
	}
}

int	num_press(t_list **stack)
{
	t_list	*tmp;
	int		*num;
	int		i;

	i = 0;
	num = (int *)malloc(sizeof(int) * ft_lstsize(stack));
	if (num == NULL)
		return (1);
	tmp = *stack;
	while (tmp != NULL)
	{
		num[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	num = bubble_sort(stack, num);
	pressnum_in(stack, num);
	free(num);
	return (0);
}
