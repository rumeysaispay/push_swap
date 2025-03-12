/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:29:33 by rispay-s          #+#    #+#             */
/*   Updated: 2025/03/11 12:29:33 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	control_syntax(char *str)
{
	if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

static long	ft_atol(char const *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (sign * res);
}

static int	control_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = flast_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

void	start_stack_a(t_stack **a, char **av, int flag)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (control_syntax(av[i]))
			free_errors(a, av, flag);
		n = ft_atol(av[i]);
		if (n > 2147483647 || n < -2147483648)
			free_errors(a, av, flag);
		if (control_duplicate(*a, (int)n))
			free_errors(a, av, flag);
		if (!(append_node(a, (int)n)))
			free_errors(a, av, flag);
		i++;
	}
	if (flag)
		destroy_av(av);
}
