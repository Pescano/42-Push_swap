/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:12:16 by paescano          #+#    #+#             */
/*   Updated: 2023/07/08 13:18:18 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit_with_free(t_stack *stacks)
{
	if (stacks)
	{
		free(stacks->stack_a);
		free(stacks->stack_b);
		free(stacks);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_exit_without_errors(t_stack *stacks)
{
	if (stacks)
	{
		free(stacks->stack_a);
		free(stacks->stack_b);
		free(stacks);
	}
	exit(0);
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
