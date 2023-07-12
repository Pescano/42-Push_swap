/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:51:30 by paescano          #+#    #+#             */
/*   Updated: 2023/07/07 12:33:53 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

//cheker functions
/**
 * @brief check if the params are numbers with spaces at the beginning and end 
 * also check if there are two spaces together. If there is a '-' it is allowed.
 * If any of these conditions is not met, call ft_exit_without_errors.
 * 
 * @param argc number of params
 * @param argv params
 */
void		ft_checker_params(int argc, char **argv);
/**
 * @brief check if a list of numbers is duplicated. If it is duplicated, call
 * ft_exit_without_errors().
 * 
 * @param stacks struct with the stacks
 */
void		ft_checker_is_duplicated(t_stack *stack);
/**
 * @brief check if a number is an integer. If it is not an integer, call
 * ft_exit_without_errors().
 * 
 * @param number number to be checked
 * @return int 1 if it is an integer, 0 if it is not
 */
int			ft_checker_is_integer(long long number);
/**
 * @brief check if the stack is sorted. If it is sorted, return 1, if it 
 * is not sorted, return 0.
 * 
 * @param stacks struct with the stacks
 * @return int boolean
 */
int			ft_checker_is_sorted(t_stack *stacks);

//utils functions
/**
 * @brief join the params in a single string separated by spaces
 * 
 * @param argc number of params
 * @param argv params
 * @return char* string with the params joined
 */
char		*ft_join_argv(int argc, char **argv);
/**
 * @brief count the number of words in a string separated by a delimiter
 * 
 * @param s string to be counted
 * @param c character that separates the words
 * @return int number of words
 */
int			ft_num_words(char const *s, char c);

//handle stack functions
/**
 * @brief initialize the stack with the params getting the size of the stack and
 * setting the memory for the stack.
 * 
 * @param argc number of params
 * @param argv params
 * @param stacks stack to be initialized
 */
void		ft_init_stacks(int argc, char **argv, t_stack *stacks);
/**
 * @brief parse the numbers of the string and put them in the stack
 * 
 * @param stacks stack to be filled
 * @param joined_argv argv joined in a string
 */
void		ft_parse_numbers(t_stack *stacks, char *joined_argv);
/**
 * @brief parse the numbers of the stack a to index from 0 to size_a - 1
 * 
 * @param stacks struct with the stacks
 */
void		ft_parse_number_to_index(t_stack *stacks);

//movements functions
/**
 * @brief  Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
 * 
 * @param stacks struct with the stacks
 */
void		ft_swap_a(t_stack *stacks);
/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * 
 * @param stacks struct with the stacks
 */
void		ft_swap_b(t_stack *stacks);
/**
 * @brief Swap the first 2 elements at the top of stack a and b.
 * Do nothing if there is only one or no elements.
 * 
 * @param stacks struct with the stacks
 */
void		ft_swap_ss(t_stack *stacks);
/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty
 * 
 * @param stacks struct with the stacks
 */
void		ft_push_a(t_stack *stacks);
/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty
 * 
 * @param stacks struct with the stacks
 */
void		ft_push_b(t_stack *stacks);
/**
 * @brief  Shift up all elements of stack a by 1. 
 * The first element becomes the last one.
 * 
 * @param stacks struct with the stacks
 */
void		ft_rotate_a(t_stack *stacks);
/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * 
 * @param stacks struct with the stacks
 */
void		ft_rotate_b(t_stack *stacks);
/**
 * @brief rotate_a and rotate_b at the same time.
 * 
 * @param stacks struct with the stacks
 */
void		ft_rotate_rr(t_stack *stacks);
/**
 * @brief Shift down all elements of stack a by 1. 
 * The last element becomes the first one.
 * 
 * @param stacks struct with the stacks
 */
void		ft_reverse_rotate_a(t_stack *stacks);
/**
 * @brief Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * 
 * @param stacks struct with the stacks
 */
void		ft_reverse_rotate_b(t_stack *stacks);
/**
 * @brief reverse_rotate_a and reverse_rotate_b at the same time.
 * 
 * @param stacks struct with the stacks
 */
void		ft_reverse_rotate_rr(t_stack *stacks);

//sort functions
/**
 * @brief sort the stack with 2 numbers
 * 
 * @param stacks struct with the stacks
 */
void		ft_sort_two(t_stack *stacks);
/**
 * @brief sort the stack with 3 numbers
 * 
 * @param stacks struct with the stacks
 */
void		ft_sort_three(t_stack *stacks);
/**
 * @brief sort the stack with 4 numbers
 * 
 * @param stacks struct with the stacks
 */
void		ft_sort_four(t_stack *stacks);
/**
 * @brief sort the stack with 5 numbers
 * 
 * @param stacks struct with the stacks
 */
void		ft_sort_five(t_stack *stacks);
/**
 * @brief sort the stack with more than 5 numbers with the algorithm
 * radix sort using the stack a as the main stack with value 0 and the
 * stack b as the auxiliar stack with value 1. The algorithm will sort
 * the stack a and then push the numbers to the stack b and then push
 * back to the stack a sorted.
 * 
 * @param stacks struct with the stacks
 */
void		ft_radix_sort_stack_a(t_stack *stacks);

//exit functions
/**
 * @brief print "Error\n" and exit with code 1
 */
void		ft_exit(void);
/**
 * @brief print "Error\n", erase the memory of the stack and exit with
 * code 1
 * 
 * @param stack 
 */
void		ft_exit_with_free(t_stack *stack);
/**
 * @brief erase the memory of the stack and exit with code 0
 * 
 * @param stack stack to be erased
 */
void		ft_exit_without_errors(t_stack *stack);

//libft functions
/**
 * @brief turn a string into an integer
 * 
 * @param str string to be converted
 * @return long int integer converted
 */
int			ft_atoi(const char *str, t_stack *stacks);
/**
 * @brief check if a character is a digit
 * 
 * @param c character to be checked
 * @return int 1 if it is a digit, 0 if it is not
 */
int			ft_isdigit(int c);
/**
 * @brief copy memory area from src to dest with n bytes
 * 
 * @param dest destination of the copy
 * @param src source of the copy
 * @param n number of bytes to be copied
 * @return void* pointer to the destination
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap: copying takes place as though the 
 * bytes in src are first copied into a temporary array that does 
 * not overlap src or dest, and the bytes are then copied from the 
 * temporary array to dest.
 * 
 * @param dest destination of the copy
 * @param src soruce of the copy
 * @param n number of bytes to be copied
 * @return void* pointer to the destination
 */
void		*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief divide a string into several strings according to a delimiter
 * 
 * @param s string to be divided
 * @param c character delimiter
 * @return char** strings divided by the delimiter
 */
char		**ft_split(char const *s, char c);
/**
 * @brief find the first occurrence of a character in a string
 * 
 * @param s string to be searched
 * @param c character to be found
 * @return char* first occurrence of the character
 */
char		*ft_strchr(const char *s, int c);
/**
 * @brief duplicate a string
 * 
 * @param str string to be duplicated
 * @return char* string duplicated
 */
char		*ft_strdup(const char *str);
/**
 * @brief join two strings
 * 
 * @param s1 string of the beginning
 * @param s2 string of the end
 * @return char* strings joined
 */
char		*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief return the length of a string
 * 
 * @param str string whose length is to be found 
 * @return int length of the string
 */
int			ft_strlen(const char *str);

#endif