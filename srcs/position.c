/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:58:42 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 23:25:11 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->nxt;
		i++;
	}
}

static int	get_target_position(t_stack **a, int b_idx,
		int targ_idx, int targ_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < targ_idx)
		{
			targ_idx = tmp_a->index;
			targ_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->nxt;
	}
	if (targ_idx != 2147483647)
		return (targ_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < targ_idx)
		{
			targ_idx = tmp_a->index;
			targ_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->nxt;
	}
	return (targ_pos);
}

void	fill_target_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		targ_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	targ_pos = 0;
	while (tmp_b)
	{
		targ_pos = get_target_position(stack_a, tmp_b->index,
				2147483647, targ_pos);
		tmp_b->target_pos = targ_pos;
		tmp_b = tmp_b->nxt;
	}
}
