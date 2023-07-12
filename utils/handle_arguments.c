/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:02:56 by paescano          #+#    #+#             */
/*   Updated: 2023/06/22 20:02:56 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_join_argv(int argc, char **argv)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	return (tmp);
}

int	ft_get_stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (--argc)
	{
		if (ft_num_words(argv[i + 1], ' '))
			size += ft_num_words(argv[i + 1], ' ');
		else
			size++;
		i++;
	}
	return (size);
}

void	ft_init_stacks(int argc, char **argv, t_stack *stacks)
{
	stacks->size_a = ft_get_stack_size(argc, argv);
	stacks->size_b = 0;
	stacks->stack_a = malloc(stacks->size_a * sizeof(stacks->stack_a));
	if (!stacks->stack_a)
		ft_exit_with_free(stacks);
	stacks->stack_b = malloc(stacks->size_a * sizeof(stacks->stack_b));
	if (!stacks->stack_b)
		ft_exit_with_free(stacks);
}

void	ft_parse_numbers(t_stack *stacks, char *joined_argv)
{
	int		i;
	int		j;
	char	**splitted;

	i = 0;
	j = 0;
	splitted = ft_split(joined_argv, ' ');
	while (splitted[i] != NULL)
	{
		stacks->stack_a[j++] = ft_atoi(splitted[i++], stacks);
		free(splitted[i - 1]);
	}
	free(joined_argv);
	free(splitted);
}

void	ft_parse_number_to_index(t_stack *stacks)
{
	int		i;
	int		j;
	int		index;
	int		*index_stack;

	index_stack = malloc(stacks->size_a * sizeof(index_stack));
	if (!index_stack)
		ft_exit_with_free(stacks);
	i = -1;
	while (++i < stacks->size_a)
	{
		index = 0;
		j = -1;
		while (++j < stacks->size_a)
			if (stacks->stack_a[i] > stacks->stack_a[j])
				index++;
		index_stack[i] = index;
	}
	i = stacks->size_a;
	while (i--)
		stacks->stack_a[i] = index_stack[i];
	free(index_stack);
}
