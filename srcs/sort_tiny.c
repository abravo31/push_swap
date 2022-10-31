/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:16:24 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 18:24:42 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_high_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (index < stack->index)
			index = stack->index;
		stack = stack->nxt;
	}
	return (index);
}

void	sort_tiny(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = get_high_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->nxt->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->nxt->index)
		do_sa(*stack);
}
