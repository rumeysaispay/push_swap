/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:30:16 by rispay-s          #+#    #+#             */
/*   Updated: 2025/03/11 12:30:16 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prep_for_push(t_stack **stack, t_stack *dest, char c)
{
	while (*stack != dest)
	{
		if (c == 'a')
		{
			if (dest->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (c == 'b')
		{
			if (dest->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = cheapest_node(*a);
	if (c_node->above_median && c_node->target_node->above_median)
		rotate_both(a, b, c_node);
	else if (!(c_node->above_median)
		&& !(c_node->target_node->above_median))
		rev_rotate_both(a, b, c_node);
	prep_for_push(a, c_node, 'a');
	prep_for_push(b, c_node->target_node, 'b');
	pb(b, a);
}

static void	min_on_top(t_stack **a)
{
	while ((fmin_node(*a))->nbr != (*a)->nbr)
	{
		if ((fmin_node(*a))->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len-- > 3)
	{
		pb(b, a);
	}
	if (!(stack_sorted(*a)) && (a_len-- > 3))
	{
		pb(b, a);
	}
	while (!(stack_sorted(*a)) && a_len-- > 3)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
