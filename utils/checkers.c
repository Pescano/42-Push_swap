/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:06:56 by paescano          #+#    #+#             */
/*   Updated: 2023/07/06 18:56:51 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_checker_is_integer(long long number)
{
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	ft_checker_is_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_checker_is_duplicated(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[i] == stacks->stack_a[j])
				ft_exit_with_free(stacks);
			j++;
		}
		i++;
	}
}

void	ft_checker_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc < 2)
		exit(1);
	while (++i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			ft_exit();
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])
				|| ft_strchr("+- ", argv[i][j]) != NULL))
				ft_exit();
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (argv[i][j + 1] == '\0' || argv[i][j + 1] == ' '))
				ft_exit();
			j++;
		}
	}
}
