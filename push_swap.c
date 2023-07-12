/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:51:33 by paescano          #+#    #+#             */
/*   Updated: 2023/07/10 18:25:02 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//eliminar cuando se acabe el proyecto es para comprobar que no hay leaks
void	ft_leaks(void)
{
	system("leaks push_swap");
}

void	ft_sort(t_stack *stacks)
{
	if (stacks->size_a == 2)
		ft_sort_two(stacks);
	else if (stacks->size_a == 3)
		ft_sort_three(stacks);
	else if (stacks->size_a == 4)
		ft_sort_four(stacks);
	else if (stacks->size_a == 5)
		ft_sort_five(stacks);
	else
		ft_radix_sort_stack_a(stacks);
	if (ft_checker_is_sorted(stacks))
		ft_exit_without_errors(stacks);
	else
		ft_exit_with_free(stacks);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	//atexit(ft_leaks);
	ft_checker_params(argc, argv);
	stacks = malloc(sizeof * stacks);
	if (!stacks)
		ft_exit();
	ft_init_stacks(argc, argv, stacks);
	ft_parse_numbers(stacks, ft_join_argv(argc, argv));
	ft_checker_is_duplicated(stacks);
	ft_parse_number_to_index(stacks);
	ft_sort(stacks);
	return (0);
}
