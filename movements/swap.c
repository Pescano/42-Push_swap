/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:29:03 by paescano          #+#    #+#             */
/*   Updated: 2023/07/05 11:29:03 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1)
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1 || stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	write(1, "ss\n", 3);
}
