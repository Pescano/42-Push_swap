/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:59:41 by paescano          #+#    #+#             */
/*   Updated: 2023/06/26 16:29:56 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	l;

	l = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * l);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s, l);
	return (str);
}
