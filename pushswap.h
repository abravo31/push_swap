/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:17:59 by abravo            #+#    #+#             */
/*   Updated: 2022/10/23 21:30:57 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	int				index;
	int				pos;
	int				target_pos;
	int				cos_a;
	int				cos_b;
	struct s_stack	*nxt;
}	t_stack;

/* Stack */
int			check_stack(char **av);
int			get_stack_size(long int ac);

t_stack		*ft_fill_stack(int ac, char **av);
t_stack		*stack_new(int val);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
void		get_index(t_stack *stack_a);

/* Positions and Costs */
void		get_position(t_stack **stack);
void		fill_target_positions(t_stack **stack_a, t_stack **stack_b);
void		fill_costs(t_stack **stack_b, int a_size, int b_size);
int			get_total_cost(t_stack *b);

/* Sort */
int			is_sorted(t_stack *stack);
void		sort_tiny(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b, int size);
void		rotate_and_push(t_stack **a, t_stack **b, int cos_a, int cos_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Move */
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack *stack_a);
void		do_sb(t_stack *stack_b);
void		do_ss(t_stack *stack_a, t_stack *stack_b);

/* Tools */
long int	ft_atoi(const char *s);
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		free_stack(t_stack **stack);
void		ft_error(t_stack **stack);

#endif
