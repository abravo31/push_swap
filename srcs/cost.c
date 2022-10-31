/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:49:54 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 21:30:17 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_stack_cos(int pos, int stack_size)
{
	int	cos;

	if (pos > (stack_size / 2))
		cos = ((stack_size - pos + 1) * -1);
	else
		cos = pos;
	return (cos);
}

void	fill_costs(t_stack **b, int a_size, int b_size)
{
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->cos_a = get_stack_cos(tmp_b->target_pos, a_size);
		tmp_b->cos_b = get_stack_cos(tmp_b->pos, b_size);
		tmp_b = tmp_b->nxt;
	}
}

int	get_total_cost(t_stack *b)
{
	int	total_cos;

	if ((b->cos_a < 0 && b->cos_b < 0) || (b->cos_a > 0 && b->cos_b > 0))
	{
		if (nb_abs(b->cos_a) > nb_abs(b->cos_b))
			total_cos = nb_abs(b->cos_a);
		else
			total_cos = nb_abs(b->cos_b);
	}
	else
		total_cos = nb_abs(b->cos_a - b->cos_b);
	return (total_cos);
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		cheapest;
	int		total_cos;
	int		cos_a;
	int		cos_b;

	tmp_b = *stack_b;
	cheapest = 2147483647;
	while (tmp_b)
	{
		total_cos = get_total_cost(tmp_b);
		if (total_cos < cheapest)
		{
			cheapest = total_cos;
			cos_a = tmp_b->cos_a;
			cos_b = tmp_b->cos_b;
		}
		tmp_b = tmp_b->nxt;
	}
	rotate_and_push(stack_a, stack_b, cos_a, cos_b);
}
