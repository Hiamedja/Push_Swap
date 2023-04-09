/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:01:52 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/09 16:59:26 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_stack_size(t_stack_a *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		(stack) = (stack)->next;
		i++;
	}
	return (i);
}

void	ft_sort2(t_stack_a *stack)
{
	ft_sa(&stack);
	while (stack)
	{
		stack = stack->next;
	}
}

void	ft_sort3(t_stack_a **stack)
{
	if ((*stack)->count > (*stack)->next->count
		&& (*stack)->count < (*stack)->next->next->count)
		ft_sa(stack);
	else if ((*stack)->count > (*stack)->next->count
		&& (*stack)->next->count > (*stack)->next->next->count)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if ((*stack)->next->count < (*stack)->count
		&& (*stack)->count > (*stack)->next->next->count)
	{
		ft_ra(stack);
	}
	else if ((*stack)->count < (*stack)->next->count
		&& (*stack)->count < (*stack)->next->next->count)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if ((*stack)->count < (*stack)->next->count
		&& (*stack)->count > (*stack)->next->next->count)
		ft_rra(stack);
}

int	find_low_numb(t_stack_a *a)
{
	int	i;

	i = a->count;
	while (a)
	{
		if (a->count < i)
			i = a->count;
		a = a->next;
	}
	return (i);
}

void	ft_sort4_5(t_stack_a **stack_a, t_stack_a **stack_b)
{
	int	i;

	*stack_b = NULL;
	while (ft_stack_size(*stack_a) > 3)
	{
		i = find_low_numb(*stack_a);
		if ((*stack_a)->count == i)
			ft_pb(stack_a, stack_b);
		else
			ft_rra(stack_a);
	}
	ft_sort3(stack_a);
	while (*stack_b)
	{
		ft_pa(stack_a, stack_b);
	}
}

void	ft_finalsort(t_stack_a **stack_b, t_stack_a **stack_a)
{
	int i;
	int size;

	size = ft_stack_size(*stack_b);
	while (size > 0)
	{
		i = size / 2;
		if (i > ft_position(*stack_b, size - 1))
		{
			while ((*stack_b)->index != size - 1)
				ft_rb(stack_b);
			ft_pa(stack_a, stack_b);
		}
		else
		{
			while ((*stack_b)->index != size - 1)
				ft_rrb(stack_b);
			ft_pa(stack_a, stack_b);
		}
		size--;
	}
}

void	ft_sort100(t_stack_a **stack_a, t_stack_a **stack_b, int *tab, int num)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_stack_size(*stack_a);
	while (size_a > 0)
	{
		size_b = ft_stack_size(*stack_b);
		if ((*stack_a)->count <= tab[i])
		{
			ft_pb(stack_a, stack_b);
			if (size_b > 2)
				ft_rb(stack_b);
			size_a--;
			i++;
		}
		else if ((*stack_a)->count > tab[i] && (*stack_a)->index <= i + num)
		{
			ft_pb(stack_a, stack_b);
			size_a--;
			i++;
		}
		else if (size_a > 2)
			ft_ra(stack_a);
	}
}

void	ft_sort(t_stack_a **stack_a, t_stack_a **stack_b, int *tab)
{
	if (ft_stack_size(*stack_a) == 2)
		ft_sort2(*stack_a);
	else if (ft_stack_size(*stack_a) == 3)
		ft_sort3(stack_a);
	else if (ft_stack_size(*stack_a) >= 4 && ft_stack_size(*stack_a) < 10)
		ft_sort4_5(stack_a, stack_b);
	else if (ft_stack_size(*stack_a) >= 10 && ft_stack_size(*stack_a) <= 100)
	{
		ft_sort100(stack_a, stack_b, tab, 6);
		ft_finalsort(stack_b, stack_a);
	}
	else
	{
		ft_sort100(stack_a, stack_b, tab, 25);
		ft_finalsort(stack_b, stack_a);
	}
}
