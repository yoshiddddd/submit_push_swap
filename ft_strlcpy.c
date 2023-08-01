/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:56:28 by kyoshida          #+#    #+#             */
/*   Updated: 2023/07/22 12:22:17 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ans;

	i = 0;
	ans = 0;
	ans = ft_strlen(src);
	if (!dest || !src || size == 0)
		return (ft_strlen(src));
	while (size - 1 > 0 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (ans);
}
