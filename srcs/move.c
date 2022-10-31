/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:42:00 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 20:07:58 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int c_a, int c_b)
{	
	while (c_a > 0 && c_b > 0)
	{
		c_b--;
		c_a--;
		do_rr(stack_a, stack_b);
	}
	while (c_a > 0)
	{
		do_ra(stack_a);
		c_a--;
	}
	while (c_b > 0)
	{
		do_rb(stack_b);
		c_b--;
	}
}

void	r_rotate_both(t_stack **stack_a, t_stack **stack_b, int c_a, int c_b)
{
	while (c_a < 0 && c_b < 0)
	{
		c_b++;
		c_a++;
		do_rrr(stack_a, stack_b);
	}
	while (c_a < 0)
	{
		do_rra(stack_a);
		c_a++;
	}
	while (c_b < 0)
	{
		do_rrb(stack_b);
		c_b++;
	}
}

void	rotate_a(t_stack **a, int c_a)
{
	while (c_a < 0)
	{
		do_rra(a);
		(c_a++);
	}
	while (c_a > 0)
	{
		do_ra(a);
		(c_a--);
	}
}

void	rotate_b(t_stack **b, int c_b)
{	
	while (c_b < 0)
	{
		do_rrb(b);
		(c_b++);
	}
	while (c_b > 0)
	{
		do_rb(b);
		(c_b--);
	}
}

void	rotate_and_push(t_stack **a, t_stack **b, int cos_a, int cos_b)
{
	if (cos_b > 0 && cos_a > 0)
		rotate_both(a, b, cos_a, cos_b);
	else if (cos_b < 0 && cos_a < 0)
		r_rotate_both(a, b, cos_a, cos_b);
	else
	{
		rotate_a(a, cos_a);
		rotate_b(b, cos_b);
	}
	do_pa(a, b);
}
