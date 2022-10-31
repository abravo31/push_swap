/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:49:06 by abravo            #+#    #+#             */
/*   Updated: 2022/10/09 18:41:32 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->nxt == NULL)
		return ;
	tmp = stack->val;
	stack->val = stack->nxt->val;
	stack->nxt->val = tmp;
	tmp = stack->index;
	stack->index = stack->nxt->index;
	stack->nxt->index = tmp;
}

void	do_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
