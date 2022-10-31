/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:33:43 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 21:02:26 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_stack_a_to_b(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed <= stack_size / 2)
	{
		if ((*stack_a)->index <= (stack_size / 2))
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

static int	get_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack->nxt)
	{
		stack = stack->nxt;
		size++;
	}
	return (size);
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	get_position(stack);
	lowest_index = tmp->index;
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->nxt;
	}
	return (lowest_pos);
}

static void	sort_stack_a(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos <= stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	a_size;
	int	b_size;	

	push_stack_a_to_b(stack_a, stack_b, size);
	sort_tiny(stack_a);
	while (*stack_b)
	{
		fill_target_positions(stack_a, stack_b);
		a_size = get_size(*stack_a);
		b_size = get_size(*stack_b);
		fill_costs(stack_b, a_size, b_size);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack_a(stack_a);
}
