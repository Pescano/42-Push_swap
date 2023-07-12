/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:55:22 by paescano          #+#    #+#             */
/*   Updated: 2023/07/07 12:40:08 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_radix_sort_stack_b(t_stack *stacks, int bit_size, int omited_bit)
{
	int	size;

	size = stacks->size_b;
	while (size-- && omited_bit <= bit_size && !ft_checker_is_sorted(stacks))
	{
		if (((stacks->stack_b[0] >> omited_bit) & 1) == 0)
			ft_rotate_b(stacks);
		else
			ft_push_a(stacks);
	}
	if (ft_checker_is_sorted(stacks))
		while (stacks->size_b != 0)
			ft_push_a(stacks);
}

void	ft_radix_sort_stack_a(t_stack *stacks)
{
	int	omited_bit;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stacks->size_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	omited_bit = -1;
	while (++omited_bit <= bit_size)
	{
		size = stacks->size_a;
		while (size-- && !ft_checker_is_sorted(stacks))
		{
			if (((stacks->stack_a[0] >> omited_bit) & 1) == 0)
				ft_push_b(stacks);
			else
				ft_rotate_a(stacks);
		}
		ft_radix_sort_stack_b(stacks, bit_size, omited_bit + 1);
	}
	while (stacks->size_b != 0)
		ft_push_a(stacks);
}
