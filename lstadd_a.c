/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:17:45 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/01 14:16:40 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_last(char *addstr, t_list **stack, int order)
{
	t_list	*new;
	long	convert_d;

	convert_d = 0;
	if (str_undigit(addstr) == 1)
		return (1);
	convert_d = ft_atoi_swap(addstr);
	if (convert_d > INT_MAX || convert_d < INT_MIN)
		return (1);
	if ((*stack)->data == 0 && (order == 1 || order == 0))
	{
		(*stack)->data = convert_d;
		(*stack)->next = NULL;
	}
	else
	{
		new = ft_lstnew(convert_d);
		if (!new)
			return (1);
		ft_lstadd_back(stack, new);
	}
	return (0);
}

static int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

static int	jud_flag(int flag, int argc, char **argv)
{
	if (flag == 0)
		return (1);
	else
		return (argv_free(argv, argc));
}

static int	jud_argc(int flag, int argc, char **argv, t_list **stack)
{
	if (flag == 1)
		argv_free(argv, argc);
	if (num_press(stack) == 1)
		return (1);
	return (0);
}

int	lstadd_a(t_list **stack, int argc, char **argv)
{
	char	*addstr;
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (1);
		argc = argv_len(argv);
		flag = 1;
		i = 0;
	}
	while (i < argc)
	{
		addstr = argv[i];
		if (new_last(addstr, stack, i) == 1)
			return (jud_flag(flag, argc, argv));
		i++;
	}
	return (jud_argc(flag, argc, argv, stack));
}
