/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:53:08 by paescano          #+#    #+#             */
/*   Updated: 2023/07/06 18:52:17 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_num_words(char const *s, char c)
{
	int	nwords;

	nwords = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		nwords++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (nwords);
}

int	ft_length_word(char const *s, char c)
{
	int	length;

	length = 0;
	while (*s && *s != c)
	{
		s++;
		length++;
	}
	return (length);
}

char	*ft_strndup(const char *s, int x)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (x + 1));
	i = 0;
	while (i < x)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		nwords;
	int		lwords;
	int		i;

	nwords = ft_num_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (*s && *s == c)
			s++;
		lwords = ft_length_word(s, c);
		strings[i] = ft_strndup(s, lwords);
		if (!strings[i])
			return (NULL);
		s += lwords;
		i++;
	}
	strings[nwords] = 0;
	return (strings);
}
