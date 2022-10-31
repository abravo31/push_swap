/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:12:17 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 17:48:36 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

t_stack	*stack_new(int val)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->val = val;
	new->index = 1;
	new->pos = -1;
	new->target_pos = -1;
	new->cos_a = -1;
	new->cos_b = -1;
	new->nxt = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!temp)
		return (temp);
	while (temp->nxt)
	{
		temp = temp->nxt;
	}
	return (temp);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = ft_stacklast(*stack);
	temp->nxt = new;
}

t_stack	*ft_fill_stack(int ac, char **av)
{
	int			i;
	long int	val;
	t_stack		*stack_a;

	i = 1;
	val = 0;
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		if (val < (-2147483648) || val > (2147483647))
			ft_error(&stack_a);
		if (i == 1)
			stack_a = stack_new((int)val);
		else
			ft_stack_add_back(&stack_a, stack_new((int)val));
		i++;
	}
	return (stack_a);
}

void	get_index(t_stack *stack_a)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = stack_a;
	while (ptr)
	{
		ptr2 = stack_a;
		while (ptr2)
		{
			if (ptr->val > ptr2->val)
				ptr->index++;
			ptr2 = ptr2->nxt;
		}
		ptr = ptr->nxt;
	}
}
