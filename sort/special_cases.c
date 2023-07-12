/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:44:51 by paescano          #+#    #+#             */
/*   Updated: 2023/07/06 13:44:51 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_two(t_stack *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		ft_swap_a(stacks);
}

void	ft_sort_three(t_stack *stacks)
{
	if (stacks->stack_a[2] != 2)
	{
		if (stacks->stack_a[0] == 2)
			ft_rotate_a(stacks);
		else
			ft_reverse_rotate_a(stacks);
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		ft_swap_a(stacks);
}

void	ft_sort_four(t_stack *stacks)
{
	while (stacks->size_b < 1)
	{
		if (stacks->stack_a[0] == 0)
			ft_push_b(stacks);
		else
			ft_rotate_a(stacks);
	}
	if (stacks->stack_a[2] != 3)
	{
		if (stacks->stack_a[0] == 3)
			ft_rotate_a(stacks);
		else
			ft_reverse_rotate_a(stacks);
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		ft_swap_a(stacks);
	ft_push_a(stacks);
}

void	ft_sort_five(t_stack *stacks)
{
	while (stacks->size_b < 2)
	{
		if (stacks->stack_a[0] == 0 || stacks->stack_a[0] == 1)
			ft_push_b(stacks);
		else
			ft_rotate_a(stacks);
	}
	if (stacks->stack_a[2] != 4)
	{
		if (stacks->stack_a[0] == 4)
			ft_rotate_a(stacks);
		else
			ft_reverse_rotate_a(stacks);
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		ft_swap_a(stacks);
	if (stacks->stack_b[0] < stacks->stack_b[1])
		ft_swap_b(stacks);
	while (stacks->size_b > 0)
		ft_push_a(stacks);
}
