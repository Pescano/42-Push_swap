/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:25:32 by paescano          #+#    #+#             */
/*   Updated: 2023/07/06 12:25:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1)
		return ;
	tmp = stacks->stack_a[0];
	ft_memmove(stacks->stack_a, stacks->stack_a + 1,
		sizeof(int) * (stacks->size_a - 1));
	stacks->stack_a[stacks->size_a - 1] = tmp;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_b[0];
	ft_memmove(stacks->stack_b, stacks->stack_b + 1,
		sizeof(int) * (stacks->size_b - 1));
	stacks->stack_b[stacks->size_b - 1] = tmp;
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1 || stacks->size_b <= 1)
		return ;
	tmp = stacks->stack_a[0];
	ft_memmove(stacks->stack_a, stacks->stack_a + 1,
		sizeof(int) * (stacks->size_a - 1));
	stacks->stack_a[stacks->size_a - 1] = tmp;
	tmp = stacks->stack_b[0];
	ft_memmove(stacks->stack_b, stacks->stack_b + 1,
		sizeof(int) * (stacks->size_b - 1));
	stacks->stack_b[stacks->size_b - 1] = tmp;
	write(1, "rr\n", 3);
}
