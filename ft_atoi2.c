/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:50 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/01 14:16:16 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_parsenumber(const char *str, int flag)
{
	long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
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
