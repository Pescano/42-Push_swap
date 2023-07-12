/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:46:05 by paescano          #+#    #+#             */
/*   Updated: 2023/06/26 17:44:13 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*odest;
	const char	*osrc;
	size_t		i;

	i = 0;
	odest = (char *)dest;
	osrc = (const char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(odest + i) = *(osrc + i);
		i++;
	}
	return (dest);
}
