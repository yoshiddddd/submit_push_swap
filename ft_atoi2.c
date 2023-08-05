/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:50 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/06 04:16:30 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_parsenumber(const char *str, int flag)
{
	long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > INT_MAX / 10 && flag == 1)
			return (LONG_MAX);
		else if (num > INT_MAX / 10 && flag == -1)
			return (LONG_MIN);
		else if (num == INT_MAX / 10 && *str - '0' > (INT_MIN % 10) * -1
			&& flag == -1)
			return (LONG_MIN);
		else if (num == INT_MAX / 10 && *str - '0' > INT_MAX % 10
			&& flag == 1)
			return (LONG_MAX);
		num = num * 10 + (*str - '0');
		str++;
	}
	if (flag == -1)
		num *= -1;
	return (num);
}

long	ft_atoi_swap(const char *str)
{
	int		flag;
	long	num;

	num = 0;
	flag = 1;
	if (*str == '-')
	{
		flag *= -1;
		str++;
	}
	num = ft_parsenumber(str, flag);
	return (num);
}
