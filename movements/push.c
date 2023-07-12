/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:20:59 by paescano          #+#    #+#             */
/*   Updated: 2023/07/05 12:20:59 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_b <= 0)
		return ;
	tmp = stacks->stack_b[0];
	ft_memmove(stacks->stack_a + 1, stacks->stack_a,
		sizeof(int) * stacks->size_a);
	stacks->stack_a[0] = tmp;
	stacks->size_a++;
	stacks->size_b--;
	ft_memmove(stacks->stack_b, stacks->stack_b + 1,
		sizeof(int) * stacks->size_b);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 0)
		return ;
	tmp = stacks->stack_a[0];
	ft_memmove(stacks->stack_b + 1, stacks->stack_b,
		sizeof(int) * stacks->size_b);
	stacks->stack_b[0] = tmp;
	stacks->size_b++;
	stacks->size_a--;
	ft_memmove(stacks->stack_a, stacks->stack_a + 1,
		sizeof(int) * stacks->size_a);
	write(1, "pb\n", 3);
}
