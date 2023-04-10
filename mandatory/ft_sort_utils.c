/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:19:20 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 15:19:53 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
