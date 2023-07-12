/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:41:10 by paescano          #+#    #+#             */
/*   Updated: 2023/07/06 12:41:10 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1)
		return ;
	tmp = stacks->stack_a[stacks->size_a - 1];
	ft_memmove(stacks->stack_a + 1, stacks->stack_a,
		sizeof(int) * (stacks->size_a - 1));
	stacks->stack_a[0] = tmp;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_b[stacks->size_b - 1];
	ft_memmove(stacks->stack_b + 1, stacks->stack_b,
		sizeof(int) * (stacks->size_b - 1));
	stacks->stack_b[0] = tmp;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rr(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1 || stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_a[stacks->size_a - 1];
	ft_memmove(stacks->stack_a + 1, stacks->stack_a,
		sizeof(int) * (stacks->size_a - 1));
	stacks->stack_a[0] = tmp;
	tmp = stacks->stack_b[stacks->size_b - 1];
	ft_memmove(stacks->stack_b + 1, stacks->stack_b,
		sizeof(int) * (stacks->size_b - 1));
	stacks->stack_b[0] = tmp;
	write(1, "rrr\n", 4);
}
