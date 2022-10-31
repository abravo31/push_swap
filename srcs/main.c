/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:40:54 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 20:58:58 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_stack_size(long int ac)
{
	long int	i;

	i = 1;
	while (i < (ac - 1))
		i++;
	return ((int)i);
}

int	is_sorted(t_stack *stack)
{
	while (stack->nxt)
	{
		if (stack->val > stack->nxt->val)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}		

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(*stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		sort_tiny(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b, stack_size);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!check_stack(av))
		ft_error(NULL);
	stack_a = ft_fill_stack(ac, av);
	stack_b = NULL;
	stack_size = get_stack_size(ac);
	get_index(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
