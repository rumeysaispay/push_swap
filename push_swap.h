/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:29:49 by rispay-s          #+#    #+#             */
/*   Updated: 2025/03/11 12:29:49 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "ft_printf/ft_printf.h"

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775807
# endif

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

int		stack_len(t_stack *stack);
t_stack	*flast_node(t_stack *stack);
t_stack	*fmax_node(t_stack *stack);
t_stack	*fmin_node(t_stack *stack);

char	**ft_split(char const *s, char c);

void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);

void	init_nodes_b(t_stack *a, t_stack *b);

t_stack	*cheapest_node(t_stack *stack);
int		stack_sorted(t_stack *a);
void	sort_three(t_stack **stack);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	destroy_av(char **av);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a, char **av, int flag);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

void	sort_stacks(t_stack **a, t_stack **b);

void	start_stack_a(t_stack **a, char **av, int flag);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	*ft_calloc(size_t count, size_t size);

#endif
