/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:18:10 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/06 04:16:21 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_free(char **argv, int argc)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		free(argv[count]);
		count++;
	}
	free(argv);
	return (1);
}

void	lst_free(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*head;

	head = stack_a;
	while (head != NULL)
	{
		tmp_a = head->next;
		free(head);
		head = tmp_a;
	}
	head = stack_b;
	while (head != NULL)
	{
		tmp_b = head->next;
		free(head);
		head = tmp_b;
	}
}

int	printerror(void)
{
	ft_printf("Error\n");
	return (1);
}

int	str_undigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	checklst_error(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
